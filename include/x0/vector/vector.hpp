#pragma once

#include "x0/config.hpp"
#include <array>
#include <cstring>

namespace x0 {

	template <std::size_t D, typename T>
	class Vector {
	public:

		using value_type = T;
		using index_type = std::size_t;
		enum : index_type { dimensions = D };

	public:

		Vector() : m_data{ 0 } {}

		Vector(const std::array<value_type, dimensions>& raw_data) : m_data{ raw_data.m_data } {}

		Vector(const value_type* raw_data[dimensions]) {
			std::memcpy(m_data.data(), raw_data, sizeof(value_type) * dimensions);
		}

		template <typename U>
		Vector(const Vector<dimensions, U>& other) {
			for (std::size_t i = 0; i < dimensions; ++i) {
				m_data[i] = static_cast<T>(other[i]);
			}
		}

		value_type& operator [] (const index_type idx) {
			return m_data[idx];
		}

		const value_type& operator [] (const index_type idx) const {
			return m_data[idx];
		}

		Vector<dimensions, value_type> operator = (const Vector<dimensions, value_type>& other) {
			return m_data = other.m_data;
		}

		value_type* rawData() {
			return m_data.data();
		}

		const value_type* rawData() const {
			return m_data.data();
		}

		std::array<value_type, dimensions>& data() {
			return m_data;
		}

		const std::array<value_type, dimensions>& data() const {
			return m_data;
		}

	private:
		std::array<value_type, dimensions> m_data;
	};

	template <std::size_t D, typename T>
	bool operator == (const Vector<D, T>& a, const Vector<D, T>& b) {
		return a.data() == b.data();
	}

	template <std::size_t D, typename T>
	bool operator != (const Vector<D, T>& a, const Vector<D, T>& b) {
		return a.data() != b.data();
	}

}
