#ifndef SRC_CORE_GRAPHICS_SHADER_HPP_
#define SRC_CORE_GRAPHICS_SHADER_HPP_

#include "../../math/Vectors.hpp"
#include "../../math/Matrixes.hpp"
#include <vector>

namespace core
{
	struct shader
	{
	private:
		static std::vector<unsigned int> id;
		static unsigned int SelectID;

	protected:
		static unsigned int getSelectID();

	public:
		static unsigned int createFromCode(const char* codeVert, const char* codeFrag);
		static unsigned int createFromFile(const char* pathToVert, const char* pathToFrag);

		static void use(unsigned int id);

		/// @brief передаём матрицу в юниформ переменную шейдера
		/// @param matrix матрица
		/// @param name название юниформ переменной
		static void UniformMat4(math::Matrix4 matrix, const char* name);

		/// @brief передаёт значение типа float в юниформ переменную шейдера
		/// @param value значение типа float 
		/// @param name название юниформ переменной
		static void Uniform1F(const float value, const char* name);


		static void Uniform2F(core::math::Vector2 vec2, const char* name);
		static void Uniform3F(core::math::Vector3 vec3, const char* name);
		static void Uniform4F(core::math::Vector4 vec4, const char* name);

		// static void Uniform1I(glm::ivec1 value, const char* name);
		// static void Uniform2I(glm::ivec2 value, const char* name);

		/// @brief передаёт значение типа Sampler2D в юниформ переменную шейдера
		/// @param value значение типа Sampler2D
		/// @param name название юниформ переменной
		static void UniformSample2D(int value, const char* name);

		static void Delete(unsigned int id);
		static void DeleteALL();
	};

	class Shader : private shader
	{
	private:
		unsigned int id;

	public:
		/// @brief конструктор, создаёт шейдер
		/// @param pathVert путь к вершинному шейдеру
		/// @param pathFrag путь к фрагментному шейдеру
		Shader(const char* pathVert, const char* pathFrag);

		~Shader();

		// ���������� �� ����� shader::getSelectID()
		//bool select = false;

		/// @brief получает дескриптор шейдера
		/// @return дескриптор
		unsigned int getID() const;

		/// @brief включает шейдер
		void use() const;

		/// @brief передаём матрицу в юниформ переменную шейдера
		/// @param matrix матрица
		/// @param name название юниформ переменной
		void UniformMat4(math::Matrix4 matrix, const char* name) const;

		/// @brief передаёт значение типа float в юниформ переменную шейдера
		/// @param value значение типа float 
		/// @param name название юниформ переменной
		void Uniform1F(const float value, const char* name) const;
		void Uniform2F(core::math::Vector2 vec2, const char* name) const;
		void Uniform3F(core::math::Vector3 vec3, const char* name) const;
		void Uniform4F(core::math::Vector4 vec4, const char* name) const;

		/*void Uniform1I(glm::ivec1 value, const char* name) const;
		void Uniform2I(glm::ivec2 value, const char* name) const;*/

		/// @brief передаёт значение типа Sampler2D в юниформ переменную шейдера
		/// @param value значение типа Sampler2D
		/// @param name название юниформ переменной		
		void UniformSample2D(int value, const char* name) const;
	};
}

#endif // !SRC_CORE_GRAPHICS_SHADER_HPP_