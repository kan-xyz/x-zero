#pragma once

#include "x0/config.hpp"
#include <type_traits>

namespace x0 {

	namespace priv {

		template <typename T, typename F, bool S>
		struct TypeSelect_t;

		template <typename T, typename F>
		struct TypeSelect_t<T, F, true> {
			using type = T;
		};

		template <typename T, typename F>
		struct TypeSelect_t<T, F, false> {
			using type = F;
		};

	}

	template <typename T, typename F, bool S>
	using TypeSelect_t = typename priv::TypeSelect_t<T, F, S>::type;

}
