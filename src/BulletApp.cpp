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
