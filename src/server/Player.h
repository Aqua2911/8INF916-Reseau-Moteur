//
// Created by CBerl139 on 13/04/2025.
//

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>


#ifndef MAGNUMBOOTSTRAP_PLAYER_H
#define MAGNUMBOOTSTRAP_PLAYER_H


class Player {
public:
    std::unordered_map<std::string, float> stats;
    void AddStat(const std::string& name, float value);

    std::vector<std::string> unlockedAchievements;
    bool HasAchievement(const std::string& id);
    void UnlockAchievement(const std::string &name);

private:
};

#endif //MAGNUMBOOTSTRAP_PLAYER_H
