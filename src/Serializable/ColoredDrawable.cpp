//
// Created by grave on 2025-04-10.
//

#include "ColoredDrawable.h"



void ColoredDrawable::serialize(std::ostream &out) const {
  Serializable::serializeColor3(_color);
  Serializable::serializeMatrix4(_primitiveTransformation);
}

void ColoredDrawable::deserialize(std::istream &in) {
}