//
// Created by grave on 2025-04-21.
//
#include <Magnum/Platform/GlfwApplication.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/SceneGraph/Camera.h>
#include <Magnum/Shaders/PhongGL.h>
#include "../externals/enet6/include/enet6/enet.h"
#include "Serializable/InstanceData.h"
#include "Serializable/Object3D.h"
#include "Serializable/Scene3D.h"
#include "Serializable/ColoredDrawable.h"

using namespace Magnum;
using namespace Math::Literals;

class BulletClient : public Platform::GlfwApplication {
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

    // Add game-specific data and rendering logic here
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
                std::cout << "Received data: " << event.packet->data << std::endl;
                // Process the received packet here (e.g., update game state)
                enet_packet_destroy(event.packet);
                break;
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

BulletClient::BulletClient(const Arguments& arguments) : Platform::GlfwApplication(arguments, NoCreate) {
    initClient();
    // Additional setup for graphics, scene, and camera

    Configuration conf;
    conf.setTitle("Bullet Client")
        .setSize({800, 600});
    GLConfiguration glConf;
    create(conf, glConf);
}

void BulletClient::drawEvent() {
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color | GL::FramebufferClear::Depth);

    const char* message = "Hello World!";
    sendMessageToServer(message);
    updateClient();

    // Draw the scene based on the received data from the server
    // For example, update instance data with positions and transformations
    // _camera->draw(_drawables);
    // Use a shader and draw objects here

    swapBuffers();
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

    // Send a shooting action to the server
    ENetPacket* packet = enet_packet_create("SHOOT", strlen("SHOOT") + 1, ENET_PACKET_FLAG_RELIABLE);
    enet_peer_send(server, 0, packet);

    event.setAccepted();
}

MAGNUM_APPLICATION_MAIN(BulletClient)
