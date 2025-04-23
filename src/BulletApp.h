//
// Created by grave on 2025-04-21.
//

#ifndef BULLETAPP_H
#define BULLETAPP_H

#include <Magnum/Timeline.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Math/Time.h>
#include <Magnum/MeshTools/Compile.h>
#include <Magnum/Platform/GlfwApplication.h>
#include <Magnum/Primitives/Cube.h>
#include <Magnum/Primitives/UVSphere.h>
#include <Magnum/SceneGraph/Camera.h>
#include <Magnum/Shaders/PhongGL.h>
#include <Magnum/Trade/MeshData.h>

#include "Serializable/ObjectData.h"
#include "../externals/enet6/include/enet6/enet.h"
#include "Serializable/InstanceData.h"
#include "Serializable/Object3D.h"
#include "Serializable/Scene3D.h"
#include "Serializable/ColoredDrawable.h"
#include "Serializable/RigidBody.h"

#ifdef BT_USE_DOUBLE_PRECISION
#error sorry, this example does not support Bullet with double precision enabled
#endif

using namespace Magnum;

using namespace Math::Literals;

//typedef SceneGraph::Object<SceneGraph::MatrixTransformation3D> Object3D;
//typedef SceneGraph::Scene<SceneGraph::MatrixTransformation3D> Scene3D;

class BulletApp: public Platform::GlfwApplication
{
    public:

    explicit BulletApp(const Arguments& arguments, const Magnum::NoCreateT&);

    protected:
        void drawEvent() override;
        void keyPressEvent(KeyEvent& event) override;

        GL::Mesh _box{NoCreate}, _sphere{NoCreate};
        GL::Buffer _boxInstanceBuffer{NoCreate}, _sphereInstanceBuffer{NoCreate};
        Shaders::PhongGL _shader{NoCreate};
        BulletIntegration::DebugDraw _debugDraw{NoCreate};
        Containers::Array<InstanceData> _boxInstanceData, _sphereInstanceData;

        btDbvtBroadphase _bBroadphase;
        btDefaultCollisionConfiguration _bCollisionConfig;
        btCollisionDispatcher _bDispatcher{&_bCollisionConfig};
        btSequentialImpulseConstraintSolver _bSolver;

        btDiscreteDynamicsWorld _bWorld{&_bDispatcher, &_bBroadphase, &_bSolver, &_bCollisionConfig};

        SceneGraph::Camera3D* _camera;
        SceneGraph::DrawableGroup3D _drawables;
        Timeline _timeline;

        Object3D *_cameraRig, *_cameraObject;

        btBoxShape _bBoxShape{{0.5f, 0.5f, 0.5f}};
        btSphereShape _bSphereShape{0.25f};
        btBoxShape _bGroundShape{{4.0f, 0.5f, 4.0f}};

        bool _drawCubes{true}, _drawDebug{true};

        //store object Data at the same place
        std::vector<ObjectData> _serializables;
};

#endif //BULLETAPP_H
