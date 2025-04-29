//
// Created by CBerl139 on 29/04/2025.
//

#ifndef MAGNUMSERVER_ONLINECLIENT_H
#define MAGNUMSERVER_ONLINECLIENT_H

#pragma once
#include <string>
#include "httplib.h"
#include "json.hpp"

class OnlineClient {
public:
    explicit OnlineClient(const std::string& host = "localhost", int port = 5009);

    bool login(const std::string& username);
    bool registerServer(std::string ip, int port, int capacity);
    bool fetchStatTypes(std::unordered_map<std::string, int>& outStatTypes);    // all existing stat types
    bool updateStat(const std::string& name, int value);
    bool fetchStats(std::unordered_map<std::string, int>& outStats);    // player stats
    bool startMatchmaking();
    bool pollSession(std::string& outSessionUrl);
    bool fetchStore(std::vector<std::tuple<int, std::string, int>>& outSkins);
    bool purchaseSkin(int id);
    bool fetchInventory(std::vector<int>& outInventory);

    std::string jwt;
    std::string uid;
    std::vector<int> inventory;

    bool isFindingMatch = false;

private:
    httplib::Client client;
    httplib::Headers headers;
};


#endif //MAGNUMSERVER_ONLINECLIENT_H
