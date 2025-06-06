#include "type.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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

int core::convertKeyCode(core::KEY_CODE keyCode)
{
	switch (keyCode)
	{
	case core::K_F1:
		return GLFW_KEY_F1;
	case core::K_F2:
		return GLFW_KEY_F2;
	case core::K_F3:
		return GLFW_KEY_F3;
	case core::K_F4:
		return GLFW_KEY_F4;
	case core::K_F5:
		return GLFW_KEY_F5;
	case core::K_F6:
		return GLFW_KEY_F6;
	case core::K_F7:
		return GLFW_KEY_F7;
	case core::K_F8:
		return GLFW_KEY_F8;
	case core::K_F9:
		return GLFW_KEY_F9;
	case core::K_F10:
		return GLFW_KEY_F10;
	case core::K_F11:
		return GLFW_KEY_F11;
	case core::K_F12:
		return GLFW_KEY_F12;
	case core::K_PRINT_SCREEN:
		return GLFW_KEY_PRINT_SCREEN;
	case core::K_SCROLL_LOCK:
		return GLFW_KEY_SCROLL_LOCK;
	case core::K_PAUSE:
		return GLFW_KEY_PAUSE;
	case core::K_1:
		return GLFW_KEY_1;
	case core::K_2:
		return GLFW_KEY_2;
	case core::K_3:
		return GLFW_KEY_3;
	case core::K_4:
		return GLFW_KEY_4;
	case core::K_5:
		return GLFW_KEY_5;
	case core::K_6:
		return GLFW_KEY_6;
	case core::K_7:
		return GLFW_KEY_7;
	case core::K_8:
		return GLFW_KEY_8;
	case core::K_9:
		return GLFW_KEY_9;
	case core::K_0:
		return GLFW_KEY_0;
	case core::K_Q:
		return GLFW_KEY_Q;
	case core::K_W:
		return GLFW_KEY_W;
	case core::K_E:
		return GLFW_KEY_E;
	case core::K_R:
		return GLFW_KEY_R;
	case core::K_T:
		return GLFW_KEY_T;
	case core::K_Y:
		return GLFW_KEY_Y;
	case core::K_U:
		return GLFW_KEY_U;
	case core::K_I:
		return GLFW_KEY_I;
	case core::K_O:
		return GLFW_KEY_O;
	case core::K_P:
		return GLFW_KEY_P;
	case core::K_A:
		return GLFW_KEY_A;
	case core::K_S:
		return GLFW_KEY_S;
	case core::K_D:
		return GLFW_KEY_D;
	case core::K_F:
		return GLFW_KEY_F;
	case core::K_G:
		return GLFW_KEY_G;
	case core::K_H:
		return GLFW_KEY_H;
	case core::K_J:
		return GLFW_KEY_H;
	case core::K_K:
		return GLFW_KEY_K;
	case core::K_L:
		return GLFW_KEY_L;
	case core::K_Z:
		return GLFW_KEY_Z;
	case core::K_X:
		return GLFW_KEY_X;
	case core::K_C:
		return GLFW_KEY_C;
	case core::K_V:
		return GLFW_KEY_V;
	case core::K_B:
		return GLFW_KEY_B;
	case core::K_N:
		return GLFW_KEY_N;
	case core::K_M:
		return GLFW_KEY_M;
	case core::K_SPACE:
		return GLFW_KEY_SPACE;
	case core::K_ESCAPE:
		return GLFW_KEY_ESCAPE;
	case core::K_LEFT_SHIFT:
		return GLFW_KEY_LEFT_SHIFT;
	case core::K_LEFT_CONTROL:
		return GLFW_KEY_LEFT_CONTROL;
	default:
		break;
	}
}
