#include "ADevice.hpp"
#include <AL/al.h>
#include <AL/alc.h>
#include <GLFW/glfw3.h>	
#include <iostream>

extern bool coreInfo;

audio::Device::Device()
{
	this->device = alcOpenDevice(nullptr);
	if (!this->device)
	{
		std::cerr << "Failed: create audio device" << std::endl;
		throw "FAILED_CREATE_AUDIO_DEVICE";
	}

	if (coreInfo) std::cout << "[" << glfwGetTime() << "] " <<
		"OK: create audio device" << std::endl;

	this->context = alcCreateContext(this->device, nullptr);
	if (!this->context)
	{
		std::cerr << "Failed: create audio context" << std::endl;
		throw "FAILED_CREATE_AUDIO_CONTEXT";
	}

	if (coreInfo) std::cout << "[" << glfwGetTime() << "] " <<
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
