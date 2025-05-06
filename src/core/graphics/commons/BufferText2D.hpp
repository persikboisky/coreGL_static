#pragma once
#include "../../math/Vectors.hpp"
#include "../../math/Matrixes.hpp"
#include <string>
#include <vector>

namespace core
{
	enum primitive;

	class Shader;
	class Window;

	struct position_2f;
	struct size_2f;
	struct color_rgba;
	struct font;
	struct style;

	class BufferText2D
	{
	private:
		static Shader* shader2D;
		static unsigned int n_Buffer;
		font* Font;

		bool vaoCompile = true;
		std::vector<float> vertexes;

		unsigned int vao = 0;
		unsigned int n_vertex = 0;

		Window* window = nullptr;

	public:
		BufferText2D();
		~BufferText2D();

		void linkFont(font &Font);
		void linkFont(font*& Font);

		void linkWindow(Window& window);
		void linkWindow(Window*& window);

		void addText(
			std::string text,
			float x,
			float y,
			float length = 1.0,
			float c_red = 255.0,
			float c_green = 255.0,
			float c_blue = 255.0,
			float c_alpha = 255.0,
			float RowingBetweenTheSymbols = 0.0f
		);

		//void addText(
		//	std::string text,
		//	position_2f pos,
		//	size_2f size,
		//	color_rgba color
		//);

		void DeleteText();

		void render();
	};
}