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

#include "Serializable/InstancedData.h"
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

class MyApplication: public Platform::GlfwApplication
{
    public:
        explicit MyApplication(const Arguments& arguments);

    private:
        void drawEvent() override;
        void keyPressEvent(KeyEvent& event) override;
        void pointerPressEvent(PointerEvent& event) override;

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

        Scene3D _scene;
        SceneGraph::Camera3D* _camera;
        SceneGraph::DrawableGroup3D _drawables;
        Timeline _timeline;

        Object3D *_cameraRig, *_cameraObject;

        btBoxShape _bBoxShape{{0.5f, 0.5f, 0.5f}};
        btSphereShape _bSphereShape{0.25f};
        btBoxShape _bGroundShape{{4.0f, 0.5f, 4.0f}};

        bool _drawCubes{true}, _drawDebug{true};
};



MyApplication::MyApplication(const Arguments& arguments):
    Platform::GlfwApplication(arguments, NoCreate)
{
    /* Try 8x MSAA, fall back to zero samples if not possible. Enable only 2x
       MSAA if we have enough DPI. */
    {
        const Vector2 dpiScaling = this->dpiScaling({});
        Configuration conf;
        conf.setTitle("Bullet Test")
            .setSize(conf.size(), dpiScaling);
        GLConfiguration glConf;
        glConf.setSampleCount(dpiScaling.max() < 2.0f ? 8 : 2);
        if(!tryCreate(conf, glConf))
            create(conf, glConf.setSampleCount(0));
    }

    /* Camera setup */
    (*(_cameraRig = new Object3D{&_scene}))
        .translate(Vector3::yAxis(3.0f))
        .rotateY(40.0_degf);
    (*(_cameraObject = new Object3D{_cameraRig}))
        .translate(Vector3::zAxis(20.0f))
        .rotateX(-25.0_degf);
    (_camera = new SceneGraph::Camera3D(*_cameraObject))
        ->setAspectRatioPolicy(SceneGraph::AspectRatioPolicy::Extend)
        .setProjectionMatrix(Matrix4::perspectiveProjection(35.0_degf, 1.0f, 0.001f, 100.0f))
        .setViewport(GL::defaultFramebuffer.viewport().size());

    /* Create an instanced shader */
    _shader = Shaders::PhongGL{Shaders::PhongGL::Configuration{}
        .setFlags(Shaders::PhongGL::Flag::VertexColor|
                  Shaders::PhongGL::Flag::InstancedTransformation)};
    _shader.setAmbientColor(0x111111_rgbf)
           .setSpecularColor(0x330000_rgbf)
           .setLightPositions({{10.0f, 15.0f, 5.0f, 0.0f}});

    /* Box and sphere mesh, with an (initially empty) instance buffer */
    _box = MeshTools::compile(Primitives::cubeSolid());
    _sphere = MeshTools::compile(Primitives::uvSphereSolid(16, 32));
    _boxInstanceBuffer = GL::Buffer{};
    _sphereInstanceBuffer = GL::Buffer{};
    _box.addVertexBufferInstanced(_boxInstanceBuffer, 1, 0,
        Shaders::PhongGL::TransformationMatrix{},
        Shaders::PhongGL::NormalMatrix{},
        Shaders::PhongGL::Color3{});
    _sphere.addVertexBufferInstanced(_sphereInstanceBuffer, 1, 0,
        Shaders::PhongGL::TransformationMatrix{},
        Shaders::PhongGL::NormalMatrix{},
        Shaders::PhongGL::Color3{});

    /* Setup the renderer so we can draw the debug lines on top */
    GL::Renderer::enable(GL::Renderer::Feature::DepthTest);
    GL::Renderer::enable(GL::Renderer::Feature::FaceCulling);
    GL::Renderer::enable(GL::Renderer::Feature::PolygonOffsetFill);
    GL::Renderer::setPolygonOffset(2.0f, 0.5f);

    /* Bullet setup */
    _debugDraw = BulletIntegration::DebugDraw{};
    _debugDraw.setMode(BulletIntegration::DebugDraw::Mode::DrawWireframe);
    _bWorld.setGravity({0.0f, -10.0f, 0.0f});
    //_bWorld.setDebugDrawer(&_debugDraw);

    /* Create the ground */
    auto* ground = new RigidBody{&_scene, 0.0f, &_bGroundShape, _bWorld};
    new ColoredDrawable{*ground, _boxInstanceData, 0xffffff_rgbf,
        Matrix4::scaling({4.0f, 0.5f, 4.0f}), _drawables};

    /* Create boxes with random colors */
    Deg hue = 42.0_degf;
    for(Int i = 0; i != 5; ++i) {
        for(Int j = 0; j != 5; ++j) {
            for(Int k = 0; k != 5; ++k) {
                auto* o = new RigidBody{&_scene, 1.0f, &_bBoxShape, _bWorld};
                o->translate({i - 2.0f, j + 4.0f, k - 2.0f});
                o->syncPose();
                new ColoredDrawable{*o, _boxInstanceData,
                    Color3::fromHsv({hue += 137.5_degf, 0.75f, 0.9f}),
                    Matrix4::scaling(Vector3{0.5f}), _drawables};
            }
        }
    }

    /* Loop at 60 Hz max */
    setSwapInterval(1);
    setMinimalLoopPeriod(16.0_msec);
    _timeline.start();

}

void MyApplication::drawEvent() {
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color|GL::FramebufferClear::Depth);

    /* Housekeeping: remove any objects which are far away from the origin */
    for(auto* base = _scene.children().first(); base;) {
        auto* obj = dynamic_cast<Object3D*>(base);
        auto* nextBase = base->nextSibling();

        if(obj && obj->transformation().translation().dot() > 100*100)
            delete obj;

        base = nextBase;
    }


    /* Step bullet simulation */
    _bWorld.stepSimulation(_timeline.previousFrameDuration(), 5);

    if(_drawCubes) {
        /* Populate instance data with transformations and colors */
        arrayResize(_boxInstanceData, 0);
        arrayResize(_sphereInstanceData, 0);
        _camera->draw(_drawables);
        _shader.setProjectionMatrix(_camera->projectionMatrix());

        /* Upload instance data to the GPU (orphaning the previous buffer
           contents) and draw all cubes in one call, and all spheres (if any)
           in another call */
        _boxInstanceBuffer.setData(_boxInstanceData, GL::BufferUsage::DynamicDraw);
        _box.setInstanceCount(_boxInstanceData.size());
        _shader.draw(_box);

        _sphereInstanceBuffer.setData(_sphereInstanceData, GL::BufferUsage::DynamicDraw);
        _sphere.setInstanceCount(_sphereInstanceData.size());
        _shader.draw(_sphere);
    }

    /*Debug draw. If drawing on top of cubes, avoid flickering by setting
       depth function to <= instead of just <.*/
    if(_drawDebug) {
        if(_drawCubes)
            GL::Renderer::setDepthFunction(GL::Renderer::DepthFunction::LessOrEqual);

        _debugDraw.setTransformationProjectionMatrix(
            _camera->projectionMatrix()*_camera->cameraMatrix());
        _bWorld.debugDrawWorld();

        if(_drawCubes)
            GL::Renderer::setDepthFunction(GL::Renderer::DepthFunction::Less);
    }


    swapBuffers();
    _timeline.nextFrame();
    redraw();
}


void MyApplication::keyPressEvent(KeyEvent& event) {
    /* Movement */
    if(event.key() == Key::S) {
        _cameraObject->rotateX(5.0_degf);
    } else if(event.key() == Key::W) {
        _cameraObject->rotateX(-5.0_degf);
    } else if(event.key() == Key::A) {
        _cameraRig->rotateY(-5.0_degf);
    } else if(event.key() == Key::D) {
        _cameraRig->rotateY(5.0_degf);
    } else if(event.key() == Key::Q) {
        // Move forward
        _cameraRig->translate(_cameraRig->transformation().backward() * -1);
    } else if(event.key() == Key::E) {
        // Move backward
        _cameraRig->translate(_cameraRig->transformation().backward());
    } else return;

    event.setAccepted();
}

void MyApplication::pointerPressEvent(PointerEvent& event) {/* Shoot an object on click */
    if(!event.isPrimary() ||
       !(event.pointer() & Pointer::MouseLeft))
        return;

    /* First scale the position from being relative to window size to being
       relative to framebuffer size as those two can be different on HiDPI
       systems */
    const Vector2 position = event.position()*Vector2{framebufferSize()}/Vector2{windowSize()};
    const Vector2 clickPoint = Vector2::yScale(-1.0f)*(position/Vector2{framebufferSize()} - Vector2{0.5f})*_camera->projectionSize();
    const Vector3 direction = (_cameraObject->absoluteTransformation().rotationScaling()*Vector3{clickPoint, -1.0f}).normalized();

    auto* object = new RigidBody{
        &_scene,
        5.0f,
        &_bSphereShape,
        _bWorld};
    object->translate(_cameraObject->absoluteTransformation().translation());
    /* Has to be done explicitly after the translate() above, as Magnum ->
       Bullet updates are implicitly done only for kinematic bodies */
    object->syncPose();

    /* Create either a box or a sphere */
    new ColoredDrawable{*object,
        _sphereInstanceData,
        0x220000_rgbf,
        Matrix4::scaling(Vector3{0.25f}), _drawables};

    /* Give it an initial velocity */
    object->rigidBody().setLinearVelocity(btVector3{direction*25.f});

    event.setAccepted();
}

MAGNUM_APPLICATION_MAIN(MyApplication)
