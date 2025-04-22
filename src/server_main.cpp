#include "BulletApp.h"

#ifdef BT_USE_DOUBLE_PRECISION
#error sorry, this example does not support Bullet with double precision enabled
#endif

using namespace Magnum;

using namespace Math::Literals;

//typedef SceneGraph::Object<SceneGraph::MatrixTransformation3D> Object3D;
//typedef SceneGraph::Scene<SceneGraph::MatrixTransformation3D> Scene3D;

class BulletServer: public BulletApp
{
    ENetHost* server;
    ENetPeer* client;

    public:
    void initServer();
    void updateServer();

    void sendMessageToClient(const char *message);

    void sendMessageToClient(const void *data, size_t length);

    void shutdownServer();

    explicit BulletServer(const Arguments& arguments);

    private:
        void drawEvent() override;
        void keyPressEvent(KeyEvent& event) override;
        void pointerPressEvent(PointerEvent& event) override;
        void EmptySerializedFile();

        btDiscreteDynamicsWorld _bWorld{&_bDispatcher, &_bBroadphase, &_bSolver, &_bCollisionConfig};

        Scene3D _scene;
        SceneGraph::DrawableGroup3D _drawables;
        Timeline _timeline;

        btBoxShape _bGroundShape{{4.0f, 0.5f, 4.0f}};
};


void BulletServer::initServer() {
    // Initialisation de ENet
    if (enet_initialize() != 0) {
        std::cerr << "An error occurred while initializing ENet." << std::endl;
        return;
    }

    ENetAddress address;
    enet_address_set_host(&address, ENET_ADDRESS_TYPE_IPV6,"::");  // Adresse de serveur local
    address.port = 12345;  // Choisissez un port libre

    // Création de l'hôte serveur
    server = enet_host_create(ENET_ADDRESS_TYPE_IPV6, &address, 4, 2, 0, 0);
    if (server == nullptr) {
        std::cerr << "An error occurred while trying to create an ENet server host." << std::endl;
        return;
    }
}

void BulletServer::updateServer() {
    ENetEvent event;
    while (enet_host_service(server, &event, 0) > 0) {
        std::cout << "Received ENetEvent of type: ";
        switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
            {
                std::cout << "Client connected";

                // ✅ Save the peer pointer somewhere, e.g., in a member variable
                client = event.peer;

                // Optional: You can assign some custom data to this peer too
                event.peer->data = (void*)"Client 1";
                break;
            }

            case ENET_EVENT_TYPE_RECEIVE:
            {
                // Safely copy the data into a null-terminated string for printing
                std::string receivedMsg(reinterpret_cast<char*>(event.packet->data), event.packet->dataLength);
                std::cout << "Received packet: " << receivedMsg << std::endl;

                // Prepare a response
                const char* message = "Message received!";
                ENetPacket* responsePacket = enet_packet_create(message, strlen(message) + 1, ENET_PACKET_FLAG_RELIABLE);
                enet_peer_send(event.peer, 0, responsePacket);

                // Traiter les données reçues ici...
                enet_packet_destroy(event.packet);
            }

            break;
            case ENET_EVENT_TYPE_DISCONNECT:
                std::cout << "Client disconnected." << std::endl;
            break;
            default:
                break;
        }
    }
}

void BulletServer::sendMessageToClient(const char* message) {
    if (client == nullptr)
        return;

    // Create the packet. The size is the length of the message.
    ENetPacket* packet = enet_packet_create(message, strlen(message) + 1, ENET_PACKET_FLAG_RELIABLE);

    // Send the packet to the server
    // `serverPeer` is the peer representing the server the client is connected to
    enet_peer_send(client, 0, packet); // 0 is the channel ID

    // Flush the packet to send immediately
    enet_host_flush(server);
}

void BulletServer::sendMessageToClient(const void* data, size_t length) {
    if (!client) return;
    ENetPacket* packet = enet_packet_create(data, length, ENET_PACKET_FLAG_RELIABLE);
    enet_peer_send(client, 0, packet);
    enet_host_flush(server);
}

void BulletServer::shutdownServer() {
    if (server) {
        enet_host_destroy(server);
    }
    enet_deinitialize();
}


BulletServer::BulletServer(const Arguments& arguments):
    BulletApp(arguments, NoCreate)
{
    initServer();
    EmptySerializedFile();

    /* Configuration window + GL context */
    const Vector2 dpiScaling = this->dpiScaling({});
    Configuration conf;
    conf.setTitle("Bullet Server")
        .setSize(conf.size(), dpiScaling);
    GLConfiguration glConf;
    glConf.setSampleCount(dpiScaling.max() < 2.0f ? 8 : 2);
    if (!tryCreate(conf, glConf))
        create(conf, glConf.setSampleCount(0));

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

    // Création du sol
    auto* ground = new RigidBody{&_scene, 0.0f, &_bGroundShape, _bWorld};
    new ColoredDrawable{*ground, _boxInstanceData, 0xffffff_rgbf,
        Matrix4::scaling({4.0f, 0.5f, 4.0f}), _drawables};

    // Cubes de la scène
    Deg hue = 42.0_degf;
    for(Int i = 0; i != 5; ++i)
        for(Int j = 0; j != 5; ++j)
            for(Int k = 0; k != 5; ++k) {
                auto* o = new RigidBody{&_scene, 1.0f, &_bBoxShape, _bWorld};
                o->translate({i - 2.0f, j + 4.0f, k - 2.0f});
                o->syncPose();
                new ColoredDrawable{*o, _boxInstanceData,
                    Color3::fromHsv({hue += 137.5_degf, 0.75f, 0.9f}),
                    Matrix4::scaling(Vector3{0.5f}), _drawables};
            }
}

void BulletServer::drawEvent() {
    // Handle ENet server networking events each frame
    updateServer();

    BulletApp::drawEvent();

    /* Step bullet simulation */
    _bWorld.stepSimulation(_timeline.previousFrameDuration(), 5);

    if(_drawCubes) {
        /* Populate instance data with transformations and colors */
        arrayResize(_boxInstanceData, 0);
        arrayResize(_sphereInstanceData, 0);
        _camera->draw(_drawables);
        _shader.setProjectionMatrix(_camera->projectionMatrix());

        /* Upload instance data to the GPU (orphaning the previous buffer
           contents) and draw all cubes in one call, and all spheres (if any)
           in another call */
        _boxInstanceBuffer.setData(_boxInstanceData, GL::BufferUsage::DynamicDraw);
        _box.setInstanceCount(_boxInstanceData.size());
        _shader.draw(_box);

        _sphereInstanceBuffer.setData(_sphereInstanceData, GL::BufferUsage::DynamicDraw);
        _sphere.setInstanceCount(_sphereInstanceData.size());
        _shader.draw(_sphere);
    }

    /*Debug draw. If drawing on top of cubes, avoid flickering by setting
       depth function to <= instead of just <.*/
    if(_drawDebug) {
        if(_drawCubes)
            GL::Renderer::setDepthFunction(GL::Renderer::DepthFunction::LessOrEqual);

        _debugDraw.setTransformationProjectionMatrix(
            _camera->projectionMatrix()*_camera->cameraMatrix());
        _bWorld.debugDrawWorld();

        if(_drawCubes)
            GL::Renderer::setDepthFunction(GL::Renderer::DepthFunction::Less);
    }


    swapBuffers();
    _timeline.nextFrame();

    // Erase the contents of the file before starting a new series of serialization
    //EmptySerializedFile();
    std::vector<char> fullBuffer;
    for (auto iData: _boxInstanceData) {
        auto instBuffer = iData.serialize();
        fullBuffer.insert(fullBuffer.end(), instBuffer.begin(), instBuffer.end());
    }
    sendMessageToClient(fullBuffer.data(), fullBuffer.size());
    redraw();
}


void BulletServer::keyPressEvent(KeyEvent& event) {
    /* Movement */
    if(event.key() == Key::S) {
        _cameraObject->rotateX(5.0_degf);
    } else if(event.key() == Key::W) {
        _cameraObject->rotateX(-5.0_degf);
    } else if(event.key() == Key::A) {
        _cameraRig->rotateY(-5.0_degf);
    } else if(event.key() == Key::D) {
        _cameraRig->rotateY(5.0_degf);
    } else if(event.key() == Key::Q) {
        // Move forward
        _cameraRig->translate(_cameraRig->transformation().backward() * -1);
    } else if(event.key() == Key::E) {
        // Move backward
        _cameraRig->translate(_cameraRig->transformation().backward());
    } else return;

    event.setAccepted();
}

void BulletServer::pointerPressEvent(PointerEvent& event) {/* Shoot an object on click */
    if(!event.isPrimary() ||
       !(event.pointer() & Pointer::MouseLeft))
        return;

    /* First scale the position from being relative to window size to being
       relative to framebuffer size as those two can be different on HiDPI
       systems */
    const Vector2 position = event.position()*Vector2{framebufferSize()}/Vector2{windowSize()};
    const Vector2 clickPoint = Vector2::yScale(-1.0f)*(position/Vector2{framebufferSize()} - Vector2{0.5f})*_camera->projectionSize();
    const Vector3 direction = (_cameraObject->absoluteTransformation().rotationScaling()*Vector3{clickPoint, -1.0f}).normalized();

    auto* object = new RigidBody{
        &_scene,
        5.0f,
        &_bSphereShape,
        _bWorld};
    object->translate(_cameraObject->absoluteTransformation().translation());
    /* Has to be done explicitly after the translate() above, as Magnum ->
       Bullet updates are implicitly done only for kinematic bodies */
    object->syncPose();

    /* Create either a box or a sphere */
    new ColoredDrawable{*object,
        _sphereInstanceData,
        0x220000_rgbf,
        Matrix4::scaling(Vector3{0.25f}), _drawables};

    /* Give it an initial velocity */
    object->rigidBody().setLinearVelocity(btVector3{direction*25.f});

    event.setAccepted();
}

void BulletServer::EmptySerializedFile() {
    std::ofstream out("serialized.txt", std::ios::binary | std::ios::trunc);
    out.close();
}

MAGNUM_APPLICATION_MAIN(BulletServer)
