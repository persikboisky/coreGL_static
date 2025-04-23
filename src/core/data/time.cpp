#include "time.hpp"
#include <GLFW/glfw3.h>
#include <chrono>
#include <iostream>

Time::Date::Date()
{

}

Time::Timer::Timer() : startTime(0)
{}

void Time::Timer::start()
{
	this->startTime = glfwGetTime();
}

double Time::Timer::finish() const
{
	return glfwGetTime() - this->startTime;
}
