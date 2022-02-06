#pragma once

namespace x0 {

	template <typename T>
	class CylindricalVector {
	public:

		using value_type = T;

	public:

		CylindricalVector() = default;

	public:
		value_type radius = 0; // radius on the xy plane
		value_type angle = 0; // rotation angle in radians going from +x-axis to +y-axis
		value_type height = 0; // height directed outwards of xy plane starting from the tip of the radial vector
	};

}
