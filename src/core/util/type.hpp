#ifndef SRC_CORE_DATA_TYPE_HPP_
#define SRC_CORE_DATA_TYPE_HPP_

namespace core
{

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
	};

	struct RGBA final
	{
		float red;
		float green;
		float blue;
		float alpha;

		RGBA() : red(0), green(0), blue(0), alpha(1.0) {}
		RGBA(float red, float green, float blue, float alpha = 255.0f) :
			red(red), green(green), blue(blue), alpha(alpha)
		{
		}
	};

	struct position_2f final
	{
		float x = 0;
		float y = 0;

		position_2f() {}
		position_2f(float x, float y) : x(x), y(y) {}
	};

	struct position_3f final
	{
		float x = 0;
		float y = 0;
		float z = 0;

		position_3f() {}
		position_3f(float x, float y, float z) : x(x), y(y), z(z) {}
	};

	struct position_4f final
	{
		float x = 0;
		float y = 0;
		float z = 0;
		float w = 0;

		position_4f() {}
		position_4f(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
	};

	struct size_2f final
	{
		float width = 0;
		float height = 0;

		size_2f() {}
		size_2f(float width, float height) : width(width), height(height)
		{
		}
	};

	struct size_3f final
	{
		float width = 0;
		float height = 0;
		float length = 0;

		size_3f() {}
		size_3f(float width, float height, float length) :
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

	unsigned int convertPrimitive(PRIMITIVE primitive);

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
}


#endif // !SRC_CORE_DATA_TYPE_HPP_