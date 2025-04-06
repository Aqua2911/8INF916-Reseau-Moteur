//
// Created by grave on 2025-04-02.
//

#ifndef PHYSICMANAGER_H
#define PHYSICMANAGER_H

#include <btBulletDynamicsCommon.h>
#include <iostream>
#include <Corrade/Containers/GrowableArray.h>
#include <Corrade/Containers/Pointer.h>
#include <Magnum/BulletIntegration/MotionState.h>
#include <Magnum/BulletIntegration/DebugDraw.h>
#include <Magnum/Math/Color.h>
#include <Magnum/SceneGraph/Drawable.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>


using namespace Magnum;

using namespace Math::Literals;

typedef SceneGraph::Object<SceneGraph::MatrixTransformation3D> Object3D;

struct InstanceData {
    Matrix4 transformationMatrix;
    Matrix3x3 normalMatrix;
    Color3 color;
};

class ColoredDrawable: public SceneGraph::Drawable3D {
public:
    explicit ColoredDrawable(Object3D& object, Containers::Array<InstanceData>& instanceData, const Color3& color, const Matrix4& primitiveTransformation, SceneGraph::DrawableGroup3D& drawables): SceneGraph::Drawable3D{object, &drawables}, _instanceData(instanceData), _color{color}, _primitiveTransformation{primitiveTransformation} {}

private:
    void draw(const Matrix4& transformation, SceneGraph::Camera3D&) override {
        const Matrix4 t = transformation*_primitiveTransformation;
        arrayAppend(_instanceData, InPlaceInit, t, t.normalMatrix(), _color);
    }

    Containers::Array<InstanceData>& _instanceData;
    Color3 _color;
    Matrix4 _primitiveTransformation;
};

class RigidBody: public Object3D {
public:
    RigidBody(Object3D* parent, Float mass, btCollisionShape* bShape, btDynamicsWorld& bWorld): Object3D{parent}, _bWorld(bWorld) {
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

    ~RigidBody() {
        _bWorld.removeRigidBody(_bRigidBody.get());
    }

    btRigidBody& rigidBody() { return *_bRigidBody; }

    /* needed after changing the pose from Magnum side */
    void syncPose() {
        _bRigidBody->setWorldTransform(btTransform(transformationMatrix()));
    }

private:
    btDynamicsWorld& _bWorld;
    Containers::Pointer<btRigidBody> _bRigidBody;
};

class PhysicsManager {
public:
    PhysicsManager(){};

    void Initialize() {
        _debugDraw.setMode(BulletIntegration::DebugDraw::Mode::DrawWireframe);
        _bWorld.setGravity({0.0f, -10.0f, 0.0f});
        _bWorld.setDebugDrawer(&_debugDraw);
    }

    void addGround(Object3D& scene) {
        auto* ground = new RigidBody{&scene, 0.0f, &_bGroundShape, _bWorld};
        new ColoredDrawable{*ground, _boxInstanceData, 0xffffff_rgbf,
            Matrix4::scaling({4.0f, 0.5f, 4.0f}), _drawables};
    }

    btDiscreteDynamicsWorld &GetWorld() {return _bWorld;}
    void stepSimulation(float deltaTime){_bWorld.stepSimulation(deltaTime, 5);}
    void debugDraw(Magnum::SceneGraph::Camera3D* camera) {
        static BulletIntegration::DebugDraw debugDraw;
        debugDraw.setTransformationProjectionMatrix(
            camera->projectionMatrix() * camera->cameraMatrix());

        _bWorld.setDebugDrawer(&debugDraw);
        _bWorld.debugDrawWorld();
    }

    void ShootSphere(
        Scene3D& scene,
        const Vector3& origin,
        const Vector3& direction,
        btCollisionShape* shape,
        SceneGraph::DrawableGroup3D& drawables,
        Containers::Array<InstanceData>& instanceData) {
        auto* object = new RigidBody{&scene, 5.0f, shape, _bWorld};
        object->translate(origin);
        object->syncPose();

        new ColoredDrawable{
            *object,
            instanceData,
            0x220000_rgbf,
            Matrix4::scaling(Vector3{0.25f}),
            drawables
        };

        object->rigidBody().setLinearVelocity(btVector3{direction * 25.0f});
    }

private:
    SceneGraph::DrawableGroup3D _drawables;
    Containers::Array<InstanceData> _boxInstanceData, _sphereInstanceData;
    BulletIntegration::DebugDraw _debugDraw;

    btDbvtBroadphase _bBroadphase;
    btDefaultCollisionConfiguration _bCollisionConfig;
    btCollisionDispatcher _bDispatcher{&_bCollisionConfig};
    btSequentialImpulseConstraintSolver _bSolver;
    btDiscreteDynamicsWorld _bWorld{&_bDispatcher, &_bBroadphase, &_bSolver, &_bCollisionConfig};
    btBoxShape _bGroundShape{{4.0f, 0.5f, 4.0f}};
};




#endif //PHYSICMANAGER_H
