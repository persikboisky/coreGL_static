#include "Vector4.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include <math.h>

using namespace math;

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

Vector4::Vector4(float x, Vector3 vector3) : x(x), y(vector3.x), z(vector3.y), w(vector3.z)
{
}

Vector4::Vector4(Vector3 vector3, float w) : x(vector3.x), y(vector3.y), z(vector3.z), w(w)
{
}

Vector4::Vector4(Vector2 vector2_1, Vector2 vector2_2) : x(vector2_1.x), y(vector2_1.y), z(vector2_2.x), w(vector2_2.y)
{
}

Vector4::Vector4(Vector2 vector2, float z, float w) : x(vector2.x), y(vector2.y), z(z), w(w)
{
}

Vector4::Vector4(float x, Vector2 vector2, float w) : x(x), y(vector2.x), z(vector2.y), w(w)
{
}

Vector4::Vector4(float x, float y, Vector2 vector2) : x(x), y(y), z(vector2.x), w(vector2.y)
{
}

Vector4 Vector4::operator + (Vector4 vector4)
{
	return Vector4(
		this->x + vector4.x,
		this->y + vector4.y,
		this->z + vector4.z,
		this->w + vector4.w
	);
}

Vector4 Vector4::operator - (Vector4 vector4)
{
	return Vector4(
		this->x - vector4.x,
		this->y - vector4.y,
		this->z - vector4.z,
		this->w - vector4.w
	);
}

Vector4 Vector4::operator * (Vector4 vector4)
{
	return Vector4(
		this->x * vector4.x,
		this->y * vector4.y,
		this->z * vector4.z,
		this->w * vector4.w
	);
}

Vector4 Vector4::operator / (Vector4 vector4)
{
	return Vector4(
		this->x / vector4.x,
		this->y / vector4.y,
		this->z / vector4.z,
		this->w / vector4.w
	);
}

void Vector4::normalize()
{
	float length = (float)sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) + pow(this->w, 2));
	this->x = x / length;
	this->y = y / length;
	this->z = z / length;
	this->w = w / length;
}