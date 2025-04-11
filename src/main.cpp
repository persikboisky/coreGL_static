#include "core/core.hpp"

int main()
{
	try
	{
		core::Init();
		Window window("Test", 1280, 720);
		window.setContext();

		while (!window.event->close())
		{
			window.event->update();
			window.swapBuffers();
			window.setSizeBuffer(window.width, window.height);
		}
	}
	catch (...)
	{
		core::Terminate();
		return -1;
	}

	core::Terminate();
	return 0;
}