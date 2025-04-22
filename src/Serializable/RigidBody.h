//
// Created by grave on 2025-04-10.
//

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <btBulletDynamicsCommon.h>
#include <Corrade/Containers/Pointer.h>
#include <Magnum/BulletIntegration/MotionState.h>

#include "Object3D.h"

using namespace Magnum;

class RigidBody: public Object3D {
public:
    RigidBody(Object3DParent* parent, Float mass, btCollisionShape* bShape, btDynamicsWorld& bWorld): Object3DParent{parent}, _bWorld(bWorld) {
        /* Calculate inertia so the object reacts as it should with
           rotation and everything */
        btVector3 bInertia(0.0f, 0.0f, 0.0f);
        if(!Math::TypeTraits<Float>::equals(mass, 0.0f))
            bShape->calculateLocalInertia(mass, bInertia);

        /* Bullet rigid body setup */
        auto* motionState = new BulletIntegration::MotionState{*this};
        _bRigidBody.emplace(btRigidBody::btRigidBodyConstructionInfo{
            mass, &motionState->btMotionState(), bShape, bInertia});
        _bRigidBody->forceActivationState(DISABLE_DEACTIVATION);
        bWorld.addRigidBody(_bRigidBody.get());
    }

    ~RigidBody() override {
        _bWorld.removeRigidBody(_bRigidBody.get());
    }

    btRigidBody& rigidBody() { return *_bRigidBody; }

    /* needed after changing the pose from Magnum side */
    void syncPose() {
        _bRigidBody->setWorldTransform(btTransform(transformationMatrix()));
    }

    //std::vector<char> serialize() override {return std::vector<char>(-1);}

    //void deserialize() override {}

private:
    btDynamicsWorld& _bWorld;
    Containers::Pointer<btRigidBody> _bRigidBody;
};



#endif //RIGIDBODY_H
