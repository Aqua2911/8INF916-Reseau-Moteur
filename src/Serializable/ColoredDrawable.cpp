//
// Created by grave on 2025-04-10.
//

#include "ColoredDrawable.h"


std::vector<char> ColoredDrawable::serialize() const
{
    std::vector<char> buffer;

    // Serialize each part correctly
    std::vector<char> matrix4_buffer = Serializable::serializeMatrix4(_primitiveTransformation);
    std::vector<char> color_buffer = Serializable::serializeColor3(_color);

    buffer.insert(buffer.end(), matrix4_buffer.begin(), matrix4_buffer.end());
    buffer.insert(buffer.end(), color_buffer.begin(), color_buffer.end());

    return buffer;
}

/*
void ColoredDrawable::deserialize() {
}
*/