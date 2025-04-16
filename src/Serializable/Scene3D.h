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
#include "Magnum/SceneGraph/Scene.h"


typedef Magnum::SceneGraph::Scene<Magnum::SceneGraph::MatrixTransformation3D> Scene3DParent;


class Scene3D : public virtual Scene3DParent, Serializable{
public:
    using Scene3DParent::Scene3DParent;

    void serialize(std::ostream& out) const override;

    void deserialize(std::istream& in) override;
};

inline void Scene3D::serialize(std::ostream &out) const {
}

inline void Scene3D::deserialize(std::istream &in) {
}


#endif //SCENE3D_H
