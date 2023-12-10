#pragma once
#include "Weights.h"

class Net {
public: 
	Net();
	float Compute(float i1, float i2);
	void Train(float i1, float i2, float expectedOutput, float learingRate);
	Weights w;
};