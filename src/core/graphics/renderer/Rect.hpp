#ifndef SRC_CORE_GRAPHICS_RENDERER_RECT_HPP_
#define SRC_CORE_GRAPHICS_RENDERER_RECT_HPP_

#include "../../util/type.hpp"

namespace core
{
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

	public:
		Rect();

		void setTexture(unsigned int id);
		void setTexture(const Texture& texture);

		void setColor(float red, float green, float blue, float alpha = 1.0f);
		void setColor(const RGB& color);
		void setColor(const RGBA& color);

		void setCoordType(TYPE_COORD typeCoord);

		void draw(float x, float y, float width, float height, Window& window) const;
	};
}

#endif // !SRC_CORE_GRAPHICS_RENDERER_RECT_HPP_