#ifndef SRC_CORE_RENDERER_TURTLE_HPP_
#define SRC_CORE_RENDERER_TURTLE_HPP_

#include "../../math/Vectors.hpp"
#include "../../util/type.hpp"
#include <vector>

namespace core
{
	enum TYPE_COORD;
	class Window;
	struct RGBA;

	class Turtle
	{
	private:
		static unsigned int shaderTurtle;
		static unsigned int shaderLine;
		static unsigned int idText;

		float x = 0.0f;
		float y = -0.5f;

		TYPE_COORD typeCoord;

		std::vector<std::vector<float>> coordPoint;
		std::vector<unsigned int> width{ 1 };

		bool updateVao = true;
		std::vector<unsigned int> vaoPoints{ 0 };
		unsigned int vaoTurtle = 0;

		bool bodyTurtleDraw = true;

		float angle = 270.0f;
		RGB color;

		Window* window;


	public:

		Turtle(Window& window);
		~Turtle();

		void setPos(float x, float y);
		void setPos(const math::Vector2& vec2);

		void clear();

		void setCoordMode(TYPE_COORD typeCoord);
		void move();
		void draw();

		void setAngle(float degree);
		void setColor(RGB color);
		void setWidth(float width);

		void enableDrawBody(bool flag);
	};
}

#endif // !SRC_CORE_RENDERER_TURTLE_HPP_