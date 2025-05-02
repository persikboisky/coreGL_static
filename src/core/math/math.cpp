#include "math.hpp"

constexpr double PI = 3.1415926535;

float math::radians(float degrees)
{
	return PI / 180.0 * degrees;
}