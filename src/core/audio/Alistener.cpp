#include "Alistener.hpp"
#include <AL/al.h>

float data[6] = { 0, 0, 0, 0, 0, 0 };

void listener::setOrientation(float pX, float pY, float pZ, float upX, float upY, float upZ)
{
	data[0] = pX;
	data[1] = pY;
	data[2] = pZ;
	data[3] = upX;
	data[4] = upY;
	data[5] = upZ;

	alListenerfv(AL_ORIENTATION, data);
}

void listener::setPos3f(float x, float y, float z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;

	listener::setOrientation(x, y, z, data[3], data[4], data[5]);
}

void listener::setUp3f(float x, float y, float z)
{
	data[3] = x;
	data[4] = y;
	data[5] = z;

	listener::setOrientation(data[0], data[1], data[2], x, y, z);
}

void listener::setVelocity3f(float x, float y, float z)
{
	alListener3f(AL_VELOCITY, x, y, z);
}
