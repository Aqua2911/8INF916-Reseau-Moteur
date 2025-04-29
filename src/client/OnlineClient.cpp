//
// Created by CBerl139 on 29/04/2025.
//

#include "OnlineClient.h"
#include <iostream>
#include <thread>
#include <chrono>

using json = nlohmann::json;

OnlineClient::OnlineClient(const std::string& host, int port)
        : client(host, port) {}

bool OnlineClient::login(const std::string& username) {
    auto res = client.Post("/login", json{{"username", username}}.dump(), "application/json");
    if (!res || res->status != 200) {
        std::cerr << "Login failed\n";
        return false;
    }

    json loginJson = json::parse(res->body);
    headers = {{"Authorization", "Bearer " + loginJson["token"].get<std::string>()}};
    jwt = loginJson["token"];
    uid = loginJson["uid"];
    std::cout << "Logged in as uid : " << uid << "\n";
    return true;
}

bool OnlineClient::registerServer(std::string ip, int port, int capacity) {
    json payload = {
            { "ip", ip },
            { "port", port },
            { "capacity", capacity }
    };

    auto res = client.Post("/register-server", payload.dump(), "application/json");

    if (res && res->status == 200) {
        std::cout << "Server registered!\n";
    } else {
        std::cerr << "Failed to register server\n";
        return false;
    }

    return true;
}

bool OnlineClient::fetchStatTypes(std::unordered_map<std::string, int>& outStatTypes) {
    auto res = client.Get("/stats/available");
    if (!res || res->status != 200) return false;

    json statTypes = json::parse(res->body);
    outStatTypes.clear();
    for (auto& [name, rule] : statTypes.items()) {
        outStatTypes[name] = rule;
    }
    return true;
}

bool OnlineClient::updateStat(const std::string& name, int value) {
    json payload = {{"value", value}};
    auto res = client.Post("/stats/" + name, headers, payload.dump(), "application/json");
    if (!res || res->status != 200) {
        std::cerr << "Stat update failed\n";
        return false;
    }
    return true;
}

bool OnlineClient::fetchStats(std::unordered_map<std::string, int>& outStats) {
    auto res = client.Get("/stats/" + uid, headers);
    if (!res || res->status != 200) return false;

    json stats = json::parse(res->body);
    outStats.clear();
    for (auto& [name, value] : stats.items()) {
        outStats[name] = value;
    }
    return true;
}

bool OnlineClient::startMatchmaking() {
    auto res = client.Post("/match", headers, "", "application/json");
    if (!res || res->status != 200) {
        std::cerr << "Failed to start matchmaking: " << (res ? res->status : 0) << "\n";
        if (res) std::cerr << res->body << "\n";
        return false;
    }
    isFindingMatch = true;
    return true;
}

bool OnlineClient::pollSession(std::string& outSessionUrl) {
    while (isFindingMatch) {
        auto res = client.Get("/session", headers);
        if (res && res->status == 200) {
            json body = json::parse(res->body);
            outSessionUrl = body["session"];
            isFindingMatch = false;
            return true;
        }
        std::cout << "Still waiting for match...\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    return false;
}

bool OnlineClient::fetchStore(std::vector<std::tuple<int, std::string, int>>& outSkins) {
    auto res = client.Get("/online", headers);
    if (!res || res->status != 200) return false;

    outSkins.clear();
    json store = json::parse(res->body);
    for (auto& s : store) {
        outSkins.emplace_back(s["id"], s["name"], s["price"]);
    }
    return true;
}

bool OnlineClient::purchaseSkin(int id) {
    auto res = client.Post("/online/purchase", headers,
                           json{{"Id", id}}.dump(), "application/json");
    if (!res || res->status != 200) {
        std::cerr << "Purchase failed: " << (res ? res->body : "No response") << "\n";
        return false;
    }

    //std::cout << "Purchased! Fetching inventory...\n";
    return true;
}

bool OnlineClient::fetchInventory(std::vector<int>& outInventory) {
    auto res = client.Get("/online/inventory", headers);
    if (!res || res->status != 200) return false;

    outInventory.clear();
    json inv = json::parse(res->body);
    for (int id : inv) outInventory.push_back(id);
    return true;
}

