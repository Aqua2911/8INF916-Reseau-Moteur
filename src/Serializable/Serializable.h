//
// Created by grave on 2025-04-06.
//

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

class Serializable {
public:
    virtual ~Serializable() = default;

    virtual void serialize(std::ostream& out) const = 0;
    virtual void deserialize(std::istream& in) = 0;

    static void serializeColor3(Magnum::Math::Color3<Magnum::Float> c);
    static void serializeMatrix3x3(Magnum::Math::Matrix3x3<Magnum::Float> m);
    static void serializeMatrix4(Magnum::Math::Matrix4<Magnum::Float> m);

    static Magnum::Math::Color3<Magnum::Float> deserializeColor3();
    static Magnum::Math::Matrix3x3<Magnum::Float> deserializeMatrix3x3();
    static Magnum::Math::Matrix4<Magnum::Float> deserializeMatrix4();
};

inline void Serializable::serializeColor3(Magnum::Math::Color3<Magnum::Float> c) {}

inline void Serializable::serializeMatrix3x3(Magnum::Math::Matrix3x3<Magnum::Float> m) {}

inline void Serializable::serializeMatrix4(Magnum::Math::Matrix4<Magnum::Float> m) {}

inline Magnum::Math::Color3<Magnum::Float> Serializable::deserializeColor3() {
    Magnum::Math::Color3<Magnum::Float> m;
    return m;
}

inline Magnum::Math::Matrix3x3<Magnum::Float> Serializable::deserializeMatrix3x3() {
    Magnum::Math::Matrix3x3<Magnum::Float> m;
    return m;
}

inline Magnum::Math::Matrix4<Magnum::Float> Serializable::deserializeMatrix4() {
    Magnum::Math::Matrix4<Magnum::Float> m;
    return m;
}

#endif //SERIALIZABLE_H
