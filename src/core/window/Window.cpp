#include "Window.hpp"
#include "Event.hpp"
#include "Cursor.hpp"
#include "../file/png.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace core;

extern bool coreInfo;

bool Window::flagGLewInit = true;

void Window::Init()
{
	this->event = new Event(*this->window);
	this->cursor = new Cursor(*this->window);
}

inline void Window::getSizeWindow()
{
	glfwGetWindowSize(this->window, &this->width, &this->height);
}

GLFWwindow* Window::getGlfwWindowObject()
{
	return this->window;
}

Window::Window(int width, int height, const char* title, bool resizable) : 
	width(width), height(height)
{
	glfwWindowHint(GLFW_RESIZABLE, resizable);
	this->window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (this->window == nullptr)
	{
		std::cerr << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		throw "FAILED_CREATE_WINDOW";
	}

	if (coreInfo)
	{
		std::cout << "[" << glfwGetTime() << "] " << "OK: to create GLFW Window" << std::endl;
	}

	this->Init();
}	
	
Window::~Window()
{
	delete this->cursor;
	delete this->event;
	glfwDestroyWindow(this->window);
}

void Window::swapBuffers()
{
	if (this->VSfps)
	{
		if (glfwGetTime() - time >= 1.0 / (double)this->FPS)
		{
			glfwSwapBuffers(this->window);
			this->time = glfwGetTime();
		}
	}
	else
	{
		glfwSwapBuffers(this->window);
	}

	this->getSizeWindow();
}

void Window::setIcon(const char* path)
{
	GLFWimage images[1] = { };

	unsigned char* img = png::load(path);

	images[0].width = png::width;
	images[0].height = png::height;
	images[0].pixels = img;

	glfwSetWindowIcon(this->window, 1, images);
	free(images[0].pixels);
}

void Window::close()
{
	glfwSetWindowShouldClose(this->window, true);
}

void Window::setContext()
{
	glfwMakeContextCurrent(this->window);

	if (Window::flagGLewInit)
	{
		glewExperimental = GL_TRUE;
		GLenum glewErr = glewInit();
		if (glewErr != GLEW_OK)
		{
			if (glewErr == GLEW_ERROR_NO_GLX_DISPLAY)
			{
				std::cerr << "Failed initializate GLEW error 240" << std::endl;
			}
			else
			{
				std::cerr << "Failed initializate GLEW" << std::endl;
			}
			throw "FAILED_INIT_GLEW";
		}

		Window::flagGLewInit = false;
	}

	glfwSwapInterval(0);
}

void Window::setSizeBuffer(int width, int height)
{
	glViewport(0, 0, width, height);
}

bool Window::isContext()
{
	if (this->window == glfwGetCurrentContext())
	{
		return true;
	}
	return false;
}

void Window::VerticalSynchronization(bool flag)
{
	this->VSfps = flag;
}

void core::Window::setMaxFPS(unsigned int fps)
{
	this->FPS = fps;
}
