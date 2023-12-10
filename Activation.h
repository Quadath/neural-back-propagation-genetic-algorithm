#pragma once
#include <cmath>

static float sigmoid(float x) {
    return 1.0f / (1.0f + std::exp(-x));
}

float sigmoidDerivative(float x) {
    float sigmoid_x = sigmoid(x);
    return sigmoid_x * (1.0f - sigmoid_x);
}