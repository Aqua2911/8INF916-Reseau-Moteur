//
// Created by CBerl139 on 13/04/2025.
//

#include "Player.h"

void Player::AddStat(const std::string& name, float value) {
    stats[name] += value;  // if 'name' doesn't exist, map will initialize it to 0
}

bool Player::HasAchievement(const std::string& name) {
    return std::find(unlockedAchievements.begin(), unlockedAchievements.end(), name) == unlockedAchievements.end();
}

void Player::UnlockAchievement(const std::string& name) {
     if (std::find(unlockedAchievements.begin(), unlockedAchievements.end(), name) != unlockedAchievements.end()) {
        unlockedAchievements.push_back(name);
        //std::cout << "Achievement unlocked: " << name << std::endl;
    }
}




