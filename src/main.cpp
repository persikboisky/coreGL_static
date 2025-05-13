#include <core/core.hpp>

using namespace core;
using namespace core::math;

int main()
{
	try
	{
		Core::Init();
		// ваш код...
	}
	catch (...)
	{
		Core::Terminate();
		return -1;
	}

	Core::Terminate();
	return 0;
}
