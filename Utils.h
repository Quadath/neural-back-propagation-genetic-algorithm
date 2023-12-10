#pragma once
#include <random>

static float Random(float min, float max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(min, max);
	return dist(gen);
}