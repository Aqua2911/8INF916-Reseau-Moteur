//
// Created by grave on 2025-04-10.
//

#include "Serializable.h"

std::vector<char>  Serializable::serializeColor3(Magnum::Color3 c){
    std::vector<char> buffer(sizeof(Magnum::Color3));
    std::memcpy(buffer.data(), &c, sizeof(Magnum::Color3));
    return buffer;
}

std::vector<char>  Serializable::serializeMatrix3x3(Magnum::Matrix3x3 m) {
    std::vector<char> buffer(sizeof(Magnum::Matrix3x3));
    std::memcpy(buffer.data(), &m, sizeof(Magnum::Matrix3x3));
    return buffer;
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
    Magnum::Matrix4 matrix;
    //in.read(reinterpret_cast<char*>(&matrix), sizeof(matrix));
    //if (!in) {
        //std::cerr << "Failed to read Matrix4 from stream!" << std::endl;
        // Handle error appropriately — return identity matrix or throw?
    //}
    return matrix;
}