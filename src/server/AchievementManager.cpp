//
// Created by CBerl139 on 13/04/2025.
//

#include "AchievementManager.h"

/**
 * Unlock achievements of which the unlocking-requirement has been met, otherwise do nothing
 */
void AchievementManager::CheckAchievements(Player& player) {
    for (const auto& achievement : allAchievements) {
        float playerStatValue = player.stats.at(achievement.statKey);

        if (!player.HasAchievement(achievement.name) && achievement.IsUnlocked(playerStatValue)) {
            player.UnlockAchievement(achievement.name);
        }
    }
}

void AchievementManager::PopulateAchievements() {
    allAchievements =  {
            {"First Victory", "games_won", 1},
            {"Cube Master", "cubes_pushed", 100},
            {"Champion", "games_won", 10}
    };
}