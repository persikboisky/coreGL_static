#include "Vector2.hpp"
#include <math.h>

using namespace math;

Vector2::Vector2(float x, float y) : x(x), y(y)
{

}

Vector2 Vector2::operator + (Vector2 vector2)
{
	return Vector2(
		this->x + vector2.x,
		this->y + vector2.y
	);
}

Vector2 Vector2::operator - (Vector2 vector2)
{
	return Vector2(
		this->x - vector2.x,
		this->y - vector2.y
	);
}

Vector2 Vector2::operator * (Vector2 vector2)
{
	return Vector2(
		this->x * vector2.x,
		this->y * vector2.y
	);
}

Vector2 Vector2::operator / (Vector2 vector2)
{
	return Vector2(
		this->x / vector2.x,
		this->y / vector2.y
	);
}

void math::Vector2::normalize()
{
	float length = (float)sqrt(pow(this->x, 2) + pow(this->y, 2));
	this->x = x / length;
	this->y = y / length;
}