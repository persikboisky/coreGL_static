#ifndef SRC_CORE_WINDOW_WINDOW_HPP_
#define SRC_CORE_WINDOW_WINDOW_HPP_

#include "Event.hpp"
#include "Cursor.hpp"

struct GLFWwindow;

class Window
{
private:
	GLFWwindow* window = nullptr;

	static bool flagGLewInit;

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

	Event* event = nullptr;
	Cursor* cursor = nullptr;

	int width;
	int height;

	Window(int width, int height, const char* title = "", bool resizable = true);
	~Window();

	void swapBuffers();
	void setIcon(const char* path);
	void close();
	void setContext();
	void setSizeBuffer(int width, int height);

	bool isContext();
};

#endif // !SRC_CORE_WINDOW_WINDOW_HPP_