//
// Created by grave on 2025-04-10.
//

#ifndef INSTANCEDATA_H
#define INSTANCEDATA_H

#include <Magnum/BulletIntegration/DebugDraw.h>
#include <Magnum/Math/Color.h>

#include "Serializable.h"

using namespace Magnum;

struct InstanceData {
    Matrix4 transformationMatrix;
    Matrix3x3 normalMatrix;
    Color3 color;

    std::vector<char> serialize() const ;
    InstanceData deserialize(std::streampos position) ;
    InstanceData deserialize(const char *buffer, int &offset);
};

#endif //INSTANCEDATA_H
