#ifndef SRC_CORE_RENDERER_TURTLE_HPP_
#define SRC_CORE_RENDERER_TURTLE_HPP_

#include "../../math/Vectors.hpp"
#include "../../util/type.hpp"
#include <vector>

namespace core
{
	class Window;

	class Turtle
	{
	private:
		static unsigned int shaderTurtle;
		static unsigned int shaderLine;
		static unsigned int idText;

		float x = 0.0f;
		float y = -0.5f;

		float valueWidth = 1.0f;

		std::vector<std::vector<float>> coordPoint;
		std::vector<float> width{ this->valueWidth };

		bool updateVao = true;
		std::vector<unsigned int> vaoPoints{ 0 };
		unsigned int vaoTurtle = 0;

		bool bodyTurtleDraw = true;

		float angle = 270.0f;
		color::RGB color;

		Window* window;

		double Time = 0.0;
		float speed = 10.0f;


	public:

		Turtle(Window& window);
		~Turtle();

		void setPos(float x, float y);
		void setPos(const math::Vector2& vec2);

		void clear();

		void setSpeed(float speed);
		void move();
		void draw();

		void setAngle(float degree);

		void setColor(float red, float green, float blue, float alpha = 255.0f);
		void setColor(color::RGB color);
		void setColor(color::RGBA color);

		void setWidth(float width);

		void enableDrawBody(bool flag);
	};
}

#endif // !SRC_CORE_RENDERER_TURTLE_HPP_