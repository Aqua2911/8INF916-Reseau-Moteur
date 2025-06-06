//
// Created by CBerl139 on 11/04/2025.
//

#include <vector>

#include <iostream>
#include "httplib.h"
#include "json.hpp"
#include "../client/OnlineClient.h"

using json = nlohmann::json;

/*
 * This file runs the basic methods that are used by a game server to communicate with the REST API
 */


int main() {
    //std::vector<GameServer> gameServers;

    OnlineClient onlineClient = OnlineClient("localhost", 5000);

    onlineClient.registerServer("127.0.0.1", 7777, 4);

    /*httplib::Client api("localhost", 5009);

    json payload = {
            { "ip", "127.0.0.1" },
            { "port", 7777 },
            { "capacity", 4 }
    };

    auto res = api.Post("/register-server", payload.dump(), "application/json");

    if (res && res->status == 200) {
        std::cout << "Server registered!\n";
    } else {
        std::cerr << "Failed to register server\n";
    }

    return 0;
     */
}