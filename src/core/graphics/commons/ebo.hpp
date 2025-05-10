#pragma once

#include <vector>

namespace core
{
	enum PRIMITIVE;

	class VAO;

	struct ebo
	{
	private:
		static std::vector<unsigned int> id;
		static unsigned int SelectID;

		static unsigned int SelectVAO;

	public:
		static void bind(unsigned int id);

		static unsigned int create(unsigned int* indices, unsigned int sizeOfByte);
		static unsigned int create(std::vector<unsigned int> indices);

		static void draw(PRIMITIVE Primitive, unsigned int nVert);
		static void draw(PRIMITIVE Primitive, unsigned int ebo, unsigned int nVert);
		static void draw(PRIMITIVE Primitive, unsigned int ebo, unsigned int vao, unsigned int nVert);
		static void draw(PRIMITIVE Primitive, unsigned int ebo, VAO& vao, unsigned int nVert);

		static void Delete(unsigned int id);
		static void DeleteALL();

		static void setSizePoints(float sizePixel);
		static void setWidthLine(float width);
	};

	class EBO
	{
	private:
		unsigned int vao;
		VAO* Vao;

		unsigned int id;
		unsigned int nVert;

		char typeVao = ' ';

		float widthLine = 1.0f;
		float sizePoint = 1.0f;

	public:
		EBO(unsigned int* indices, unsigned int sizeOfByte);
		EBO(std::vector<unsigned int> indices);

		~EBO();

		void linkVAO(unsigned int vao);
		void linkVAO(VAO& vao);

		void draw(PRIMITIVE Primitive, unsigned int nVert = 0);

		void setSizePoints(float sizePixel);
		void setWidthLine(float width);
	};
}