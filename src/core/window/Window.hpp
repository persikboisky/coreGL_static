#ifndef SRC_CORE_WINDOW_WINDOW_HPP_
#define SRC_CORE_WINDOW_WINDOW_HPP_

#include "Event.hpp"
#include "Cursor.hpp"

struct GLFWwindow;

class Window
{
private:
	GLFWwindow* window;

	void Init()
	{
		this->event = new Event(*this->window);
		this->cursor = new Cursor(*this->window);
	}
	void getSizeWindow();

public:

	GLFWwindow* getGlfwWindowObject()
	{
		return this->window;
	}

	Event* event;
	Cursor* cursor;

	int width;
	int height;

	Window(const char* title, int width, int height, bool resizable = true);
	~Window();

	void swapBuffers();
	void setIcon(const char* path);
	void close();
	void setContext();
	void setSizeBuffer(int width, int height);

	bool isContext();
};

#endif // !SRC_CORE_WINDOW_WINDOW_HPP_