#ifndef SRC_MATH_VECTOR3_HPP_
#define SRC_MATH_VECTOR3_HPP_

namespace math
{
	struct Vector2;

	struct Vector3 final
	{
		float x;
		float y;
		float z;

		Vector3(float x = 0, float y = 0, float z = 0);
		Vector3(Vector2 vector, float z = 0);
		Vector3(float x, Vector2 vector);

		Vector3 operator + (Vector3 vector3);
		Vector3 operator - (Vector3 vector3);
		Vector3 operator * (Vector3 vector3);
		Vector3 operator / (Vector3 vector3);
		Vector3 cross(const Vector3& vector3);

		float length() const;
		float dot(const Vector3& vector3) const;
		float distance(const Vector3& vector3) const;
		float getAngle(const Vector3 vector3) const;

		void normalize();
	};
}

#endif // !SRC_MATH_VECTOR3_HPP_