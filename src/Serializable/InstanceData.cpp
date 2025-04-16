//
// Created by grave on 2025-04-10.
//

#include "InstanceData.h"

#include <iostream>


void InstanceData::serialize() const {
    std::ofstream out("serialized.txt", std::ios::app | std::ios::binary);
    if (out.is_open()) {
        // Serialize each part correctly
        std::vector<char> matrix4_buffer = Serializable::serializeMatrix4(transformationMatrix);
        //std::string matrix3_x3_string = Serializable::serializeMatrix3x3(normalMatrix);
        //std::string color_string = Serializable::serializeColor3(color);

        // Write the serialized data to the file
        out.write(matrix4_buffer.data(), matrix4_buffer.size());  // Write Matrix4
        //out.write(matrix3_x3_string.data(), matrix3_x3_string.size());  // Write Matrix3x3
        //out.write(color_string.data(), color_string.size());  // Write Color3

        out.close();
    } else {
        std::cerr << "Failed to open file for serialization!" << std::endl;
    }
}

void InstanceData::deserialize(std::streampos position) {
    std::ifstream in("serialized.txt", std::ios::binary);
    in.seekg(position);
    if (in.is_open()) {
        Matrix4 matrix;
        in.read(reinterpret_cast<char*>(&matrix), sizeof(matrix));
        in.close();

        if (matrix == transformationMatrix)
            std::cerr << "equal" << std::endl;
        else
            std::cerr << "not equal" << std::endl;
    } else {
        std::cerr << "Failed to open file for deserialization!" << std::endl;
    }
}