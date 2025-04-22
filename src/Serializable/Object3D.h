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

class Object3D : public virtual Object3DParent, public virtual Serializable {
public:
    using Object3DParent::Object3DParent; // inherit constructors

    std::vector<char> serialize() override { /* ... */return std::vector<char>(-1); }
    void deserialize() override { /* ... */ }
};

#endif //OBJECT3D_H
