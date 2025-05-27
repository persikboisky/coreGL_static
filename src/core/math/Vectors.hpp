#ifndef SRC_CORE_MATH_VECTORS_HPP
#define SRC_CORE_MATH_VECTORS_HPP

namespace core
{
	namespace math
	{
		class Vector2;
		class Vector3;
		class Vector4;
		class Matrix4;

		class Vector2 final
		{
		public:
			float x;
			float y;

			Vector2();
			Vector2(float x, float y = 0);
			Vector2(const Vector2 &vec2);

			Vector2 operator+(const Vector2 &vec2);
			Vector2 operator-(const Vector2 &vec2);
			Vector2 operator*(const Vector2 &vec2);
			Vector2 operator/(const Vector2 &vec2);

			Vector2 operator*(const float &value);
			Vector2 operator/(const float &value);

			void operator+=(const Vector2 &vec2);
			void operator-=(const Vector2 &vec2);
			void operator*=(const Vector2 &vec2);
			void operator/=(const Vector2 &vec2);

			bool operator==(const Vector2 &vec2);
			bool operator>(const Vector2 &vec2);
			bool operator<(const Vector2 &vec2);
			bool operator>=(const Vector2 &vec2);
			bool operator<=(const Vector2 &vec2);

			void operator=(const Vector2 &vec2);

			/// @brief находит нормализированный вектор
			/// @param vec2 вектор
			/// @return нормализированный вектор
			static Vector2 normalize(const Vector2 &vec2);

			/// @brief находит длину вектора
			/// @param vec2 вектор
			/// @return длину вектора
			static float length(const Vector2 &vec2);

			/// @brief находит скалярное произведение векторов
			/// @param vec2_1 первый вектор
			/// @param vec2_2 второй вектор
			/// @return скалярное произведение векторов
			static float dot(const Vector2 &vec2_1, const Vector2 &vec2_2);

			/// @brief находит растояние между двумя точками
			/// @param vec2_1 первый вектор
			/// @param vec2_2 второй вектор
			/// @return растояние между двумя точками
			static float distance(const Vector2 &vec2_1, const Vector2 &vec2_2);

			/// @brief находит нормализированный вектор
			/// @return нормализированный вектор
			Vector2 normalize();

			/// @brief нормализирует вектор
			void normal();

			/// @brief находит длину вектора
			/// @return длина вектора
			float length() const;

			/// @brief находит скалярное произведение векторов
			/// @param vec2 вектор
			/// @return скалярное произведение векторов
			float dot(const Vector2 &vec2) const;

			/// @brief находит растояние между двумя точками
			/// @param vec2 вектор
			/// @return растояние между двумя точками
			float distance(const Vector2 &vec2) const;

			static bool sloped(const Vector2 &vec2_1, const Vector2 &vec2);
			bool sloped(const Vector2 &vec2);
		};

		class Vector3 final
		{
		public:
			float x;
			float y;
			float z;

			Vector3();
			Vector3(float x, float y = 0.0f, float z = 0.0f);
			Vector3(const Vector4 &vec4);

			Vector3 operator+(const Vector3 &vec3);
			Vector3 operator-(const Vector3 &vec3);
			Vector3 operator*(const Vector3 &vec3);
			Vector3 operator/(const Vector3 &vec3);

			Vector3 operator*(const float &value);
			Vector3 operator/(const float &value);

			void operator+=(const Vector3 &vec3);
			void operator-=(const Vector3 &vec3);
			void operator*=(const Vector3 &vec3);
			void operator/=(const Vector3 &vec3);

			bool operator==(const Vector3 &vec3);
			bool operator>(const Vector3 &vec3);
			bool operator<(const Vector3 &vec3);
			bool operator>=(const Vector3 &vec3);
			bool operator<=(const Vector3 &vec3);

			void operator=(const Vector3 &vec3);

			/// @brief находит нормализированный вектор
			/// @param vec3 вектор
			/// @return нормализированный вектор
			static Vector3 normalize(const Vector3 &vec3);

			/// @brief находит векторное произведение
			/// @param vec3_1 первый вектор
			/// @param vec3_2 второй вектор
			/// @return векторное произведение
			static Vector3 cross(const Vector3 &vec3_1, const Vector3 &vec3_2);

			/// @brief находит длину вектора
			/// @param vec3 вектор
			/// @return длину вектора
			static float length(const Vector3 &vec3);

			/// @brief находит скалярное произведение векторов
			/// @param vec3_1 первый вектор
			/// @param vec3_2 второй вектор
			/// @return скалярное произведение векторов
			static float dot(const Vector3 &vec3_1, const Vector3 &vec3_2);

			/// @brief находит растояние между двумя точками
			/// @param vec3_1 первый вектор
			/// @param vec3_2 второй вектор
			/// @return растояние между двумя точками
			static float distance(const Vector3 &vec3_1, const Vector3 &vec3_2);

			/// @brief находит нормализированный вектор
			/// @return нормализированный вектор
			Vector3 normalize();

			/// @brief нормализирует вектор
			void normal();

			/// @brief находит длину вектора
			/// @return длину вектора
			float length() const;

			/// @brief находит скалярное произведение векторов
			/// @param vec3 вектор
			/// @return скалярное произведение векторов
			float dot(const Vector3 &vec3) const;

			/// @brief находит растояние между двумя точками
			/// @param vec3 вектор
			/// @return растояние между двумя точками
			float distance(const Vector3 &vec3) const;
		};

		class Vector4 final
		{
		public:
			float x;
			float y;
			float z;
			float w;

			Vector4();
			Vector4(const Vector4 &vec4);
			Vector4(float x, float y = 0.0f, float z = 0.0f, float w = 1.0f);
			Vector4(const Vector3 &vec3, float w = 1.0f);

			Vector4 operator+(const Vector4 &vec4);
			Vector4 operator-(const Vector4 &vec4);
			Vector4 operator*(const Vector4 &vec4);
			Vector4 operator/(const Vector4 &vec4);

			Vector4 operator*(const float &value);
			Vector4 operator/(const float &value);

			void operator+=(const Vector4 &vec4);
			void operator-=(const Vector4 &vec4);
			void operator*=(const Vector4 &vec4);
			void operator/=(const Vector4 &vec4);

			bool operator==(const Vector4 &vec4);
			bool operator>(const Vector4 &vec4);
			bool operator<(const Vector4 &vec4);
			bool operator>=(const Vector4 &vec4);
			bool operator<=(const Vector4 &vec4);

			void operator=(const Vector4 &vec4);

			/// @brief находит нормализированный вектор
			/// @param vec4 вектор
			/// @return нормализированный вектор
			static Vector4 normalize(const Vector4 &vec4);

			/// @brief находит длину вектора
			/// @param vec4 вектор
			/// @return длину вектора
			static float length(const Vector4 &vec4);

			/// @brief находит скалярное произведение векторов
			/// @param vec4_1 первый вектор
			/// @param vec4_2 второй вектор
			/// @return скалярное произведение векторов
			static float dot(const Vector4 &vec4_1, const Vector4 &vec4_2);

			/// @brief находит растояние между двумя точками
			/// @param vec4_1 первый вектор
			/// @param vec4_2 второй вектор
			/// @return растояние между двумя точками
			static float distance(const Vector4 &vec4_1, const Vector4 &vec4_2);

			/// @brief находит нормализированный вектор
			/// @return нормализированный вектор
			Vector4 normalize();

			/// @brief нормализирует вектор
			void normal();

			/// @brief находит длину вектора
			/// @return длину вектора
			float length() const;

			/// @brief находит скалярное произведение векторов
			/// @param vec4 вектор
			/// @return скалярное произведение векторов
			float dot(const Vector4 &vec4) const;

			/// @brief находит растояние между двумя точками
			/// @param vec4 вектор
			/// @return растояние между двумя точками
			float distance(const Vector4 &vec4) const;

			auto operator*(Matrix4 mat4) -> Vector4;
		};
	}
}

#endif // !SRC_CORE_MATH_VECTORS_HPP
