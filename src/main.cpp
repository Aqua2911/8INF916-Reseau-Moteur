#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Platform/GlfwApplication.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>
#include <Magnum/SceneGraph/Scene.h>
#include <Magnum/Trade/MeshData.h>
#include <Magnum/Primitives/Cube.h>
#include <Magnum/MeshTools/Compile.h>
#include <Magnum/GL/Mesh.h>

#include "Magnum/SceneGraph/Camera.h"

using namespace Magnum;

class MyApplication: public Platform::Application {
    public:
        explicit MyApplication(const Arguments& arguments);

    private:
        void drawEvent() override;
        void keyPressEvent(KeyEvent& event) override;
        void pointerPressEvent(PointerEvent& event) override;

        SceneGraph::Scene<SceneGraph::MatrixTransformation3D> _scene;
        SceneGraph::Object<SceneGraph::MatrixTransformation3D> _cameraObject;
        SceneGraph::Camera3D* _camera{};

        GL::Mesh _cubeMesh;
        std::vector<SceneGraph::Object<SceneGraph::MatrixTransformation3D>> _cubes;

        void setupScene();
};

MyApplication::MyApplication(const Arguments& arguments):
    Platform::Application{arguments, Configuration{}.setTitle("Bullet Test")}
{
    setupScene();
}

void MyApplication::drawEvent() {
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color | GL::FramebufferClear::Depth);


    for (auto& cube : _cubes) {
        // Rendu des cubes (ici, un simple rendu de debug, il faudra un shader plus tard)
        //_cubeMesh.draw();
    }

    swapBuffers();
    redraw();
}


void MyApplication::keyPressEvent(KeyEvent &event) {
    // Déplacement de la caméra avec WASD/QE
    if (event.key() == Key::W) _cameraObject.translate(Vector3::zAxis(-0.1f));
    if (event.key() == Key::S) _cameraObject.translate(Vector3::zAxis(0.1f));
    if (event.key() == Key::A) _cameraObject.translate(Vector3::xAxis(-0.1f));
    if (event.key() == Key::D) _cameraObject.translate(Vector3::xAxis(0.1f));
    if (event.key() == Key::Q) _cameraObject.translate(Vector3::yAxis(-0.1f));
    if (event.key() == Key::E) _cameraObject.translate(Vector3::yAxis(0.1f));

    redraw();
}

void MyApplication::pointerPressEvent(PointerEvent& event) {
    if (event.pointer() == Pointer::MouseLeft) {
        Debug{} << "Click détecté ! Tir d'une sphère à implémenter...";
        // TODO: Ajouter la gestion de la sphère qui est tirée
    }
}


void MyApplication::setupScene() {
    // Charger le maillage du cube
    _cubeMesh = MeshTools::compile(Primitives::cubeSolid());

    // Placer le sol (un grand cube aplati)
    auto& floor = _scene.addChild<SceneGraph::Object<SceneGraph::MatrixTransformation3D>>();
    floor.translate(Vector3{0.0f, -0.5f, 0.0f}).scale(Vector3{10.0f, 0.1f, 10.0f});


    // Générer une grille de cubes 10x10
    for (int x = 0; x < 10; ++x) {
        for (int z = 0; z < 10; ++z) {
            auto& cube = _scene.addChild<SceneGraph::Object<SceneGraph::MatrixTransformation3D>>();
            cube.translate(Vector3{float(x) - 4.5f, 0.0f, float(z) - 4.5f});
            //_cubes.push_back(std::move(cube));
        }
    }


    // Configurer la caméra
    _cameraObject.translate(Vector3{0.0f, 2.0f, 10.0f});
    _camera = new SceneGraph::Camera3D{_cameraObject};
    _camera->setProjectionMatrix(Matrix4::perspectiveProjection(
    Rad{Deg{45.0f}}, // Conversion explicite
    1.0f, 0.1f, 100.0f
));
}

MAGNUM_APPLICATION_MAIN(MyApplication)
