//
// Created by grave on 2025-04-22.
//

#ifndef OBJECTDATA_H
#define OBJECTDATA_H

//#include "Rigidbody.h"
#include "ColoredDrawable.h"

enum DataType {
  DataType_Cube = 0,
  DataType_Ground = 1,
  DataType_Sphere = 3,
  DataType_Camera = 4,
  DataType_None = 5
};

class ClientObjectData{
  public:
    int ID;
    DataType type;
    Matrix4 _transform;
    Matrix4 _primitiveTransform;
    Color3 _color;

    ClientObjectData();
};

class ObjectData{
public:
  int ID;
  DataType type;
  Object3D* object;
  //RigidBody* rb;
  ColoredDrawable* cd;

  ObjectData(DataType type, Object3D* object, /*RigidBody* rb,*/ ColoredDrawable* cd);

  std::vector<char> serialize();

  static inline int nextID = 0;

  // Static method declaration (no 'inline' needed here)
  static ClientObjectData deserialize(const char* data, size_t size, size_t& offset);
};


#endif //OBJECTDATA_H
