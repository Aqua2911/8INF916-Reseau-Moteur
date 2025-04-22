//
// Created by grave on 2025-04-10.
//

#include "InstanceData.h"

#include <iostream>


std::vector<char> InstanceData::serialize() const {
    std::vector<char> buffer;
    std::ofstream out("serialized.txt", std::ios::app | std::ios::binary);
    if (out.is_open()) {
        // Serialize each part correctly
        std::vector<char> matrix4_buffer = Serializable::serializeMatrix4(transformationMatrix);
        std::vector<char> matrix3_x3_buffer = Serializable::serializeMatrix3x3(normalMatrix);
        std::vector<char> color_buffer = Serializable::serializeColor3(color);

        buffer.insert(buffer.end(), matrix4_buffer.begin(), matrix4_buffer.end());
        buffer.insert(buffer.end(), matrix3_x3_buffer.begin(), matrix3_x3_buffer.end());
        buffer.insert(buffer.end(), color_buffer.begin(), color_buffer.end());

        // Write the serialized data to the file
        out.write(matrix4_buffer.data(), matrix4_buffer.size());  // Write Matrix4
        out.write(matrix3_x3_buffer.data(), matrix3_x3_buffer.size());  // Write Matrix3x3
        out.write(color_buffer.data(), color_buffer.size());  // Write Color3

        out.close();
    } else {
        std::cerr << "Failed to open file for serialization!" << std::endl;
    }

    return buffer;
}

InstanceData InstanceData::deserialize(std::streampos position) {
    InstanceData iData;
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
        iData = InstanceData(updatedMatrix, updatedNormalMatrix, updatedColor);

        if (updatedMatrix != transformationMatrix)
            std::cerr << "not equal" << std::endl;
    } else {
        std::cerr << "Failed to open file for deserialization!" << std::endl;
    }

    return iData;
}

InstanceData InstanceData::deserialize(const char *buffer, int &offset) {
    Matrix4 updatedTransformationMatrix = Serializable::deserializeMatrix4(buffer, offset);
    Matrix3x3  updatedNormalMatrix = Serializable::deserializeMatrix3x3(buffer, offset);
    Color3 updatedColor = Serializable::deserializeColor3(buffer, offset);
    return InstanceData(updatedTransformationMatrix, updatedNormalMatrix, updatedColor);
}
