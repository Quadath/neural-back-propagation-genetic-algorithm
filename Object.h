#pragma once

class Object {
public:
	Object(float X, float Y);
	virtual void Move(float x, float y);
	float x, y;
};