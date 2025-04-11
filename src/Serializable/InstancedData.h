//
// Created by grave on 2025-04-10.
//

#ifndef INSTANCEDDATA_H
#define INSTANCEDDATA_H

#include <Magnum/BulletIntegration/DebugDraw.h>
#include <Magnum/Math/Color.h>

using namespace Magnum;

struct InstanceData {
    Matrix4 transformationMatrix;
    Matrix3x3 normalMatrix;
    Color3 color;
};



#endif //INSTANCEDDATA_H
