#ifndef SRC_CORE_WINDOW_WINDOW_HPP_
#define SRC_CORE_WINDOW_WINDOW_HPP_

struct GLFWwindow;

class Event;
class Cursor;

class Window
{
private:
	GLFWwindow* window = nullptr;

	static bool flagGLewInit;

	void Init();
	void getSizeWindow();

public:

	GLFWwindow* getGlfwWindowObject();

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