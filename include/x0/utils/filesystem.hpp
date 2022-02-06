#pragma once

#include <filesystem>

namespace x0 {

	template <typename C>
	std::basic_string<C> getCurrentPath() {
		if constexpr (std::is_same_v<C, char>) {
			return std::filesystem::current_path().string();
		}
		else if constexpr (std::is_same_v<C, wchar_t>) {
			return std::filesystem::current_path().wstring();
		}
		else if constexpr (std::is_same_v<C, char8_t>) {
			return std::filesystem::current_path().u8string();
		}
		else if constexpr (std::is_same_v<C, char16_t>) {
			return std::filesystem::current_path().u16string();
		}
		else if constexpr (std::is_same_v<C, char32_t>) {
			return std::filesystem::current_path().u32string();
		}
	}

}
