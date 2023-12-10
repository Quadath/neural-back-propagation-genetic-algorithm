#include "Object.h"
#include "Settings.h"

Object::Object(float X, float Y): x(X), y(Y) {}
void Object::Move(float dirX, float dirY) { x += dirX; y += dirY;}