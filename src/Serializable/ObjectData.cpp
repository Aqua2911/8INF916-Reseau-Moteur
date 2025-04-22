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