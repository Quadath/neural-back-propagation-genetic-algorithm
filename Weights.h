#pragma once

class Weights {
public: 
	Weights();
	void Randomize();
	Weights Mutation(Weights w);
	float i1_h1 = 0;
	float i2_h1 = 0;
	float bias_h1 = 0;
	float i1_h2 = 0;
	float i2_h2 = 0;
	float bias_h2 = 0;
	float i1_h3 = 0;
	float i2_h3 = 0;
	float bias_h3 = 0;
	float i1_h4 = 0;
	float i2_h4 = 0;
	float bias_h4 = 0;
	float i1_h5 = 0;
	float i2_h5 = 0;
	float bias_h5 = 0;
	float h1_o1 = 0;
	float h2_o1 = 0;
	float h3_o1 = 0;
	float h4_o1 = 0;
	float h5_o1 = 0;
	float bias_o1 = 0;
};