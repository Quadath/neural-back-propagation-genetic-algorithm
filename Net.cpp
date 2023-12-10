#include <vector>
#include "Net.h"
#include "Activation.h"


Net::Net() : w() { w.Randomize(); };

float Net::Compute(float i1, float i2) {
	float h1_input = w.i1_h1 * i1 +
		w.i2_h1 * i2 +
		w.bias_h1;
	float h1 = sigmoid(h1_input);

	float h2_input = w.i1_h2 * i1 +
		w.i2_h2 * i2 +
		w.bias_h2;
	float h2 = sigmoid(h2_input);

	float h3_input = w.i1_h3 * i1 +
		w.i2_h3 * i2 +
		w.bias_h3;
	float h3 = sigmoid(h3_input);

	float h4_input = w.i1_h4 * i1 +
		w.i2_h4 * i2 +
		w.bias_h4;
	float h4 = sigmoid(h4_input);

	float h5_input = w.i1_h5 * i1 +
		w.i2_h5 * i2 +
		w.bias_h5;
	float h5 = sigmoid(h5_input);

	float o1_input =
		w.h1_o1 * h1 +
		w.h2_o1 * h2 +
		w.h3_o1 * h3 +
		w.h4_o1 * h4 +
		w.h5_o1 * h5 +
		w.bias_o1;

	float o1 = sigmoid(o1_input);

	return o1;
}

void Net::Train(float i1, float i2, float expectedOutput, float learingRate) {
	float o = 0;

	float i1_h1_delta = 0;
	float i2_h1_delta = 0;
	float bias_h1_delta = 0;
	float i1_h2_delta = 0;
	float i2_h2_delta = 0;
	float bias_h2_delta = 0;
	float i1_h3_delta = 0;
	float i2_h3_delta = 0;
	float bias_h3_delta = 0;
	float i1_h4_delta = 0;
	float i2_h4_delta = 0;
	float bias_h4_delta = 0;
	float i1_h5_delta = 0;
	float i2_h5_delta = 0;
	float bias_h5_delta = 0;
	float h1_o1_delta = 0;
	float h2_o1_delta = 0;
	float h3_o1_delta = 0;
	float h4_o1_delta = 0;
	float h5_o1_delta = 0;
	float bias_o1_delta = 0;

	float h1_input = w.i1_h1 * i1 +
		w.i2_h1 * i2 +
		w.bias_h1;
	float h1 = sigmoid(h1_input);

	float h2_input = w.i1_h2 * i1 +
		w.i2_h2 * i2 +
		w.bias_h2;
	float h2 = sigmoid(h2_input);

	float h3_input = w.i1_h3 * i1 +
		w.i2_h3 * i2 +
		w.bias_h3;
	float h3 = sigmoid(h3_input);

	float h4_input = w.i1_h4 * i1 +
		w.i2_h4 * i2 +
		w.bias_h4;
	float h4 = sigmoid(h4_input);

	float h5_input = w.i1_h5 * i1 +
		w.i2_h5 * i2 +
		w.bias_h5;
	float h5 = sigmoid(h5_input);

	float o1_input =
		w.h1_o1 * h1 +
		w.h2_o1 * h2 +
		w.h3_o1 * h3 +
		w.h4_o1 * h4 +
		w.h5_o1 * h5 +
		w.bias_o1;

	float o1 = sigmoid(o1_input);

	float o1_error = expectedOutput - o1;
	float o1_delta = o1_error * sigmoidDerivative(o1_input);

	h1_o1_delta = h1 * o1_delta;
	h2_o1_delta = h2 * o1_delta;
	h3_o1_delta = h3 * o1_delta;
	h4_o1_delta = h4 * o1_delta;
	h5_o1_delta = h5 * o1_delta;
	bias_o1_delta += o1_delta;

	float h1_delta = w.h1_o1 * o1_delta * sigmoidDerivative(h1_input);
	float h2_delta = w.h2_o1 * o1_delta * sigmoidDerivative(h2_input);
	float h3_delta = w.h3_o1 * o1_delta * sigmoidDerivative(h3_input);
	float h4_delta = w.h4_o1 * o1_delta * sigmoidDerivative(h4_input);
	float h5_delta = w.h5_o1 * o1_delta * sigmoidDerivative(h5_input);

	i1_h1_delta = i1 * h1_delta;
	i2_h1_delta = i2 * h1_delta;
	bias_h1_delta = h1_delta;

	i1_h2_delta = i1 * h2_delta;
	i2_h2_delta = i2 * h2_delta;
	bias_h2_delta = h2_delta;

	i1_h3_delta = i1 * h3_delta;
	i2_h3_delta = i2 * h3_delta;
	bias_h3_delta = h3_delta;

	i1_h4_delta = i1 * h4_delta;
	i2_h4_delta = i2 * h4_delta;
	bias_h4_delta = h4_delta;

	i1_h5_delta = i1 * h5_delta;
	i2_h5_delta = i2 * h5_delta;
	bias_h5_delta = h5_delta;

	w.i1_h1 += i1_h1_delta * learingRate;
	w.i2_h1 += i2_h1_delta * learingRate;
	w.bias_h1 += bias_h1_delta * learingRate;

	w.i1_h2 += i1_h2_delta * learingRate;
	w.i2_h2 += i2_h2_delta * learingRate;
	w.bias_h2 += bias_h2_delta * learingRate;

	w.i1_h3 += i1_h3_delta * learingRate;
	w.i2_h3 += i2_h3_delta * learingRate;
	w.bias_h3 += bias_h3_delta * learingRate;

	w.i1_h4 += i1_h4_delta * learingRate;
	w.i2_h4 += i2_h4_delta * learingRate;
	w.bias_h4 += bias_h4_delta * learingRate;

	w.i1_h5 += i1_h5_delta * learingRate;
	w.i2_h5 += i2_h5_delta * learingRate;
	w.bias_h5 += bias_h5_delta * learingRate;

	w.h1_o1 += h1_o1_delta * learingRate;
	w.h2_o1 += h2_o1_delta * learingRate;
	w.h3_o1 += h3_o1_delta * learingRate;
	w.h4_o1 += h4_o1_delta * learingRate;
	w.h5_o1 += h5_o1_delta * learingRate;
	w.bias_o1 += bias_o1_delta * learingRate;
}