#include "Vector3.hpp"
#include "Vector2.hpp"
#include <math.h>

constexpr float PI = 3.141592f;

using namespace math;

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
}

Vector3::Vector3(Vector2 vector2, float z) : x(vector2.x), y(vector2.y), z(z)
{
}

Vector3::Vector3(float x, Vector2 vector2) : x(x), y(vector2.y), z(vector2.x)
{
}

Vector3 Vector3::operator + (Vector3 vector3)
{
	return Vector3(
		this->x + vector3.x,
		this->y + vector3.y,
		this->z + vector3.z
	);
}

Vector3 Vector3::operator - (Vector3 vector3)
{
	return Vector3(
		this->x - vector3.x,
		this->y - vector3.y,
		this->z - vector3.z
	);
}

Vector3 Vector3::operator * (Vector3 vector3)
{
	return Vector3(
		this->x * vector3.x,
		this->y * vector3.y,
		this->z * vector3.z
	);
}

Vector3 Vector3::operator / (Vector3 vector3)
{
	return Vector3(
		this->x / vector3.x,
		this->y / vector3.y,
		this->z / vector3.z
	);
}

Vector3 math::Vector3::cross(const Vector3& vector3)
{
	return Vector3(
		this->y * vector3.z - this->z * vector3.y,
		this->z * vector3.x - this->x * vector3.z,
		this->x * vector3.y - this->y * vector3.x
	);
}

inline float Vector3::length() const
{
	return sqrtf(
		pow(this->x, 2) + 
		pow(this->y, 2) + 
		pow(this->z, 2)
	);
}

float Vector3::dot(const Vector3& vector3) const
{
	return this->x * vector3.x + this->y * vector3.y + this->z + vector3.z;
}

inline float Vector3::distance(const Vector3& vector3) const
{
	return sqrtf(
		pow(this->x - vector3.x, 2) + 
		pow(this->y - vector3.y, 2) + 
		pow(this->y - vector3.y, 2)
	);
}

inline float Vector3::getAngle(const Vector3 vector3) const
{
	return acosf(
		this->dot(vector3) / 
		(this->length() * vector3.length())) / 
		3.141592f * 180.0f;
}

void Vector3::normalize()
{
	const float LENGTH = this->length();

	this->x = x / LENGTH;
	this->y = y / LENGTH;
	this->z = z / LENGTH;
}