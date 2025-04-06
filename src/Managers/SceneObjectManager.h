//
// Created by grave on 2025-04-02.
//

#ifndef SCENEOBJECTMANAGER_H
#define SCENEOBJECTMANAGER_H

#include "PhysicManager.h"

class SceneObjectsManager {
public:
    SceneObjectsManager(){};

    void Initialize(Scene3D& scene, btDiscreteDynamicsWorld& world) {
        for(int x = -5; x <= 5; ++x) {
            for(int z = -5; z <= 5; ++z) {
                CreateBox(scene, world, {Float(x), 2.0f, Float(z)});
            }
        }
    }

    void CreateBox(Scene3D& scene, btDiscreteDynamicsWorld& world, const Magnum::Vector3& position) {
        auto* obj = new RigidBody{&scene, 1.0f, new btBoxShape({0.5f, 0.5f, 0.5f}), world};
        obj->translate(position);
        obj->syncPose();

        // Optional: add drawable here
        // new ColoredDrawable{*obj, instanceData, 0x228822_rgbf, Matrix4::scaling(Vector3{1.0f}), drawables};
    }

private:
    SceneGraph::DrawableGroup3D _drawables;
    //btBoxShape _bBoxShape;
    Containers::Array<InstanceData> _boxInstanceData, _sphereInstanceData;
};

#endif //SCENEOBJECTMANAGER_H
