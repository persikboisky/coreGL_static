#ifndef SRC_CORE_GRAPHICS_RENDERER_RECT_HPP_
#define SRC_CORE_GRAPHICS_RENDERER_RECT_HPP_

#include "../../util/type.hpp"

namespace core
{
	class Texture;

	class Rect
	{
	private:
		static unsigned int vaoID;
		static unsigned int shaderID;

		unsigned int tID = 0;
		RGBA color;

	public:
		Rect();

		void setTexture(unsigned int id);
		void setTexture(const Texture& texture);

		void setColor(float red, float green, float blue, float alpha = 1.0f);
		void setColor(const RGB& color);
		void setColor(const RGBA& color);

		void draw(float x, float y, float width, float height);
	};
}

#endif // !SRC_CORE_GRAPHICS_RENDERER_RECT_HPP_