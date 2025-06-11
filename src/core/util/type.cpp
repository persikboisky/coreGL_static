#include "type.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace core;

color::RGB::RGB(COLOR color)
{
	RGBA Color = convertColor(color);
	this->red = Color.red;
	this->green = Color.green;
	this->blue = Color.blue;
}

void color::RGB::operator=(const RGB &color)
{
	this->red = color.red;
	this->green = color.green;
	this->blue = color.blue;
}

color::RGBA::RGBA(COLOR color)
{
	RGBA Color = convertColor(color);
	this->red = Color.red;
	this->green = Color.green;
	this->blue = Color.blue;
	this->alpha = Color.alpha;
}

void color::RGBA::operator=(const RGB &color)
{
	this->red = color.red;
	this->green = color.green;
	this->blue = color.blue;
	this->alpha = 255.0f;
}

void color::RGBA::operator=(const RGBA &color)
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

color::RGBA core::convertColor(color::COLOR color)
{
	switch (color)
	{
	case color::ALICE_BLUE:
		return color::RGBA(240, 248, 255);
	case color::ANTIQUE_WHITE:
		return color::RGBA(250, 235, 215);
	case color::AQUA:
		return color::RGBA(0, 255, 255);
	case color::AQUAMARINE:
		return color::RGBA(127, 255, 212);
	case color::AZURE:
		return color::RGBA(240, 255, 255);
	case color::BEIGE:
		return color::RGBA(245, 245, 220);
	case color::BISQUE:
		return color::RGBA(255, 228, 196);
	case color::BLACK:
		return color::RGBA(0, 0, 0);
	case color::BLANCHED_ALMOND:
		return color::RGBA(255, 235, 205);
	case color::BLUE:
		return color::RGBA(0, 0, 255);
	case color::BLUE_VIOLET:
		return color::RGBA(138, 43, 226);
	case color::BROWN:
		return color::RGBA(165, 42, 42);
	case color::BURTLY_WOOD:
		return color::RGBA(222, 184, 135);
	case color::CADET_BLUE:
		return color::RGBA(95, 158, 160);
	case color::CHARTREUSE:
		return color::RGBA(127, 255, 0);
	case color::CHOCOLATE:
		return color::RGBA(210, 105, 30);
	case color::CORAL:
		return color::RGBA(255, 127, 80);
	case color::CORNFLOWER_BLUE:
		return color::RGBA(100, 149, 237);
	case color::CORNSILK:
		return color::RGBA(255, 248, 220);
	case color::CRIMSON:
		return color::RGBA(220, 20, 60);
	case color::CYAN:
		return color::RGBA(0, 255, 255);
	case color::DARK_BLUE:
		return color::RGBA(0, 0, 139);
	case color::DARK_CYAN:
		return color::RGBA(0, 139, 139);
	case color::DARK_GOLDEN_ROD:
		return color::RGBA(184, 134, 11);
	case color::DARK_GREY:
		return color::RGBA(169, 169, 169);
	case color::DARK_GREEN:
		return color::RGBA(0, 100, 0);
	case color::DARK_KHAKI:
		return color::RGBA(189, 183, 107);
	case color::DARK_MAGENTA:
		return color::RGBA(139, 0, 139);
	case color::DARK_OLIVE_GREEN:
		return color::RGBA(85, 107, 47);
	case color::DARK_ORANGE:
		return color::RGBA(255, 140, 0);
	case color::DARK_ORCHID:
		return color::RGBA(153, 50, 204);
	case color::DARK_RED:
		return color::RGBA(139, 0, 0);
	case color::DARK_SALMON:
		return color::RGBA(143, 188, 143);
	case color::DARK_SLATE_BLUE:
		return color::RGBA(72, 61, 139);
	case color::DARK_SLATE_GREY:
		return color::RGBA(47, 79, 79);
	case color::DARK_TURQUOISE:
		return color::RGBA(0, 206, 209);
	case color::DARK_VIOLET:
		return color::RGBA(148, 0, 211);
	case color::DEEP_PINK:
		return color::RGBA(255, 20, 147);
	case color::DEEP_SKY_BLUE:
		return color::RGBA(0, 191, 255);
	case color::DIM_GREY:
		return color::RGBA(105, 105, 105);
	case color::DODGER_BLUE:
		return color::RGBA(30, 144, 255);
	case color::FIRE_BRICK:
		return color::RGBA(178, 34, 34);
	case color::FLORAL_WHITE:
		return color::RGBA(255, 250, 240);
	case color::FOREST_GREEN:
		return color::RGBA(34, 139, 34);
	case color::FUCHSIA:
		return color::RGBA(255, 0, 255);
	case color::GAINSBORO:
		return color::RGBA(220, 220, 220);
	case color::GHOST_WHITE:
		return color::RGBA(248, 248, 255);
	case color::GOLD:
		return color::RGBA(255, 215, 0);
	case color::GOLDEN_ROD:
		return color::RGBA(218, 165, 32);
	case color::GREY:
		return color::RGBA(128, 128, 128);
	case color::GREEN:
		return color::RGBA(0, 128, 0);
	case color::GREEN_YELLOW:
		return color::RGBA(173, 255, 47);
	case color::HONEY_DEW:
		return color::RGBA(240, 255, 240);
	case color::HOT_PINK:
		return color::RGBA(255, 105, 180);
	case color::INDIAN_RED:
		return color::RGBA(205, 92, 92);
	case color::INDIGO:
		return color::RGBA(75, 0, 130);
	case color::IVORY:
		return color::RGBA(255, 255, 240);
	case color::KHAKI:
		return color::RGBA(240, 230, 140);
	case color::LAVENDER:
		return color::RGBA(230, 230, 250);
	case color::LAVENDER_BLUSH:
		return color::RGBA(255, 240, 245);
	case color::LAWN_GREEN:
		return color::RGBA(124, 252, 0);
	case color::LEMON_CHIFFON:
		return color::RGBA(255, 250, 205);
	case color::LIGHT_BLUE:
		return color::RGBA(173, 216, 230);
	case color::LIGHT_CORAL:
		return color::RGBA(240, 128, 128);
	case color::LIGHT_CYAN:
		return color::RGBA(224, 255, 255);
	case color::LIGHT_GOLDEN_ROD_YELLOW:
		return color::RGBA(250, 250, 210);
	case color::LIGHT_GREY:
		return color::RGBA(211, 211, 211);
	case color::LIGHT_GREEN:
		return color::RGBA(144, 238, 144);
	case color::LIGHT_PINK:
		return color::RGBA(255, 182, 193);
	case color::LIGHT_SALMON:
		return color::RGBA(255, 160, 122);
	case color::LIGHT_SEA_GREEN:
		return color::RGBA(32, 178, 170);
	case color::LIGHT_SKY_BLUE:
		return color::RGBA(135, 206, 250);
	case color::LIGHT_SLATE_GREY:
		return color::RGBA(119, 136, 153);
	case color::LIGHT_STEEL_BLUE:
		return color::RGBA(176, 196, 222);
	case color::LIGHT_YELLOW:
		return color::RGBA(255, 255, 224);
	case color::LIME:
		return color::RGBA(0, 255, 0);
	case color::LIME_GREEN:
		return color::RGBA(50, 205, 50);
	case color::LINEN:
		return color::RGBA(250, 240, 230);
	case color::MAGENTA:
		return color::RGBA(255, 0, 255);
	case color::MAROON:
		return color::RGBA(128, 0, 0);
	case color::MEDIUM_AQUA_MARINE:
		return color::RGBA(102, 205, 170);
	case color::MEDIUM_BLUE:
		return color::RGBA(0, 0, 205);
	case color::MEDIUM_ORCHID:
		return color::RGBA(186, 85, 211);
	case color::MEDIUM_PURPLE:
		return color::RGBA(147, 112, 219);
	case color::MEDIUM_SEA_GREEN:
		return color::RGBA(60, 179, 113);
	case color::MEDIUM_SLATE_BLUE:
		return color::RGBA(123, 104, 238);
	case color::MEDIUM_SPRING_GREEN:
		return color::RGBA(0, 250, 154);
	case color::MEDIUM_TURQUOISE:
		return color::RGBA(72, 209, 204);
	case color::MEDIUM_VIOLET_RED:
		return color::RGBA(199, 21, 133);
	case color::MIDNIGHT_BLUE:
		return color::RGBA(25, 25, 112);
	case color::MINT_CREAM:
		return color::RGBA(245, 255, 250);
	case color::MISTY_ROSE:
		return color::RGBA(255, 228, 225);
	case color::MOCCASIN:
		return color::RGBA(255, 228, 181);
	case color::NAVAJO_WHITE:
		return color::RGBA(255, 222, 173);
	case color::NAVY:
		return color::RGBA(0, 0, 128);
	case color::OLD_LACE:
		return color::RGBA(253, 245, 230);
	case color::OLIVE:
		return color::RGBA(128, 128, 0);
	case color::OLIVE_DRAB:
		return color::RGBA(107, 142, 35);
	case color::ORANGE:
		return color::RGBA(255, 165, 0);
	case color::ORANGE_RED:
		return color::RGBA(255, 69, 0);
	case color::ORCHID:
		return color::RGBA(218, 112, 214);
	case color::PALE_GOLDEN_ROD:
		return color::RGBA(238, 232, 170);
	case color::PALE_GREEN:
		return color::RGBA(152, 251, 152);
	case color::PALE_TURQUOISE:
		return color::RGBA(175, 238, 238);
	case color::PALE_VIOLET_RED:
		return color::RGBA(219, 112, 147);
	case color::PAPAYA_WHIP:
		return color::RGBA(255, 239, 213);
	case color::PEACH_PUFF:
		return color::RGBA(255, 218, 185);
	case color::PERU:
		return color::RGBA(205, 133, 63);
	case color::PINK:
		return color::RGBA(255, 192, 203);
	case color::PLUM:
		return color::RGBA(221, 160, 221);
	case color::POWDER_BLUE:
		return color::RGBA(176, 224, 230);
	case color::PURPLE:
		return color::RGBA(128, 0, 128);
	case color::REBECCA_PURPLE:
		return color::RGBA(102, 51, 153);
	case color::RED:
		return color::RGBA(255, 0, 0);
	case color::ROSY_BROWN:
		return color::RGBA(188, 143, 143);
	case color::ROYAL_BLUE:
		return color::RGBA(65, 105, 225);
	case color::SADDLE_BROWN:
		return color::RGBA(139, 69, 19);
	case color::SALMON:
		return color::RGBA(250, 128, 114);
	case color::SANDY_BROWN:
		return color::RGBA(244, 164, 96);
	case color::SEA_GREEN:
		return color::RGBA(46, 139, 87);
	case color::SEA_SHELL:
		return color::RGBA(255, 245, 238);
	case color::SIENNA:
		return color::RGBA(160, 82, 45);
	case color::SILVER:
		return color::RGBA(192, 192, 192);
	case color::SKY_BLUE:
		return color::RGBA(135, 206, 235);
	case color::SLATE_BLUE:
		return color::RGBA(106, 90, 205);
	case color::SLATE_GREY:
		return color::RGBA(112, 128, 144);
	case color::SNOW:
		return color::RGBA(255, 250, 250);
	case color::SPRING_GREEN:
		return color::RGBA(0, 255, 127);
	case color::STEEL_BLUE:
		return color::RGBA(70, 130, 180);
	case color::TAN:
		return color::RGBA(210, 180, 140);
	case color::TEAL:
		return color::RGBA(0, 128, 128);
	case color::THISTLE:
		return color::RGBA(216, 191, 216);
	case color::TOMATO:
		return color::RGBA(255, 99, 71);
	case color::TURQUOISE:
		return color::RGBA(64, 224, 208);
	case color::VIOLET:
		return color::RGBA(238, 130, 238);
	case color::WHEAT:
		return color::RGBA(245, 222, 179);
	case color::WHITE:
		return color::RGBA(255, 255, 255);
	case color::WHITE_SMOKE:
		return color::RGBA(245, 245, 245);
	case color::YELLOW:
		return color::RGBA(255, 255, 0);
	case color::YELLOW_GREEN:
		return color::RGBA(154, 205, 50);
	default:
		return color::RGBA(0, 0, 0, 0);
	}
}