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
			float x, y;

			Vector2();
			Vector2(float x, float y = 0);
			Vector2(const Vector2& vec2);

			Vector2 operator+(const Vector2& vec2);
			Vector2 operator-(const Vector2& vec2);
			Vector2 operator*(const Vector2& vec2);
			Vector2 operator/(const Vector2& vec2);

			Vector2 operator*(const float& value);
			Vector2 operator/(const float& value);

			static Vector2 normalize(const Vector2& vec2);

			static float length(const Vector2& vec2);
			static float dot(const Vector2& vec2_1, const Vector2& vec2_2);
			static float distance(const Vector2& vec2_1, const Vector2& vec2_2);

			Vector2 normalize();
			void normal();

			/// @brief находит длину вектора
			/// @return длина вектора
			float length() const;

			float dot(const Vector2& vec2) const;

			/// @brief находит растояние от текущего вектора до передоваемового в функцию
			/// @param vec2 вектор
			/// @return длина
			float distance(const Vector2& vec2) const;
		};

		class Vector3 final
		{
		public:
			float x, y, z;

			Vector3();
			Vector3(float x, float y = 0.0f, float z = 0.0f);
			Vector3(const Vector4& vec4);

			Vector3 operator+(const Vector3& vec3);
			Vector3 operator-(const Vector3& vec3);
			Vector3 operator*(const Vector3& vec3);
			Vector3 operator/(const Vector3& vec3);

			Vector3 operator*(const float& value);
			Vector3 operator/(const float& value);

			static Vector3 normalize(const Vector3& vec3);
			static Vector3 cross(const Vector3& vec3_1, const Vector3& vec3_2);

			static float length(const Vector3& vec3);
			static float dot(const Vector3& vec3_1, const Vector3& vec3_2);
			static float distance(const Vector3& vec3_1, const Vector3& vec3_2);

			Vector3 normalize();
			void normal();

			float length() const;
			float dot(const Vector3& vec3) const;

			/// @brief находит растояние от текущего вектора до передоваемового в функцию
			/// @param vec3 вектор
			/// @return длина
			float distance(const Vector3& vec3) const;
		};

		class Vector4 final
		{
		public:
			float x, y, z, w;

			Vector4();
			Vector4(const Vector4& vec4);
			Vector4(float x, float y = 0.0f, float z = 0.0f, float w = 1.0f);
			Vector4(const Vector3& vec3, float w = 1.0f);

			Vector4 operator+(const Vector4& vec4);
			Vector4 operator-(const Vector4& vec4);
			Vector4 operator*(const Vector4& vec4);
			Vector4 operator/(const Vector4& vec4);

			Vector4 operator*(const float& value);
			Vector4 operator/(const float& value);

			static Vector4 normalize(const Vector4& vec4);

			static float length(const Vector4& vec4);
			static float dot(const Vector4& vec4_1, const Vector4& vec4_2);
			static float distance(const Vector4& vec4_1, const Vector4& vec4_2);

			Vector4 normalize();
			void normal();

			float length() const;
			float dot(const Vector4& vec4) const;

			/// @brief находит растояние от текущего вектора до передоваемового в функцию
			/// @param vec4 вектор
			/// @return длина
			float distance(const Vector4& vec4) const;

			auto operator * (Matrix4 mat4) -> Vector4;
		};
	}
}

#endif // !SRC_CORE_MATH_VECTORS_HPP
