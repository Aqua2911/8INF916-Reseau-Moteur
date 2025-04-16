//
// Created by grave on 2025-04-10.
//

#include "Serializable.h"

std::string Serializable::serializeColor3(Magnum::Color3 c) {
    return std::string(reinterpret_cast<const char*>(&c), sizeof(c));
}

std::string Serializable::serializeMatrix3x3(Magnum::Matrix3x3 m) {
    return std::string(reinterpret_cast<const char*>(&m), sizeof(m));
}

std::vector<char>  Serializable::serializeMatrix4(Magnum::Matrix4 m) {
    std::vector<char> buffer(sizeof(Magnum::Matrix4));
    std::memcpy(buffer.data(), &m, sizeof(Magnum::Matrix4));
    return buffer;
}

Magnum::Math::Color3<Magnum::Float> Serializable::deserializeColor3() {
    Magnum::Math::Color3<Magnum::Float> m;
    return m;
}

Magnum::Math::Matrix3x3<Magnum::Float> Serializable::deserializeMatrix3x3() {
    Magnum::Math::Matrix3x3<Magnum::Float> m;
    return m;
}

Magnum::Math::Matrix4<Magnum::Float> Serializable::deserializeMatrix4() {
    Magnum::Math::Matrix4<Magnum::Float> m;
    return m;
}