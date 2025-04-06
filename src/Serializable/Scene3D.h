//
// Created by grave on 2025-04-06.
//

#ifndef SCENE3D_H
#define SCENE3D_H

#include <Magnum/SceneGraph/Object.h>
#include <Magnum/Math/Matrix4.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>
#include <Corrade/Containers/Array.h>
#include <Corrade/Utility/Assert.h>
#include <iostream>
#include <fstream>
#include "Serializable.h"


typedef Magnum::SceneGraph::Scene<Magnum::SceneGraph::MatrixTransformation3D> Scene3DParent;


class Scene3D : public virtual Scene3DParent, public Serializable {
public:
    using Scene3DParent::Scene3DParent;

    void serialize() const override {
    }

    void deserialize() override {
    }
};



#endif //SCENE3D_H
