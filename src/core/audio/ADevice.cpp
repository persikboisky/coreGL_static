#include "ADevice.hpp"
#include "../config.hpp"
#include <AL/al.h>
#include <AL/alc.h>
#include <GLFW/glfw3.h>	
#include <iostream>

using namespace core;

audio::Device::Device()
{
	this->device = alcOpenDevice(nullptr);
	if (!this->device)
	{
		std::cerr << "Failed: create audio device" << std::endl;
		throw "FAILED_CREATE_AUDIO_DEVICE";
	}

	if (CORE_INFO) std::cout << "[" << glfwGetTime() << "] " <<
		"OK: create audio device" << std::endl;

	this->context = alcCreateContext(this->device, nullptr);
	if (!this->context)
	{
		std::cerr << "Failed: create audio context" << std::endl;
		throw "FAILED_CREATE_AUDIO_CONTEXT";
	}

	if (CORE_INFO) std::cout << "[" << glfwGetTime() << "] " <<
		"OK: create audio context" << std::endl;
}

audio::Device::~Device()
{
	alcMakeContextCurrent(nullptr);
	alcDestroyContext(this->context);
	alcCloseDevice(this->device);
}

void audio::Device::setContext()
{
	if (!alcMakeContextCurrent(this->context))
	{
		std::cerr << "Failed: ser audio context" << std::endl;
		throw "FAILED_SET_AUDIO_CONTEXT";
	}
}
