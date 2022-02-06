#include "tests.hpp"
#include "x0/utils/random.hpp"
#include "x0/utils/timing.hpp"
#include <cstdio>

void x0_tests::rng_test() {

	x0::RandomGenerator rng;

	x0::Timer timer;
	const double p = 0.5;
	for (std::size_t i = 0; i < 1000; ++i) {
		std::printf("%f\t%f\t%d\n", 
			rng.random<x0::UniformDist<float>>(0.0f, 1.0f), 
			rng.random<x0::GaussianDist<float>>(10.0f, 2.0f), 
			rng.random<x0::BernoulliDist>(p));
	}
	std::printf("\nsequence generated in %f seconds\n", timer.getElapsedTime<x0::Seconds>());

}
