//
// Created by CBerl139 on 13/04/2025.
//

#ifndef MAGNUMBOOTSTRAP_ACHIEVEMENTMANAGER_H
#define MAGNUMBOOTSTRAP_ACHIEVEMENTMANAGER_H


#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include "Player.h"

struct Achievement {
    std::string name;
    std::string statKey;  // ex: "games_won"
    float threshold;

    [[nodiscard]] bool IsUnlocked(float statValue) const {
        return statValue >= threshold;
    }
};

class AchievementManager {
public:
    static void PopulateAchievements(); // achievements codés en dur
    static void CheckAchievements(Player& player);

private:
    static std::vector<Achievement> allAchievements;
};


#endif //MAGNUMBOOTSTRAP_ACHIEVEMENTMANAGER_H
