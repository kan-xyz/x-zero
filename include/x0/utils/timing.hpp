#pragma once

#include "x0/config.hpp"
#include <chrono>

namespace x0 {

	using SteadyClock = std::chrono::steady_clock;
	
	template <class Cl>
	using TimePoint = std::chrono::time_point<Cl>;

	using Seconds = std::chrono::duration<float, std::ratio<1, 1>>;

	template <class Cl>
	class BasicTimer {
	public:

		using clock_type = Cl;
		using time_point_type = TimePoint<clock_type>;

	public:

		BasicTimer() = default;

		void restart() {
			m_start_time = clock_type::now();
		}

		template <class Dur>
		typename Dur::rep getElapsedTime() {
			return std::chrono::duration_cast<Dur>(clock_type::now() - m_start_time).count();
		}

		const time_point_type& getStartTime() const {
			return m_start_time;
		}

	private:
		time_point_type m_start_time = clock_type::now();
	};

	using Timer = BasicTimer<SteadyClock>;

}
