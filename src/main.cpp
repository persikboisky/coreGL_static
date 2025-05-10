#include <core/core.hpp>

using namespace core;
using namespace core::math;

std::vector<float> vertexes{
	-0.05, 0.05, 1, 0,
	-0.05,-0.05, 1, 1,
	 0.05,-0.05, 0, 1,
	 0.05, 0.05, 0, 0
};

std::vector<unsigned int> indexes{0, 1, 2, 3};


int main()
{
	try
	{
		Core::Init();

		Window window = Window(1280, 720, "test");
		window.setMaxFPS(75);
		window.setContext();

		fbo::DepthTest(true);
		fbo::setColor(RGBA(0, 0, 0, 255));

		Turtle turtle = Turtle(window);

		double time = 0;

		while (!window.event->close())
		{
			window.event->update();

			turtle.enableDrawBody(false);
			if (Core::GetTime() >= time + 0.01)
			{
				time = Core::GetTime();
				turtle.setColor(RGB(255, 0, 255));
				turtle.setWidth(10);
				turtle.move();
				turtle.setAngle(Core::GetTime() * 20);
			}

			turtle.draw();

			window.swapBuffers();
			fbo::clearBuffers(COLOR_BUFFER, DEPTH_BUFFER);
		}

		turtle.clear();
	}
	catch (...)
	{
		Core::Terminate();
		return -1;
	}

	Core::Terminate();
	return 0;
}