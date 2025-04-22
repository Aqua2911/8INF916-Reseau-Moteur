//
// Created by grave on 2025-04-10.
//

#include "Serializable.h"

std::vector<char>  Serializable::serializeColor3(Magnum::Color3 c){
    std::vector<char> buffer(sizeof(Magnum::Color3));
    std::memcpy(buffer.data(), &c, sizeof(Magnum::Color3));
    return buffer;
}

std::vector<char> Serializable::serializeMatrix3x3(Magnum::Matrix3x3 m) {
    return serializeMatrix(m);
}

std::vector<char> Serializable::serializeMatrix4(Magnum::Matrix4 m) {
    return serializeMatrix(m);
}

Magnum::Math::Color3<Magnum::Float> Serializable::deserializeColor3(const char *buffer, int& offset) {
    Magnum::Math::Color3<Magnum::Float> c;

    std::memcpy(&c, buffer + offset, sizeof(Magnum::Math::Color3<Magnum::Float>));
    offset += sizeof(Magnum::Math::Color3<Magnum::Float>);

    return c;
}

Magnum::Math::Matrix3x3<Magnum::Float> Serializable::deserializeMatrix3x3(const char *buffer, int& offset) {
    return deserializeMatrix<Magnum::Math::Matrix3x3<Magnum::Float>>(buffer, offset);
}

Magnum::Math::Matrix4<Magnum::Float> Serializable::deserializeMatrix4(const char *buffer, int& offset) {
    return deserializeMatrix<Magnum::Math::Matrix4<Magnum::Float>>(buffer, offset);
}