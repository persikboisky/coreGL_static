#include "Asource.hpp"
#include "Abuffer.hpp"
#include <AL/al.h>
#include <iostream>

audio::Source::Source()
{
	alGenSources(1, &this->id);
	if (this->id <= 0)
	{
		std::cerr << "Failed: create audio source" << std::endl;
		throw "FAILED_CREATE_AUDIO_SOURCE";
	}
}

audio::Source::~Source()
{
	alDeleteSources(1, &this->id);
}

void audio::Source::linkBuffer(audio::Buffer buffer) const
{
	alSourcei(this->id, AL_BUFFER, buffer.getID());
}

void audio::Source::setVolume(float value) const
{
	alSourcef(this->id, AL_GAIN, value);
}

void audio::Source::setSpeed(float value) const
{
	alSourcef(this->id, AL_PITCH, value);
}

void audio::Source::looping(bool flag) const
{
	alSourcei(this->id, AL_LOOPING, flag);
}

void audio::Source::play() const
{
	alSourcePlay(this->id);
}
