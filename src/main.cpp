#include <core/core.hpp>
#include <cmath>

using namespace core;
using namespace core::math;

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
