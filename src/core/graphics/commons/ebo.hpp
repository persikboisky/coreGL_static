#pragma once

#include <vector>

namespace core
{
	enum PRIMITIVE;

	class VAO;

	/// @brief структура для работы с ebo
	struct ebo
	{
	private:
		static std::vector<unsigned int> id;
		static unsigned int SelectID;

		static unsigned int SelectVAO;

	public:
		/// @brief включает ebo по его дескриптору
		/// @param id дескриптор
		static void bind(unsigned int id);

		/// @brief создаёт ebo
		/// @param indexes массив индексов
		/// @param sizeOfByte размер массива в байтах
		/// @return дескриптор
		static unsigned int create(unsigned int *indexes, unsigned int sizeOfByte);

		/// @brief создаёт ebo
		/// @param indexes вектор индексов
		/// @return дескриптор
		static unsigned int create(std::vector<unsigned int> indexes);

		/// @brief рисует примитив, используя данные из включенного vao
		/// @param Primitive название примитива
		/// @param nVert кол-во вершин
		static void draw(PRIMITIVE Primitive, unsigned int nVert);

		/// @brief рисует примитив, используя данные из включенного vao
		/// @param Primitive название примитива
		/// @param ebo дескриптор ebo
		/// @param nVert кол-во вершин
		static void draw(PRIMITIVE Primitive, unsigned int ebo, unsigned int nVert);

		/// @brief рисует примитив
		/// @param Primitive название примитива
		/// @param ebo дескриптор ebo
		/// @param vao дескриптор vao
		/// @param nVert кол-во вершин
		static void draw(PRIMITIVE Primitive, unsigned int ebo, unsigned int vao, unsigned int nVert);

		/// @brief рисует примитив
		/// @param Primitive название примитива
		/// @param ebo дескриптор ebo
		/// @param vao объект vao
		/// @param nVert кол-во вершин
		static void draw(PRIMITIVE Primitive, unsigned int ebo, VAO &vao, unsigned int nVert);

		/// @brief удаляет ebo по его дескриптору
		/// @param id дескриптор
		static void Delete(unsigned int id);

		/// @brief удаляет все ebo
		static void DeleteALL();

		/// @brief устанавливает размер точки, если в качестве примитива точка
		/// @param sizePixel размер в пикселях
		static void setSizePoints(float sizePixel);

		/// @brief устанавливает ширину линии, если в качестве примитива линия(ии)
		/// @param width ширина в пикселях
		static void setWidthLine(float width);
	};

	/// @brief класс для работы с ebo
	class EBO
	{
	private:
		unsigned int vao;
		VAO *Vao;

		unsigned int id;
		unsigned int nVert;

		char typeVao = ' ';

		float widthLine = 1.0f;
		float sizePoint = 1.0f;

	public:
		/// @brief конструктор создаёт ebo и его объект
		/// @param indexes массив индексов
		/// @param sizeOfByte размер массива в байтах
		EBO(unsigned int *indexes, unsigned int sizeOfByte);

		/// @brief конструктор создаёт ebo и его объект
		/// @param indexes вектор индексов
		EBO(std::vector<unsigned int> indexes);

		/// @brief дескриптор удаляет ebo и его объект
		~EBO();

		/// @brief привязывает vao к ebo
		/// @param vao дескриптор vao
		void linkVAO(unsigned int vao);

		/// @brief привязывает vao к ebo
		/// @param vao объект vao
		void linkVAO(VAO &vao);

		/// @brief рисует примитив
		/// @param Primitive название примитива
		/// @param nVert кол-во вершин (если не указать, рисует все)
		void draw(PRIMITIVE Primitive, unsigned int nVert = 0);

		/// @brief устанавливает размер точки, если в качестве примитива точка
		/// @param sizePixel размер в пикселях
		void setSizePoints(float sizePixel);

		/// @brief устанавливает ширину линии, если в качестве примитива линия(ии)
		/// @param width ширина в пикселях
		void setWidthLine(float width);
	};
}