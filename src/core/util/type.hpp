#ifndef SRC_CORE_DATA_TYPE_HPP_
#define SRC_CORE_DATA_TYPE_HPP_

namespace core
{
	enum COLOR;

	struct RGB final
	{
		float red;
		float green;
		float blue;

		RGB() : red(0), green(0), blue(0) {}
		RGB(float red, float green, float blue) :
			red(red), green(green), blue(blue)
		{
		}

		void operator = (const RGB& color);
	};

	struct RGBA final
	{
		float red;
		float green;
		float blue;
		float alpha;

		RGBA(COLOR color);
		RGBA() : red(0), green(0), blue(0), alpha(1.0) {}
		RGBA(float red, float green, float blue, float alpha = 255.0f) :
			red(red), green(green), blue(blue), alpha(alpha)
		{
		}


		void operator = (const RGB& color);
		void operator = (const RGBA& color);
	};

	struct pos2f final
	{
		float x = 0;
		float y = 0;

		pos2f() {}
		pos2f(float x, float y) : x(x), y(y) {}
	};

	struct pos3f final
	{
		float x = 0;
		float y = 0;
		float z = 0;

		pos3f() {}
		pos3f(float x, float y, float z) : x(x), y(y), z(z) {}
	};

	struct pos4f final
	{
		float x = 0;
		float y = 0;
		float z = 0;
		float w = 0;

		pos4f() {}
		pos4f(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
	};

	struct size2f final
	{
		float width = 0;
		float height = 0;

		size2f() {}
		size2f(float width, float height) : width(width), height(height)
		{
		}
	};

	struct size3f final
	{
		float width = 0;
		float height = 0;
		float length = 0;

		size3f() {}
		size3f(float width, float height, float length) :
			width(width), height(height), length(length)
		{
		}
	};

	enum CAM_MODE
	{
		/// @brief ������ ������� � ���� �����
		CAM_DYNAMIC,

		/// @brief ������ ������� � ���� �����������
		CAM_STATIC,

		CAM_PLAYER
	};

	enum PRIMITIVE
	{
		POINTS,
		LINES,
		LINE_STRIP,
		LINE_LOOP,
		TRIANGLES,
		TRIANGLES_FAN,
		TRIANGLES_STRIP
	};

	enum KEY_CODE {
		K_F1,
		K_F2,
		K_F3,
		K_F4,
		K_F5,
		K_F6,
		K_F7,
		K_F8,
		K_F9,
		K_F10,
		K_F11,
		K_F12,
		K_PRINT_SCREEN,
		K_SCROLL_LOCK,
		K_PAUSE,
		K_1,
		K_2,
		K_3,
		K_4,
		K_5,
		K_6,
		K_7,
		K_8,
		K_9,
		K_0,
		K_Q,
		K_W,
		K_E,
		K_R,
		K_T,
		K_Y,
		K_U,
		K_I,
		K_O,
		K_P,
		K_A,
		K_S,
		K_D,
		K_F,
		K_G,
		K_H,
		K_J,
		K_K,
		K_L,
		K_Z,
		K_X,
		K_C,
		K_V,
		K_B,
		K_N,
		K_M,
		K_SPACE,
		K_ESCAPE,
		K_LEFT_SHIFT,
		K_LEFT_CONTROL
	};

	unsigned int convertPrimitive(PRIMITIVE primitive);
	int convertKeyCode(KEY_CODE keyCode);

	enum TYPE_COORD
	{
		WINDOW_COORD,
		POSITIVE_WINDOW_COORD,
		RELATIVE_COORD,
		POSITIVE_RELATIVE_COORD
	};

	enum Buffer
	{
		COLOR_BUFFER = 1,
		DEPTH_BUFFER = 2,
		NONE = 0
	};

	enum TYPE_SHADER
	{
		FRAGMENT,
		GEOMETRY,
		VERTEX
	};

	enum COLOR
	{
		RED,
		GREEN,
		BLUE,
		WHITE
	};

	RGBA convertColor(COLOR color);
}

#endif // !SRC_CORE_DATA_TYPE_HPP_