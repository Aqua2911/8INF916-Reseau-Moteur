//
// Created by CBerl139 on 13/04/2025.
//

#include "Player.h"

void Player::AddStat(const std::string& name, float value) {
    stats[name] += value;  // if 'name' doesn't exist, map will initialize it to 0
}



