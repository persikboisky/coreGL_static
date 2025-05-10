#include "type.hpp"
#include <GL/glew.h>

unsigned int core::convertPrimitive(PRIMITIVE primitive)
{
	switch (primitive)
	{
	case core::POINTS:
		return GL_POINTS;

	case core::TRIANGLES:
		return GL_TRIANGLES;

	case core::LINES:
		return GL_LINES;

	case core::LINE_STRIP:
		return GL_LINE_STRIP;

	case core::LINE_LOOP:
		return GL_LINE_LOOP;

	case core::TRIANGLES_FAN:
		return GL_TRIANGLE_FAN;

	case core::TRIANGLES_STRIP:
		return GL_TRIANGLE_STRIP;

	default:
		break;
	}
}