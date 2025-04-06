//
// Created by grave on 2025-04-06.
//

#ifndef OBJECT3D_H
#define OBJECT3D_H



#include <Magnum/SceneGraph/Object.h>
#include <Magnum/Math/Matrix4.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>
#include <Corrade/Containers/Array.h>
#include <Corrade/Utility/Assert.h>
#include <iostream>
#include <fstream>
#include "Serializable.h"

typedef Magnum::SceneGraph::Object<Magnum::SceneGraph::MatrixTransformation3D> Object3DParent;

class Object3D : public virtual Object3DParent, public virtual Serializable {
public:
    using Object3DParent::Object3DParent; // inherit constructors

    void serialize() const override { /* ... */ }
    void deserialize() override { /* ... */ }
};

#endif //OBJECT3D_H
