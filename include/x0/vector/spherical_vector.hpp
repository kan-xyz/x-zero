#pragma once

namespace x0 {

	template <typename T>
	class SphericalVector {
	public:

		using value_type = T;

	public:

		SphericalVector() = default;

	public:
		value_type radius = 0; // radius of the sphere
		value_type theta = 0; // azimuthal angle - the angle in radians rotated from +x-axis towards +y-axis
		value_type phi = 0; // polar angle - the angle in radians directed from +z-axis to the radius vector
	};

}
