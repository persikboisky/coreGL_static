#include "type.hpp"
#include <GL/glew.h>

using namespace core;

void core::RGB::operator=(const RGB& color)
{
	this->red = color.red;
	this->green = color.green;
	this->blue = color.blue;
}

void RGBA::operator=(const RGB& color)
{
	this->red = color.red;
	this->green = color.green;
	this->blue = color.blue;
	this->alpha = 255.0f;
}

void RGBA::operator=(const core::RGBA& color)
{
	this->red = color.red;
	this->green = color.green;
	this->blue = color.blue;
	this->alpha = color.alpha;
}

unsigned int core::convertPrimitive(PRIMITIVE primitive)
{
	switch (primitive)
	{
	case POINTS:
		return GL_POINTS;

	case TRIANGLES:
		return GL_TRIANGLES;

	case LINES:
		return GL_LINES;

	case LINE_STRIP:
		return GL_LINE_STRIP;

	case LINE_LOOP:
		return GL_LINE_LOOP;

	case TRIANGLES_FAN:
		return GL_TRIANGLE_FAN;

	case TRIANGLES_STRIP:
		return GL_TRIANGLE_STRIP;

	default:
		break;
	}
}