//
// Created by grave on 2025-04-21.
//

#include "BulletApp.h"

using namespace Magnum;
using namespace Math::Literals;

class BulletClient : public BulletApp {
    ENetHost* client;
    ENetPeer* server;

public:
    void initClient();
    void updateClient();
    void shutdownClient();
    void sendMessageToServer(const char* message);

    explicit BulletClient(const Arguments& arguments);

private:
    void drawEvent() override;
    void keyPressEvent(KeyEvent& event) override;
    void pointerPressEvent(PointerEvent& event) override;
    void ReadySerializables(const char* buffer, size_t length);

    void exitEvent(ExitEvent &event) override{
        shutdownClient();
    }

    // Add game-specific data and rendering logic here
    Scene3D _scene;
    //store object Data at the same place
    std::vector<ClientObjectData> _serializables;
    std::vector<ObjectData> _serializables2;
};

void BulletClient::initClient() {
    // Initialize ENet
    if (enet_initialize() != 0) {
        std::cerr << "An error occurred while initializing ENet." << std::endl;
        return;
    }

    ENetAddress address;
    enet_address_set_host(&address, ENET_ADDRESS_TYPE_IPV6, "::1");  // Server's address
    address.port = 12345;  // Server's port

    // Create the client host
    client = enet_host_create(ENET_ADDRESS_TYPE_IPV6, nullptr, 1, 2, 0, 0);  // Create a host for a client
    if (client == nullptr) {
        std::cerr << "An error occurred while trying to create an ENet client host." << std::endl;
        return;
    }

    // Connect to the server
    server = enet_host_connect(client, &address, 2, 0);
    if (server == nullptr) {
        std::cerr << "An error occurred while trying to connect to the server." << std::endl;
        return;
    }

    // Wait for a connection event from the server
    ENetEvent event;
    if (enet_host_service(client, &event, 3000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
        std::cout << "Successfully connected to the server." << std::endl;
    } else {
        std::cerr << "Failed to connect to the server." << std::endl;
    }
}

void BulletClient::updateClient() {
    ENetEvent event;
    while (enet_host_service(client, &event, 0) > 0) {
        switch (event.type) {
            case ENET_EVENT_TYPE_RECEIVE:
            {
                ReadySerializables(reinterpret_cast<const char*>(event.packet->data), event.packet->dataLength);
                enet_packet_destroy(event.packet);
                break;
            }
            case ENET_EVENT_TYPE_DISCONNECT:
                std::cout << "Disconnected from server." << std::endl;
                break;
            default:
                break;
        }
    }
}

void BulletClient::shutdownClient() {
    if (client) {
        enet_peer_disconnect(server, 0);
        enet_host_destroy(client);
    }
    enet_deinitialize();
}

void BulletClient::sendMessageToServer(const char* message) {
    // Create the packet. The size is the length of the message.
    ENetPacket* packet = enet_packet_create(message, strlen(message) + 1, ENET_PACKET_FLAG_RELIABLE);

    // Send the packet to the server
    // `serverPeer` is the peer representing the server the client is connected to
    enet_peer_send(server, 0, packet); // 0 is the channel ID

    // Flush the packet to send immediately
    enet_host_flush(client);
}

BulletClient::BulletClient(const Arguments& arguments) : BulletApp::BulletApp(arguments, NoCreate) {
    initClient();
    // Additional setup for graphics, scene, and camera
    Configuration conf;
    conf.setTitle("Bullet Client")
        .setSize({800, 600});
    GLConfiguration glConf;
    create(conf, glConf);


    /* Camera setup */
    (*(_cameraRig = new Object3D{&_scene}))
        .translate(Vector3::yAxis(3.0f))
        .rotateY(40.0_degf);
    (*(_cameraObject = new Object3D{_cameraRig}))
        .translate(Vector3::zAxis(20.0f))
        .rotateX(-25.0_degf);
    (_camera = new SceneGraph::Camera3D(*_cameraObject))
        ->setAspectRatioPolicy(SceneGraph::AspectRatioPolicy::Extend)
        .setProjectionMatrix(Matrix4::perspectiveProjection(35.0_degf, 1.0f, 0.001f, 100.0f))
        .setViewport(GL::defaultFramebuffer.viewport().size());

    /* Shaders + meshes */
    _shader = Shaders::PhongGL{Shaders::PhongGL::Configuration{}
        .setFlags(Shaders::PhongGL::Flag::VertexColor|
                  Shaders::PhongGL::Flag::InstancedTransformation)};
    _shader.setAmbientColor(0x111111_rgbf)
           .setSpecularColor(0x330000_rgbf)
           .setLightPositions({{10.0f, 15.0f, 5.0f, 0.0f}});

    _box = MeshTools::compile(Primitives::cubeSolid());
    _sphere = MeshTools::compile(Primitives::uvSphereSolid(16, 32));
    _boxInstanceBuffer = GL::Buffer{};
    _sphereInstanceBuffer = GL::Buffer{};
    _box.addVertexBufferInstanced(_boxInstanceBuffer, 1, 0,
        Shaders::PhongGL::TransformationMatrix{},
        Shaders::PhongGL::NormalMatrix{},
        Shaders::PhongGL::Color3{});
    _sphere.addVertexBufferInstanced(_sphereInstanceBuffer, 1, 0,
        Shaders::PhongGL::TransformationMatrix{},
        Shaders::PhongGL::NormalMatrix{},
        Shaders::PhongGL::Color3{});

    GL::Renderer::enable(GL::Renderer::Feature::DepthTest);
    GL::Renderer::enable(GL::Renderer::Feature::FaceCulling);
    GL::Renderer::enable(GL::Renderer::Feature::PolygonOffsetFill);
    GL::Renderer::setPolygonOffset(2.0f, 0.5f);

    _debugDraw = BulletIntegration::DebugDraw{};
    _debugDraw.setMode(BulletIntegration::DebugDraw::Mode::DrawWireframe);
    _bWorld.setGravity({0.0f, -10.0f, 0.0f});
    //_bWorld.setDebugDrawer(&_debugDraw);

    setSwapInterval(1);
    setMinimalLoopPeriod(16.0_msec);
    _timeline.start();
}

void BulletClient::drawEvent() {
    // Clear the screen
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color | GL::FramebufferClear::Depth);

    // Receive updates from server
    updateClient(); // This should update _clientObjects or _serializable

    // Prepare camera
    _camera->draw(_drawables);
    _shader.setProjectionMatrix(_camera->projectionMatrix());
    _shader.setTransformationMatrix(_camera->cameraMatrix());


    if (_drawCubes) {
        // Clear instance buffers
        arrayResize(_boxInstanceData, 0);
        arrayResize(_sphereInstanceData, 0);

        // Assume you have a list of deserialized ObjectData or similar
        for(const auto& data : _serializables) {
            const Matrix4 finalTransform = data._transform * data._primitiveTransform;
            const Matrix3 normalMatrix = finalTransform.normalMatrix();
            const Color3 color = data._color;


            if (data.type == DataType_CameraRig)
            {
                //Debug{} << "CameraRig Transform Matrix:\n" << _cameraRig->transformation();

                _cameraRig->setTransformation(data._transform);
            }
            else if (data.type == DataType_CameraObject)
            {
                _cameraObject->setTransformation(data._transform);
            }
            if(data.type == DataType_Cube || data.type == DataType_Ground )
                arrayAppend(_boxInstanceData, InPlaceInit, finalTransform, normalMatrix, color);
            else if(data.type == DataType_Sphere)
                arrayAppend(_sphereInstanceData, InPlaceInit, finalTransform, normalMatrix, color);
        }
        // Send data to GPU
        _boxInstanceBuffer.setData(_boxInstanceData, GL::BufferUsage::DynamicDraw);
        _box.setInstanceCount(_boxInstanceData.size());
        _shader.draw(_box);

        _sphereInstanceBuffer.setData(_sphereInstanceData, GL::BufferUsage::DynamicDraw);
        _sphere.setInstanceCount(_sphereInstanceData.size());
        _shader.draw(_sphere);
    }

    /*
     Optional: Draw debug lines sent from the server
    if (_drawDebug) {
        GL::Renderer::setDepthFunction(GL::Renderer::DepthFunction::LessOrEqual);
        _debugDraw.setTransformationProjectionMatrix(
            _camera->projectionMatrix() * _camera->cameraMatrix());
        _debugDraw.draw(_clientDebugLines); // if you're receiving those
        GL::Renderer::setDepthFunction(GL::Renderer::DepthFunction::Less);
    }
    */

    // Finalize frame
    swapBuffers();
    _timeline.nextFrame();
    redraw();
}


void BulletClient::keyPressEvent(KeyEvent& event) {
    if (event.key() == Key::W) {
        // Send movement data to the server (e.g., player movement)
        ENetPacket* packet = enet_packet_create("MOVE_FORWARD", strlen("MOVE_FORWARD") + 1, ENET_PACKET_FLAG_RELIABLE);
        enet_peer_send(server, 0, packet);
    }

    event.setAccepted();
}

void BulletClient::pointerPressEvent(PointerEvent& event) {
    if (!event.isPrimary() || !(event.pointer() & Pointer::MouseLeft)) {
        return;
    }

    Vector2 pos = event.position();

    // Create a binary packet: Command (1 byte), x (float), y (float)
    uint8_t command = 1;  // 1 could represent SHOOT command
    float x = pos.x();
    float y = pos.y();

    // Create the packet with a size of 1 byte for command + 2 floats (4 bytes each)
    ENetPacket* packet = enet_packet_create(nullptr, sizeof(command) + sizeof(x) + sizeof(y), ENET_PACKET_FLAG_RELIABLE);
    auto data = reinterpret_cast<uint8_t*>(packet->data);

    // Write data into the packet
    data[0] = command;  // Command byte
    std::memcpy(data + 1, &x, sizeof(x));  // x position as float
    std::memcpy(data + 1 + sizeof(x), &y, sizeof(y));  // y position as float

    enet_peer_send(server, 0, packet);
}

void BulletClient::ReadySerializables(const char* buffer, size_t length) {
    _serializables.clear();
    _serializables.reserve(length);

    size_t offset = 0;
    while (offset < length) {
        try {
            ClientObjectData obj = ObjectData::deserialize(buffer, length, offset);
            _serializables.push_back(obj);
        } catch (const std::exception& e) {
            std::cerr << "Deserialization error: " << e.what() << std::endl;
            break;
        }
    }

}

MAGNUM_APPLICATION_MAIN(BulletClient)
