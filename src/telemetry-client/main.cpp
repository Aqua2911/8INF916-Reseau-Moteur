#include <ixwebsocket/IXWebSocket.h>
#include <iostream>
#include <json.hpp>
#include <thread>
#include <chrono>

using json = nlohmann::json;

int main() {
    ix::WebSocket ws;

    ws.setUrl("ws://localhost:5009/telemetry");

    ws.setOnMessageCallback([](const ix::WebSocketMessagePtr& msg) {
        if (msg->type == ix::WebSocketMessageType::Message) {
            std::cout << "Server says: " << msg->str << std::endl;
        }
    });

    ws.start();

    // Wait for connection
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    for (int i = 0; i < 5; ++i) {
        json data = {
            {"playerId", "alice"},
            {"type", "ping"},
            {"timestamp", std::chrono::system_clock::now().time_since_epoch().count()}
        };

        ws.send(data.dump());
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    ws.stop();
    return 0;
}