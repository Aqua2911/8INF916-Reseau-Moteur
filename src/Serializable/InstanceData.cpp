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
        std::vector<char> matrix3_x3_buffer = Serializable::serializeMatrix3x3(normalMatrix);
        std::vector<char> color_buffer = Serializable::serializeColor3(color);

        // Write the serialized data to the file
        out.write(matrix4_buffer.data(), matrix4_buffer.size());  // Write Matrix4
        out.write(matrix3_x3_buffer.data(), matrix3_x3_buffer.size());  // Write Matrix3x3
        out.write(color_buffer.data(), color_buffer.size());  // Write Color3

        out.close();
    } else {
        std::cerr << "Failed to open file for serialization!" << std::endl;
    }
}

void InstanceData::deserialize(std::streampos position) {
    std::ifstream in("serialized.txt", std::ios::binary);
    in.seekg(position);
    if (in.is_open()) {
        Matrix4 updatedMatrix;
        Matrix3x3 updatedNormalMatrix;
        Color3 updatedColor;
        in.read(reinterpret_cast<char*>(&updatedMatrix), sizeof(updatedMatrix));
        in.read(reinterpret_cast<char*>(&updatedNormalMatrix), sizeof(updatedNormalMatrix));
        in.read(reinterpret_cast<char*>(&updatedColor), sizeof(updatedColor));
        in.close();

        if (updatedMatrix != transformationMatrix)
            std::cerr << "not equal" << std::endl;
    } else {
        std::cerr << "Failed to open file for deserialization!" << std::endl;
    }
}