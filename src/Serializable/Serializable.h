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
    std::ofstream out = std::ofstream("serialized.txt", std::ios::binary); // open in binary mode
    virtual ~Serializable() = default;

    virtual void serialize() const = 0;
    virtual void deserialize() = 0;

    static std::vector<char>  serializeColor3(Magnum::Math::Color3<Magnum::Float> c);
    static std::vector<char>   serializeMatrix3x3(Magnum::Math::Matrix3x3<Magnum::Float> m);
    static std::vector<char>   serializeMatrix4(Magnum::Math::Matrix4<Magnum::Float> m);

    static Magnum::Math::Color3<Magnum::Float> deserializeColor3(const char *buffer, int& offset);
    static Magnum::Math::Matrix3x3<Magnum::Float> deserializeMatrix3x3(const char *buffer, int& offset);
    static Magnum::Math::Matrix4<Magnum::Float> deserializeMatrix4(const char *buffer, int& offset);
};

template<typename T>
std::vector<char> serializeMatrix(const T &matrix) {
    std::vector<char> buffer(sizeof(T));
    std::memcpy(buffer.data(), &matrix, sizeof(T));
    return buffer;
}

template <typename T>
T deserializeMatrix(const char* buffer, int& offset) {
    T matrix;
    std::memcpy(&matrix, buffer + offset, sizeof(T));
    offset += sizeof(T);
    return matrix;
}

#endif //SERIALIZABLE_H
