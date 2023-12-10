#pragma once
#include <cmath>

#define M_PI 3.14159265358979323846

class Vector2 {
public:
	float x;
	float y;
	Vector2(float X, float Y) : x(X), y(Y) {}
	static float Distance(Vector2 a, Vector2 b) {
		float deltaX = b.x - a.x;
		float deltaY = b.y - a.y;
		return sqrt(deltaX * deltaX + deltaY * deltaY);
	}
	static Vector2 Direction(float angle) {
		float radians = angle * (M_PI / 180);
		return Vector2(cos(radians), sin(radians));
	}

	Vector2 operator*(float scalar) const {
		return Vector2(x * scalar, y * scalar);
	}
};
