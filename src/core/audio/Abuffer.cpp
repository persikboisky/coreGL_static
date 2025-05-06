#include "Abuffer.hpp"
#include "../file/wav.hpp"
#include <AL/al.h>
#include <vector>
#include <iostream>

using namespace core;

unsigned int audio::Buffer::getID() const
{
	return this->id;
}

audio::Buffer::Buffer(const char* path)
{
	alGenBuffers(1, &this->id);
	if (this->id <= 0)
	{
		std::cerr << "Failed: create audio buffer";
		throw "FAILED_CREATE_AUDIO_BUFFER";
	}

	uint8_t channels;
	int32_t sampleRate;
	uint8_t bitsPerSample;
	ALsizei size;
	std::vector<char> code = wav::load(path, channels, sampleRate, bitsPerSample, size);

	ALenum format;
	if (channels == (uint8_t)1 && bitsPerSample == (uint8_t)8)
		format = AL_FORMAT_MONO8;
	else if (channels == (uint8_t)1 && bitsPerSample == (uint8_t)16)
		format = AL_FORMAT_MONO16;
	else if (channels == (uint8_t)2 && bitsPerSample == (uint8_t)8)
		format = AL_FORMAT_STEREO8;
	else if (channels == (uint8_t)2 && bitsPerSample == (uint8_t)16)
		format = AL_FORMAT_STEREO16;

	alBufferData(this->id, format, code.data(), code.size(), sampleRate);

	code.clear();
}

audio::Buffer::~Buffer()
{
	alDeleteBuffers(1, &this->id);
}
