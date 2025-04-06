//
// Created by grave on 2025-04-02.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <Magnum/BulletIntegration/DebugDraw.h>
#include <Magnum/Math/Color.h>
#include <Magnum/MeshTools/Compile.h>
#include <Magnum/Primitives/Cube.h>
#include <Magnum/Primitives/UVSphere.h>
#include <Magnum/Shaders/PhongGL.h>
#include <Magnum/Trade/MeshData.h>

using namespace Magnum;

using namespace Math::Literals;

class Renderer {
public:
    Renderer()= default;

    void Initialize() {
        _shader = Shaders::PhongGL{Shaders::PhongGL::Configuration{}
            .setFlags(Shaders::PhongGL::Flag::VertexColor |
                      Shaders::PhongGL::Flag::InstancedTransformation)};
        _shader.setAmbientColor(0x111111_rgbf)
               .setSpecularColor(0x330000_rgbf)
               .setLightPositions({{10.0f, 15.0f, 5.0f, 0.0f}});

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
    }

    void render(Magnum::SceneGraph::Camera3D* camera,
                Magnum::SceneGraph::DrawableGroup3D& drawables) {
        using namespace Magnum;

        GL::defaultFramebuffer.clear(GL::FramebufferClear::Color | GL::FramebufferClear::Depth);

        camera->draw(drawables);
    }

    btCollisionShape* GetSphereShape(){return &_sphereShape;}
    Containers::Array<InstanceData>& GetSphereInstanceData() {
        return _sphereInstanceData;
    }

private:
    Containers::Array<InstanceData> _sphereInstanceData;
    Shaders::PhongGL _shader;
    GL::Mesh _box, _sphere;
    GL::Buffer _boxInstanceBuffer, _sphereInstanceBuffer;

    btSphereShape _sphereShape{0.25f};
};

#endif //RENDERER_H
