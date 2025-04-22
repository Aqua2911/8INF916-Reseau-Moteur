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
    //static ObjectData deserialize(const char* data, size_t size, size_t& offset);

    static inline int nextID = 0;
};


#endif //OBJECTDATA_H
