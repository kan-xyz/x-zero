#pragma once

#include "x0/config.hpp"
#include "x0/meta/meta_types.hpp"
#include <random>

namespace x0 {

	template <typename T>
	using UniformDist = TypeSelect_t<std::uniform_int_distribution<T>, std::uniform_real_distribution<T>, std::is_integral_v<T>>;

	template <typename T>
	using GaussianDist = std::normal_distribution<T>;

	using BernoulliDist = std::bernoulli_distribution;

	template <class Eng>
	class BasicRandomGenerator {
	public:

		using engine_type = Eng;
		using result_type = typename engine_type::result_type;

	public:

		BasicRandomGenerator() : m_engine(std::random_device{}()) {}

		void seed(const result_type& seed_val) {
			m_engine.seed(seed_val);
		}

		void init() {
			seed(std::random_device{}());
		}

		template <class Dist, typename ...A>
		typename Dist::result_type random(A&& ...args) {
			return Dist{ std::forward<A>(args)... }(m_engine);
		}

		engine_type& getEngine() {
			return m_engine;
		}

	private:
		engine_type m_engine;
	};

	using RandomGenerator = BasicRandomGenerator<std::mt19937>;

}
