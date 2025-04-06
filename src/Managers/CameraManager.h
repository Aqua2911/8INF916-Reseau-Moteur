//
// Created by grave on 2025-04-02.
//

#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/SceneGraph/Camera.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>

using namespace Magnum;

using namespace Math::Literals;

typedef SceneGraph::Object<SceneGraph::MatrixTransformation3D> Object3D;
typedef SceneGraph::Scene<SceneGraph::MatrixTransformation3D> Scene3D;


class CameraManager {
public:
    CameraManager(): _cameraRig(nullptr), _cameraObject(nullptr), _camera(nullptr) {
    };

    void Initialize(Object3D& scene) {
        _cameraRig = new Object3D{&scene};
        _cameraRig->translate(Vector3::yAxis(3.0f)).rotateY(40.0_degf);

        _cameraObject = new Object3D{_cameraRig};
        _cameraObject->translate(Vector3::zAxis(20.0f)).rotateX(-25.0_degf);

        _camera = new SceneGraph::Camera3D(*_cameraObject);
        _camera->setAspectRatioPolicy(SceneGraph::AspectRatioPolicy::Extend)
               .setProjectionMatrix(Matrix4::perspectiveProjection(35.0_degf, 1.0f, 0.001f, 100.0f))
               .setViewport(GL::defaultFramebuffer.viewport().size());
    }

    SceneGraph::Camera3D* GetCamera() { return _camera; }

    bool HandleInput(Platform::Application::KeyEvent &event) {
        bool b = true;
        /* Movement */
        if(event.key() == Platform::Application::Key::S) {
            _cameraObject->rotateX(5.0_degf);
        } else if(event.key() == Platform::Application::Key::W) {
            _cameraObject->rotateX(-5.0_degf);
        } else if(event.key() == Platform::Application::Key::A) {
            _cameraRig->rotateY(-5.0_degf);
        } else if(event.key() == Platform::Application::Key::D) {
            _cameraRig->rotateY(5.0_degf);
        } else if(event.key() == Platform::Application::Key::Q) {
            // Move forward
            _cameraRig->translate(_cameraRig->transformation().backward() * -1);
        } else if(event.key() == Platform::Application::Key::E) {
            // Move backward
            _cameraRig->translate(_cameraRig->transformation().backward());
        } else b = false;

        return b;
    }

    Object3D* GetCameraObject() { return _cameraObject; }
private:
    Object3D* _cameraRig;
    Object3D* _cameraObject;
    SceneGraph::Camera3D* _camera;
};



#endif //CAMERAMANAGER_H
