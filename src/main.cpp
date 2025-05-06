#include <core/core.hpp>

using namespace core;
using namespace core::math;

int main()
{
	try
	{
		Core::Init();
		Window window = Window(1280, 720, "test");
	}
	catch (...)
	{
		Core::Terminate();
		return -1;
	}

	Core::Terminate();
	return 0;
}