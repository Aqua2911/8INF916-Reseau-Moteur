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

#include "../externals/enet6/include/enet6/enet.h"
#include "Serializable/InstanceData.h"
#include "Serializable/Object3D.h"
#include "Serializable/Scene3D.h"
#include "Serializable/ColoredDrawable.h"
#include "Serializable/RigidBody.h"

#include "BulletApp.h"

#ifdef BT_USE_DOUBLE_PRECISION
#error sorry, this example does not support Bullet with double precision enabled
#endif

using namespace Magnum;

using namespace Math::Literals;

BulletApp::BulletApp(const Arguments& arguments, const NoCreateT& noCreate)
    : Platform::GlfwApplication{arguments, noCreate},
      _bWorld{nullptr, nullptr, nullptr, nullptr} // Setup deferred
{

}

void BulletApp::drawEvent() {
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color|GL::FramebufferClear::Depth);

    /*
    int currentPos = 0;
    for (auto iData: _boxInstanceData) {
        iData.deserialize(currentPos);

        // Move to the next position in the file for the next object
        currentPos += sizeof(InstanceData);
    }
    */

    /* Housekeeping: remove any objects which are far away from the origin */
    for(auto* base = _scene.children().first(); base;) {
        auto* obj = dynamic_cast<Object3D*>(base);
        auto* nextBase = base->nextSibling();

        if(obj && obj->transformation().translation().dot() > 100*100)
            delete obj;

        base = nextBase;
    }
}


void BulletApp::keyPressEvent(KeyEvent& event) {
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

void BulletApp::pointerPressEvent(PointerEvent& event) {/* Shoot an object on click */
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
