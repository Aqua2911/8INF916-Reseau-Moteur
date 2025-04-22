//
// Created by grave on 2025-04-22.
//

#include "ObjectData.h"

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

  // 3. Serialize Object3D transform (Matrix4)
  if (object) {
    std::vector<char> transform = this->object->serializeTransform();
    buffer.insert(buffer.end(), reinterpret_cast<const char*>(&transform), reinterpret_cast<const char*>(&transform) + sizeof(Matrix4));
  }

  // 4. Serialize ColoredDrawable color and primitive transform
  if (cd) {
    // Color3: 3 floats
    std::vector<char> cdb = this->cd->serialize();
    buffer.insert(buffer.end(), reinterpret_cast<const char*>(&cdb), reinterpret_cast<const char*>(&cdb) + sizeof(Color3));
  }

  return buffer;
}

/*
ObjectData ObjectData::deserialize(const char* data, size_t size, size_t& offset) {
  // 1. Deserialize ID
  int id;
  std::memcpy(&id, data + offset, sizeof(int));
  offset += sizeof(int);

  // 2. Deserialize DataType
  int typeInt;
  std::memcpy(&typeInt, data + offset, sizeof(int));
  offset += sizeof(int);
  DataType type = static_cast<DataType>(typeInt);

  // 3. Deserialize Matrix4 transform
  Matrix4 transform;
  std::memcpy(&transform, data + offset, sizeof(Matrix4));
  offset += sizeof(Matrix4);

  // 4. Deserialize Color3
  Color3 color;
  std::memcpy(&color, data + offset, sizeof(Color3));
  offset += sizeof(Color3);

  // 5. Deserialize primitive transform
  Matrix4 primitiveTransform;
  std::memcpy(&primitiveTransform, data + offset, sizeof(Matrix4));
  offset += sizeof(Matrix4);

  // 6. Create dummy object, you’ll reassign these later
  ObjectData obj(type, nullptr, nullptr);
  obj.ID = id;

  // We store deserialized data for now — the actual Object3D* and ColoredDrawable*
  // will be created later from this info in BulletClient::drawEvent()
  // You could add members to hold them temporarily if you want: deserializedTransform, deserializedColor, etc.

  // For now, let’s inject them directly if you want:
  obj.object = new Object3D();  // optionally pass parent
  obj.object->setTransformationMatrix(transform);

  obj.cd = new ColoredDrawable(*obj.object, primitiveTransform, color, _shader); // assuming _shader is available
  // This assumes ColoredDrawable has a constructor taking those args

  return obj;
}
*/