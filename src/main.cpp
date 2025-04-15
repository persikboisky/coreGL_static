#include <core/core.hpp>

int n = 0;
static void print()
{
	n++;
	std::cout << n << std::endl;
}

int main()
{
	try
	{
		core::Init();
		Window window(1280, 720);
		window.setContext();

		fbo::DepthTest(true);
		fbo::setColor(0, 0, 0, 1);

		font fontS = font();
		GUI gui(window, fontS);

		GUIstyle style;
		style.pos = position_2f(0.1, 0.1);
		style.size = size_2f(0.1, 0.1);
		style.background = color_rgba(255, 200, 200, 255);
		style.activeBackground = color_rgba(255, 200, 200, 100);
		style.hover = true;
		style.hoverBackground = color_rgba(255, 200, 200, 200);

		gui.button->add(style, print);

		while (!window.event->close())
		{
			window.event->update();

			gui.render();
			window.swapBuffers();
			fbo::clearBuffers(COLOR_BUFFER, DEPTH_BUFFER);
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