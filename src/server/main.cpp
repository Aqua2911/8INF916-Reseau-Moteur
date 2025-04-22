//
// Created by CBerl139 on 11/04/2025.
//

#include <vector>

#include <iostream>
#include "httplib.h"
#include "json.hpp"

using json = nlohmann::json;

int main() {
    //std::vector<GameServer> gameServers;

    httplib::Client cli("localhost", 5009);

    json payload = {
            { "ip", "127.0.0.1" },
            { "port", 7777 },
            { "capacity", 4 }
    };

    auto res = cli.Post("/register-server", payload.dump(), "application/json");

    if (res && res->status == 200) {
        std::cout << "Server registered!\n";
    } else {
        std::cerr << "Failed to register server\n";
    }

    return 0;
}