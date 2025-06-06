#include "Event.hpp"
#include "Window.hpp"
#include "../util/type.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

using namespace core;

bool Key[MAX_KEY_CODE];

static void key_callbac(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		Key[key] = true;
	}
	else if (action == GLFW_RELEASE)
	{
		Key[key] = false;
	}
}

void Event::setCallbackKey(GLFWkeyfun callback)
{
	glfwSetKeyCallback(this->window, callback);

	for (unsigned int index = 0; index < MAX_KEY_CODE; index++)
	{
		this->key[index] = Key[index];
	}
}

Event::Event(GLFWwindow &addrWindow) : window(&addrWindow)
{
	this->setCallbackKey(key_callbac);
	//glfwSetKeyCallback(this->window, key_callbac);
	memset(this->saveKey, false, MAX_KEY_CODE);
}

Event::Event(Window& window) : window(window.getGlfwWindowObject())
{
	this->setCallbackKey(key_callbac);
	memset(this->saveKey, false, MAX_KEY_CODE);
}

Event::~Event()
{
	delete this->key;
	delete this->saveKey;
}

void Event::update()
{
	for (unsigned int index = 0; index < MAX_KEY_CODE; index++)
	{
		this->saveKey[index] = this->key[index];
	}
	this->setCallbackKey(key_callbac);
	glfwPollEvents();
}

bool Event::close()
{
	return glfwWindowShouldClose(this->window);
}

bool Event::GetMouseLeftButton()
{
	return glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_LEFT);
}

bool Event::GetMouseRightButton()
{
	return glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_RIGHT);
}

bool Event::stateKey(int key)
{
	if (key >= MAX_KEY_CODE || key < 0) std::cerr << "there is no such key in the buffer" << std::endl;

	else return this->key[key];
}

bool Event::stateKey(KEY_CODE key)
{
	return this->stateKey(convertKeyCode(key));
}

bool Event::downKey(int key)
{
	if (this->key[key] > this->saveKey[key])
	{
		return true;
	}
	return false;
}

bool Event::downKey(KEY_CODE key)
{
	return this->downKey(convertKeyCode(key));
}

bool Event::upKey(int key)
{
	if (this->key[key] < this->saveKey[key])
	{
		return true;
	}
	return false;
}

bool Event::upKey(KEY_CODE key)
{
	return this->upKey(convertKeyCode(key));
}
