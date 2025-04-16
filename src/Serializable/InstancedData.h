//
// Created by grave on 2025-04-10.
//

#ifndef INSTANCEDDATA_H
#define INSTANCEDDATA_H

#include <Magnum/BulletIntegration/DebugDraw.h>
#include <Magnum/Math/Color.h>

#include "Serializable.h"

using namespace Magnum;

struct InstanceData {
    Matrix4 transformationMatrix;
    Matrix3x3 normalMatrix;
    Color3 color;

    void serialize(std::ostream &out) const ;
    void deserialize(std::istream &in) ;
};

inline void InstanceData::serialize(std::ostream &out) const {
    Serializable::serializeMatrix4(transformationMatrix);
    Serializable::serializeMatrix3x3(normalMatrix);
    Serializable::serializeColor3(color);
}

inline void InstanceData::deserialize(std::istream &in) {
    Serializable::deserializeMatrix4();
    Serializable::deserializeMatrix3x3();
    Serializable::deserializeColor3();
}

#endif //INSTANCEDDATA_H
