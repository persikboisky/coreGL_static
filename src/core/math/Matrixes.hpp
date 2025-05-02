#ifndef SRC_MATH_MATRIXES_HPP_
#define SRC_MATH_MATRIXES_HPP_

namespace math
{
	class Vector4;
	class Vector3;

	class Matrix4 final
	{
	private:
		float mat[16];

	public:
        /// @brief конструктор матрицы, создаёт матрицу
        /// @param diagonal значение, которым заполняется по диагонали матрица
        Matrix4(float diagonal = 1.0f);

        /// @brief конструктор матрицы, создаёт матрицу
        /// @param mat4 массив[16], в виде матрицы
        Matrix4(float mat4[16]);

        /// @brief возвращает массив матрицы
        /// @return float[16]
        float *getArray();

		/// @brief перемножает матрицы
		/// @param mat1 массив первой матрицы
		/// @param mat2 массив второй матрицы
		/// @return float[16] 
		static float* multiply(float mat1[16], float mat2[16]);

		/// @brief умножает вектор на матрицу
		/// @param vec четырёхмерный вектор (Кватернион)
		/// @param mat матрица
		/// @return четырёхмерный вектор (Кватернион)
		static Vector4 multiply(Vector4 vec, float mat[16]);

		auto operator * (Matrix4 mat4) -> Matrix4;
		auto operator * (Vector4 vec4) -> Vector4;
		void operator *= (Matrix4 mat4);

		/// @brief создаёт матрицу масштабирования
		/// @param vecScale вектор коэффициентов масштабирования 
		/// @return матрица масштабирования
		static Matrix4 getScale(Vector3 vecScale);

		/// @brief создаёт матрицу перемещения
		/// @param vecTranslate вектор перемещения
		/// @return матрица перемещения
		static Matrix4 getTranslate(Vector3 vecTranslate);

		/// @brief создаёт матрицу поворота
		/// @param angle угол поворота в радианах
		/// @param axises вектор осей поворота (Пример: math::vector3(1, 0, 0) - означает поворот по оси x и z);
		/// @return матрица поворота
		static Matrix4 getRotate(float angle, const Vector3& axises);

		/// @brief создаёт перспективную матрицу
		/// @param fovToRadians угол обзора в радианах
		/// @param aspect соотношение сторон (ширина окна / высота окна)
		/// @param near ближняя плоскость среза (обычно 0.01)
		/// @param far дальняя плоскость среза (или дальность прорисовки)
		/// @return перспективная матрица
		static Matrix4 getPerspective(float fovToRadians, float aspect, float near, float far);

		/// @brief создаёт видовую матрицу
		/// @param pos позиция (откудого смотрит)
		/// @param target цель (куда смотрит)
		/// @param up верх (Пример: math::Vector3(0, 1, 0) - означает что верх совпадает с осью Y)
		/// @return видовая матрица
		static Matrix4 getLookAt(Vector3 pos, Vector3 target, Vector3 up);
	};
}

#endif // !SRC_MATH_MATRIXES_HPP_
