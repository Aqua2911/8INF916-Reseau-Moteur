﻿//
// Created by grave on 2025-04-10.
//

#ifndef COLOREDDRAWABLE_H
#define COLOREDDRAWABLE_H

#include <Corrade/Containers/GrowableArray.h>
#include <Magnum/SceneGraph/Drawable.h>

#include "Object3D.h"
#include "InstanceData.h"

using namespace Magnum;


class ColoredDrawable: public SceneGraph::Drawable3D /*, Serializable*/ {
public:
    explicit ColoredDrawable(Object3D& object, Containers::Array<InstanceData>& instanceData, const Color3& color, const Matrix4& primitiveTransformation, SceneGraph::DrawableGroup3D& drawables): SceneGraph::Drawable3D{object, &drawables}, _instanceData(instanceData), _color{color}, _primitiveTransformation{primitiveTransformation} {}

private:
    void draw(const Matrix4& transformation, SceneGraph::Camera3D&) override {
        const Matrix4 t = transformation*_primitiveTransformation;
        arrayAppend(_instanceData, InPlaceInit, t, t.normalMatrix(), _color);
    }

    //void serialize() const override;
    //void deserialize() override;

    Containers::Array<InstanceData>& _instanceData;
    Color3 _color;
    Matrix4 _primitiveTransformation;
};


#endif //COLOREDDRAWABLE_H
