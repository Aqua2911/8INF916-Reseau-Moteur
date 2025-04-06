//
// Created by grave on 2025-04-02.
//
#include <Magnum/Timeline.h>
#include <Magnum/Math/Time.h>
#include <Magnum/Platform/GlfwApplication.h>
#include <Magnum/SceneGraph/Scene.h>

#include "Managers/CameraManager.h"
#include "Managers/PhysicManager.h"
#include "Managers/Renderer.h"
#include "Managers/SceneObjectManager.h"

#ifdef BT_USE_DOUBLE_PRECISION
#error sorry, this example does not support Bullet with double precision enabled
#endif

using namespace Magnum;

using namespace Math::Literals;

typedef SceneGraph::Object<SceneGraph::MatrixTransformation3D> Object3D;
typedef SceneGraph::Scene<SceneGraph::MatrixTransformation3D> Scene3D;

class MyApplication: public Platform::GlfwApplication
{
    public:
        explicit MyApplication(const Arguments& arguments);

    private:
        void drawEvent() override;
        void keyPressEvent(KeyEvent& event) override;
        void pointerPressEvent(PointerEvent& event) override;

        BulletIntegration::DebugDraw _debugDraw{NoCreate};

        //Managers
        CameraManager CameraManager;
        PhysicsManager PhysicManager;
        Renderer Renderer;
        SceneObjectsManager SceneObjectsManager;

        //Scene and Drawables
        Scene3D _scene;
        SceneGraph::DrawableGroup3D _drawables;
    
        Timeline _timeline;

        bool _drawCubes{true}, _drawDebug{true};
};

MyApplication::MyApplication(const Arguments& arguments): Platform::GlfwApplication(arguments, NoCreate)
{
    /* Try 8x MSAA, fallback to zero if not possible */
    const Vector2 dpiScaling = this->dpiScaling({});
    Configuration conf;
    conf.setTitle("Bullet Test")
        .setSize(conf.size(), dpiScaling);
    GLConfiguration glConf;
    glConf.setSampleCount(dpiScaling.max() < 2.0f ? 8 : 2);
    // Configs...
    if (!tryCreate(conf, glConf))
        create(conf, glConf.setSampleCount(0));

    /* Initialize managers */
    PhysicManager.Initialize();
    Renderer.Initialize();
    CameraManager.Initialize(_scene);
    SceneObjectsManager.Initialize(_scene, PhysicManager.GetWorld());

    setSwapInterval(1);
    setMinimalLoopPeriod(16.0_msec);
    _timeline.start();
}

void MyApplication::drawEvent() {
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color | GL::FramebufferClear::Depth);

    /* Remove distant objects */
    for(Object3D* obj = _scene.children().first(); obj; ) {
        Object3D* next = obj->nextSibling();
        if(obj->transformation().translation().dot() > 100*100)
            delete obj;
        obj = next;
    }

    /* Step simulation */
    PhysicManager.stepSimulation(_timeline.previousFrameDuration());

    /* Render objects */
    if(_drawCubes)
        Renderer.render(CameraManager.GetCamera(), _drawables);

    /* Debug draw */
    if(_drawDebug)
        PhysicManager.debugDraw(CameraManager.GetCamera());

    swapBuffers();
    _timeline.nextFrame();
    redraw();
}

void MyApplication::keyPressEvent(KeyEvent &event) {
    /* Movement */
    if(CameraManager.HandleInput(event))
        event.setAccepted();
}

void MyApplication::pointerPressEvent(PointerEvent &event) {
       if(!event.isPrimary() || !(event.pointer() & Pointer::MouseLeft))
           return;
       const Vector2 position = event.position()*Vector2{framebufferSize()} / Vector2{windowSize()};
       const Vector2 clickPoint = Vector2::yScale(-1.0f)*(position / Vector2{framebufferSize()} - Vector2{0.5f})*CameraManager.GetCamera()->projectionSize();
       const Vector3 direction = (CameraManager.GetCameraObject()->absoluteTransformation().rotationScaling()*Vector3{clickPoint, -1.0f}).normalized();

       PhysicManager.ShootSphere(
           _scene,
           CameraManager.GetCameraObject()->absoluteTransformation().translation(),
           direction,
           Renderer.GetSphereShape(),
           _drawables,
           Renderer.GetSphereInstanceData());
       event.setAccepted();
}

    MAGNUM_APPLICATION_MAIN(MyApplication)
