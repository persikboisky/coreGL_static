#ifndef SRC_CORE_DATA_TYPE_HPP_
#define SRC_CORE_DATA_TYPE_HPP_

namespace core
{
	namespace color
	{
		enum COLOR
		{
			ALICE_BLUE,
			ANTIQUE_WHITE,
			AQUA,
			AQUAMARINE,
			AZURE,
			BEIGE,
			BISQUE,
			BLACK,
			BLANCHED_ALMOND,
			BLUE,
			BLUE_VIOLET,
			BROWN,
			BURTLY_WOOD,
			CADET_BLUE,
			CHARTREUSE,
			CHOCOLATE,
			CORAL,
			CORNFLOWER_BLUE,
			CORNSILK,
			CRIMSON,
			CYAN,
			DARK_BLUE,
			DARK_CYAN,
			DARK_GOLDEN_ROD,
			DARK_GREY,
			DARK_GREEN,
			DARK_KHAKI,
			DARK_MAGENTA,
			DARK_OLIVE_GREEN,
			DARK_ORANGE,
			DARK_ORCHID,
			DARK_RED,
			DARK_SALMON,
			DARK_SLATE_BLUE,
			DARK_SLATE_GREY,
			DARK_TURQUOISE,
			DARK_VIOLET,
			DEEP_PINK,
			DEEP_SKY_BLUE,
			DIM_GREY,
			DODGER_BLUE,
			FIRE_BRICK,
			FLORAL_WHITE,
			FOREST_GREEN,
			FUCHSIA,
			GAINSBORO,
			GHOST_WHITE,
			GOLD,
			GOLDEN_ROD,
			GREY,
			GREEN,
			GREEN_YELLOW,
			HONEY_DEW,
			HOT_PINK,
			INDIAN_RED,
			INDIGO,
			IVORY,
			KHAKI,
			LAVENDER,
			LAVENDER_BLUSH,
			LAWN_GREEN,
			LEMON_CHIFFON,
			LIGHT_BLUE,
			LIGHT_CORAL,
			LIGHT_CYAN,
			LIGHT_GOLDEN_ROD_YELLOW,
			LIGHT_GREY,
			LIGHT_GREEN,
			LIGHT_PINK,
			LIGHT_SALMON,
			LIGHT_SEA_GREEN,
			LIGHT_SKY_BLUE,
			LIGHT_SLATE_GREY,
			LIGHT_STEEL_BLUE,
			LIGHT_YELLOW,
			LIME,
			LIME_GREEN,
			LINEN,
			MAGENTA,
			MAROON,
			MEDIUM_AQUA_MARINE,
			MEDIUM_BLUE,
			MEDIUM_ORCHID,
			MEDIUM_PURPLE,
			MEDIUM_SEA_GREEN,
			MEDIUM_SLATE_BLUE,
			MEDIUM_SPRING_GREEN,
			MEDIUM_TURQUOISE,
			MEDIUM_VIOLET_RED,
			MIDNIGHT_BLUE,
			MINT_CREAM,
			MISTY_ROSE,
			MOCCASIN,
			NAVAJO_WHITE,
			NAVY,
			OLD_LACE,
			OLIVE,
			OLIVE_DRAB,
			ORANGE,
			ORANGE_RED,
			ORCHID,
			PALE_GOLDEN_ROD,
			PALE_GREEN,
			PALE_TURQUOISE,
			PALE_VIOLET_RED,
			PAPAYA_WHIP,
			PEACH_PUFF,
			PERU,
			PINK,
			PLUM,
			POWDER_BLUE,
			PURPLE,
			REBECCA_PURPLE,
			RED,
			ROSY_BROWN,
			ROYAL_BLUE,
			SADDLE_BROWN,
			SALMON,
			SANDY_BROWN,
			SEA_GREEN,
			SEA_SHELL,
			SIENNA,
			SILVER,
			SKY_BLUE,
			SLATE_BLUE,
			SLATE_GREY,
			SNOW,
			SPRING_GREEN,
			STEEL_BLUE,
			TAN,
			TEAL,
			THISTLE,
			TOMATO,
			TURQUOISE,
			VIOLET,
			WHEAT,
			WHITE,
			WHITE_SMOKE,
			YELLOW,
			YELLOW_GREEN
		};

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
			RGB(COLOR color);

			void operator = (const RGB& color);
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
			RGBA(COLOR color);

			void operator = (const RGB& color);
			void operator = (const RGBA& color);
		};
	}

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
		/// @brief режим координат относительно окна(отсчёт идёт от центра, где центр это координата 0, 0)
		WINDOW_COORD,

		/// @brief режим положительных координат относительно окна
		/// @brief (отсчёт идёт от верхнего левого угла, где центр это координата 0, 0)
		POSITIVE_WINDOW_COORD,

		/// @brief режим относительных координат(отсчёт идёт от центра, где центр это координата 0, 0; до 0.5 или -0.5)
		RELATIVE_COORD,

		/// @brief режим положительных относительных координат
		/// @brief (отсчёт идёт от верхнего левого угла, где центр это координата 0, 0; до 1 или -1) 
		POSITIVE_RELATIVE_COORD
	};

	enum Buffer
	{
		/// @brief буфер цвета
		COLOR_BUFFER = 1,

		/// @brief буфер глубины(z-буфер)
		DEPTH_BUFFER = 2,

		NONE = 0
	};

	enum TYPE_SHADER
	{
		FRAGMENT,
		GEOMETRY,
		VERTEX
	};

	color::RGBA convertColor(color::COLOR color);
}

#endif // !SRC_CORE_DATA_TYPE_HPP_