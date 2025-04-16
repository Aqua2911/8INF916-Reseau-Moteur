//
// Created by grave on 2025-04-06.
//

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H
#include <fstream>
#include <ostream>
#include <vector>
#include <cstring>

#include "Magnum/Math/Color.h"
#include <Magnum/Math/Matrix4.h>

class Serializable {
public:
    std::ofstream out = std::ofstream("serialized.bin", std::ios::binary); // open in binary mode
    virtual ~Serializable() = default;

    virtual void serialize() const = 0;
    virtual void deserialize() = 0;

    static std::string serializeColor3(Magnum::Math::Color3<Magnum::Float> c);
    static std::string  serializeMatrix3x3(Magnum::Math::Matrix3x3<Magnum::Float> m);
    static std::vector<char>   serializeMatrix4(Magnum::Math::Matrix4<Magnum::Float> m);

    static Magnum::Math::Color3<Magnum::Float> deserializeColor3();
    static Magnum::Math::Matrix3x3<Magnum::Float> deserializeMatrix3x3();
    static Magnum::Math::Matrix4<Magnum::Float> deserializeMatrix4();
};

#endif //SERIALIZABLE_H
