#include "math.hpp"

using namespace core;

float math::radians(float degrees)
{
	return PI / 180.0 * degrees;
}

float core::math::degrees(float radians)
{
	return 180.0 / PI * radians;
}
