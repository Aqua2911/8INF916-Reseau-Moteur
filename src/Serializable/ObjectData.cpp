//
// Created by grave on 2025-04-22.
//

#include "ObjectData.h"

ClientObjectData::ClientObjectData() {
  ID = -1;
  type = DataType_None;
  _transform = Matrix4();
  _primitiveTransform = Matrix4();
  _color = Color3();
}


ObjectData::ObjectData(DataType type, Object3D* object, /*RigidBody* rb,*/ ColoredDrawable* cd){
  ID = ObjectData::nextID++;
  this->type = type;
  this->object = object;
  //this->rb = rb;
  this->cd = cd;
};

std::vector<char> ObjectData::serialize() {
  std::vector<char> buffer;

  // 1. Serialize ID
  buffer.insert(buffer.end(), reinterpret_cast<char*>(&ID), reinterpret_cast<char*>(&ID) + sizeof(ID));

  // 2. Serialize DataType
  int typeInt = static_cast<int>(type);
  buffer.insert(buffer.end(), reinterpret_cast<char*>(&typeInt), reinterpret_cast<char*>(&typeInt) + sizeof(int));

  // 3. Serialize Object3D transform
  if (object) {
    std::vector<char> transform = this->object->serializeTransform();
    buffer.insert(buffer.end(), transform.begin(), transform.end());
  } else {
    // If object missing, write identity matrix
    Matrix4 identity;
    std::memset(&identity, 0, sizeof(Matrix4));
    buffer.insert(buffer.end(), reinterpret_cast<const char*>(&identity), reinterpret_cast<const char*>(&identity) + sizeof(Matrix4));
  }

  // 4. Serialize ColoredDrawable
  if (cd) {
    //Debug{} << "cube Color:" << this->cd->_color;
    std::vector<char> cdb = this->cd->serialize();
    buffer.insert(buffer.end(), cdb.begin(), cdb.end());
  } else {
    // Write dummy data for primitiveTransform and color
    Matrix4 dummyMatrix;
    std::memset(&dummyMatrix, 0, sizeof(Matrix4));
    buffer.insert(buffer.end(), reinterpret_cast<const char*>(&dummyMatrix), reinterpret_cast<const char*>(&dummyMatrix) + sizeof(Matrix4));

    Color3 dummyColor;
    std::memset(&dummyColor, 0, sizeof(Color3));
    buffer.insert(buffer.end(), reinterpret_cast<const char*>(&dummyColor), reinterpret_cast<const char*>(&dummyColor) + sizeof(Color3));
  }

  return buffer;
}


ClientObjectData ObjectData::deserialize(const char* data, size_t size, size_t& offset) {
  ClientObjectData* obj = new ClientObjectData();

  // 1. Deserialize ID
  int id;
  std::memcpy(&id, data + offset, sizeof(int));
  offset += sizeof(int);

  obj->ID = id;

  // 2. Deserialize DataType
  int typeInt;
  std::memcpy(&typeInt, data + offset, sizeof(int));
  offset += sizeof(int);
  DataType type = static_cast<DataType>(typeInt);

  obj->type = type;

  // 3. Deserialize Matrix4 transform
  Matrix4 transform;
  std::memcpy(&transform, data + offset, sizeof(Matrix4));
  offset += sizeof(Matrix4);

  obj->_transform = transform;



  if (type != DataType_Camera)
  {
      // 5. Deserialize primitive transform
      Matrix4 primitiveTransform;
      std::memcpy(&primitiveTransform, data + offset, sizeof(Matrix4));
      offset += sizeof(Matrix4);

      obj->_primitiveTransform = primitiveTransform;

      Color3 color;
      std::memcpy(&color, data + offset, sizeof(Color3));
      offset += sizeof(Color3);

      obj->_color = color;
      //Debug{} << "cube Color:" << color;

      // We store deserialized data for now — the actual Object3D* and ColoredDrawable*
      // will be created later from this info in BulletClient::drawEvent()
      // You could add members to hold them temporarily if you want: deserializedTransform, deserializedColor, etc.

      // For now, let’s inject them directly if you want:
      //obj.object = new Object3D();  // optionally pass parent
      //obj.object->setTransformationMatrix(transform);

      //obj.cd = new ColoredDrawable(*obj.object, primitiveTransform, color, _shader); // assuming _shader is available
      // This assumes ColoredDrawable has a constructor taking those args
  }

  return *obj;
}