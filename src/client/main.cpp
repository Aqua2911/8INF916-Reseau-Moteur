//
// Created by CBerl139 on 21/04/2025.
//

#include <iostream>
#include "httplib.h"
#include "json.hpp"  // nlohmann/json
#include "OnlineClient.h"

using json = nlohmann::json;

int main(int argc, char** argv) {
    std::cout << "[ClientApp] main() entered " << "\n";

    OnlineClient onlineClient = OnlineClient("localhost", 5009);
    onlineClient.login("alice");

    std::unordered_map<std::string, int> statTypes;
    onlineClient.fetchStatTypes(statTypes);

    onlineClient.updateStat("GAMES_WON", 5);

    onlineClient.startMatchmaking();

    std::string sessionID;
    onlineClient.pollSession(sessionID);

    std::vector<std::tuple<int, std::string, int>> skins;
    onlineClient.fetchStore(skins);

    onlineClient.purchaseSkin(1);
}

/*
int main(int argc, char** argv) {
    std::cout << "[ClientApp] main() entered " << "\n";

    if (argc < 2) {
        std::cerr << "Usage: ClientApp <username>\n";
        return 1;
    }
    std::string user = argv[1];
    httplib::Client api("localhost", 5009);

    // 1) Login
    auto res = api.Post("/login", json{{"username", user}}.dump(), "application/json");
    if (!res || res->status != 200) { std::cerr<<"Login failed\n"; return 1; }
    json loginJson = json::parse(res->body);
    std::string token = loginJson["token"];
    std::string uid = loginJson["uid"];
    std::cout<<"Logged in as uid : "<< uid <<"\n";

    httplib::Headers hdrs{{"Authorization","Bearer " + token}};

    // Get available stat types
    res = api.Get("/stats/available");
    if (!res || res->status != 200) { std::cout << "Failed to fetch available stat types\n"; return 1; }

    json statTypes = json::parse(res->body);
    std::cout << "Available stats:\n";
    for (auto& [name, rule] : statTypes.items()) {
        std::cout << "  " << name << " (aggregation rule: " << rule << ")\n";
    }

    // Update a stat
    std::string statName = "GAMES_WON";
    json statPayload = { {"value", 5} };
    auto statRes = api.Post("/stats/" + statName, hdrs, statPayload.dump(), "application/json");
    if (!statRes || statRes->status != 200) { std::cout << "Stat update failed\n"; return 1; }

    res = api.Get("/stats/" + uid);
    std::cout << uid << " stats : " << "\n";
    json playerStats = json::parse(res->body);
    if (!res || res->status != 200) { std::cerr << "Failed to fetch stats\n"; return 1; }

    for (auto& [name, value] : playerStats.items()) {
        std::cout << "  " << name << " = " << value << "\n";
    }
    // 2) Match
    res = api.Post("/match", hdrs, "", "application/json");
    if (!res || res->status != 200) {
        std::cerr << "Failed to start matchmaking: " << res->status << "\n";
        if (res) std::cerr << res->body << "\n";
    }

    std::string sessionUrl;
    while (true) {
        res = api.Get("/session", hdrs);
        if (res && res->status == 200) {
            auto body = nlohmann::json::parse(res->body);
            sessionUrl = body["session"];
            std::cout << "Matched! Session: " << sessionUrl << "\n";
            break;
        }

        std::cout << "Still waiting for match...\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    // 3) Session
    res = api.Get("/session", hdrs);
    std::cout<<"Session: "<<json::parse(res->body)["session"]<<"\n";

    // 4) Fetch store
    res = api.Get("/online", hdrs);
    if (!res || res->status != 200) { std::cerr<<"Store fetch failed\n"; return 1; }
    auto store = json::parse(res->body);
    std::cout<<"Available skins:\n";
    for (auto& s : store) {
        std::cout<<"  ["<<s["id"]<<"] "<<s["name"]<<" - "<<s["price"]<<" coins\n";
    }

    // 5) Prompt purchase
    int choice;
    std::cout<<"Enter skin ID to purchase: ";
    std::cin>>choice;
    res = api.Post("/online/purchase", hdrs,
                   json{{"Id",choice}}.dump(), "application/json");
    if (!res || res->status != 200) {
        std::cerr<<"Purchase failed: "<<res->body<<"\n";
    } else {
        std::cout<<"Purchased! Fetching inventory...\n";
        res = api.Get("/online/inventory", hdrs);
        auto inv = json::parse(res->body);
        std::cout<<"Your inventory: ";
        for (int id : inv) std::cout<<id<<' ';
        std::cout<<"\n";
    }

    return 0;
}
 */