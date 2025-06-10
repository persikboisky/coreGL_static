#ifndef SRC_CORE_GRAPHICS_RENDERER_RECT_HPP_
#define SRC_CORE_GRAPHICS_RENDERER_RECT_HPP_

#include "../../util/type.hpp"

namespace core
{
	namespace math
	{
		struct Vector2;
	}

	class Texture;
	class Window;

	class Rect
	{
	private:
		static unsigned int shaderID;
		static unsigned int textureID;
		
		unsigned int userTID = 0;
		RGBA color;

		TYPE_COORD typeCoord = POSITIVE_WINDOW_COORD;

		float u1 = 0.0f;
		float u2 = 1.0f;
		float v1 = 0.0f;
		float v2 = 1.0f;

	public:
		Rect();

		/// @brief устанавливает текстуру
		/// @param id дескриптор текстуры
		void setTexture(unsigned int id);

		/// @brief устанавливает текстуру
		/// @param texture объект текстуры
		void setTexture(const Texture& texture);

		/// @brief устанавливает координаты фрагмента текстуры для отрисовки
		/// @param u1 x координата верехнего левого угла
		/// @param v1 y координата верехнего левого угла
		/// @param u2 x координата нижнего правого угла
		/// @param v2 y координата нижнего правого угла
		void setTextureCoord(float u1, float v1, float u2, float v2);

		/// @brief устанавливает координаты фрагмента текстуры для отрисовки
		/// @param vec2_1 координаты верехнего левого угла
		/// @param vec2_2 координаты нижнего правого угла
		void setTextureCoord(math::Vector2 vec2_1, math::Vector2 vec2_2);

		/// @brief устанавливает цвет
		/// @param red красный канал (от 0 до 255)
		/// @param green зелёный канал (от 0 до 255)
		/// @param blue синий канал (от 0 до 255)
		/// @param alpha альфа канал (от 0 до 255), по ум
		void setColor(float red, float green, float blue, float alpha = 1.0f);
		void setColor(const RGB& color);
		void setColor(const RGBA& color);

		void setCoordType(TYPE_COORD typeCoord);

		void draw(float x, float y, float width, float height, Window& window) const;
	};
}

#endif // !SRC_CORE_GRAPHICS_RENDERER_RECT_HPP_