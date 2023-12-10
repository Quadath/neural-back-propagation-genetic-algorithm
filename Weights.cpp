#include "Weights.h"
#include "Utils.h"

Weights::Weights() {};

void Weights::Randomize() {
	i1_h1 = Random(-1, 1);
	i2_h1 = Random(-1, 1);
	bias_h1 = Random(-1, 1);
	i1_h2 = Random(-1, 1);
	i2_h2 = Random(-1, 1);
	bias_h2 = Random(-1, 1);
	i1_h3 = Random(-1, 1);
	i2_h3 = Random(-1, 1);
	bias_h3 = Random(-1, 1);
	i1_h4 = Random(-1, 1);
	h1_o1 = Random(-1, 1);
	h2_o1 = Random(-1, 1);
	h3_o1 = Random(-1, 1);
	bias_o1 = Random(-1, 1);
}

Weights Weights::Mutation(Weights w) {
	Weights result;
	
	return result;
}