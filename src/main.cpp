#include <core/core.hpp>
#include <cmath>

using namespace core;
using namespace core::math;

std::vector<float> vertexes = {
//   x  y  z  r  g  b
	-1, 1, 0, 1, 0, 0, // 0
	-1,-1, 0, 0, 1, 0, // 1
	 1,-1, 0, 0, 0, 1, // 2
	 1, 1, 0, 1, 1, 0  // 3
};

std::vector<unsigned int> indexes = { 0, 1, 2, 0, 2, 3 };

int main()
{
	try
	{
		Core::init();
		// ваш код
	}
	catch (...)
	{
		Core::Terminate();
		return -1;
	}

	Core::Terminate();
	return 0;
}
