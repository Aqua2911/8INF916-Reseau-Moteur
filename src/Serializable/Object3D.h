//
// Created by grave on 2025-04-06.
//

#ifndef OBJECT3D_H
#define OBJECT3D_H



#include <Magnum/SceneGraph/Object.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>
#include <fstream>
#include "Serializable.h"

typedef Magnum::SceneGraph::Object<Magnum::SceneGraph::MatrixTransformation3D> Object3DParent;
using Matrix4 = Magnum::Math::Matrix4<float>;

class Object3D : public virtual Object3DParent {
public:
    using Object3DParent::Object3DParent; // inherit constructors

    std::vector<char> serializeTransform() const {
        std::vector<char> buffer;
        Matrix4 transform = transformationMatrix();
        buffer.insert(buffer.end(), reinterpret_cast<const char*>(&transform), reinterpret_cast<const char*>(&transform) + sizeof(Matrix4));
        return buffer;
    }

    void deserializeTransform(const char* data, size_t& offset) {
        Matrix4 transform;
        std::memcpy(&transform, data + offset, sizeof(Matrix4));
        offset += sizeof(Matrix4);
        this->setTransformation(transform);
    }
};

#endif //OBJECT3D_H
