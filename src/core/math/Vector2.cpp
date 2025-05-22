#include "Vectors.hpp"
#include <cmath>

using namespace core::math;

Vector2::Vector2() : x(0), y(0) { }
Vector2::Vector2(float x, float y) : x(x), y(y) {}
Vector2::Vector2(const Vector2& vec2) : x(vec2.x), y(vec2.y) {}

Vector2 Vector2::operator+(const Vector2 &vec2)
{
	return Vector2(
		this->x + vec2.x,
		this->y + vec2.y
	);
}

Vector2 Vector2::operator-(const Vector2 &vec2)
{
	return Vector2(
		this->x - vec2.x,
		this->y - vec2.y
	);
}

Vector2 Vector2::operator*(const Vector2 &vec2)
{
	return Vector2(
		this->x * vec2.x,
		this->y * vec2.y
	);
}

Vector2 Vector2::operator/(const Vector2 &vec2)
{
	return Vector2(
		this->x / vec2.x,
		this->y / vec2.y
	);
}

Vector2 Vector2::operator*(const float &value)
{
	return Vector2(
		this->x * value,
		this->y * value
	);
}

Vector2 Vector2::operator/(const float &value)
{
	return Vector2(
		this->x / value,
		this->y / value
	);
}

void Vector2::operator=(const Vector2& vec2)
{
	this->x = vec2.x;
	this->y = vec2.y;
}

Vector2 Vector2::normalize(const Vector2& vec2)
{
	const float LENGTH = Vector2::length(vec2);
	return Vector2(
		vec2.x / LENGTH,
		vec2.y / LENGTH
	);
}

float Vector2::length(const Vector2& vec2)
{
	return sqrtf(powf(vec2.x, 2) + powf(vec2.y, 2));
}

float Vector2::dot(const Vector2& vec2_1, const Vector2& vec2_2)
{
    return vec2_1.x * vec2_2.x + vec2_1.y * vec2_2.y;
}

float Vector2::distance(const Vector2& vec2_1, const Vector2& vec2_2)
{
	return sqrtf(powf(vec2_1.x - vec2_2.x, 2) + powf(vec2_1.y - vec2_2.y, 2));
}

Vector2 Vector2::normalize()
{
	const float LENGTH = this->length();
	return Vector2(
		this->x / LENGTH,
		this->y / LENGTH
	);
}

void Vector2::normal() 
{
	const float LENGTH = this->length();
	this->x /= LENGTH;
	this->y /= LENGTH;
}

float Vector2::length() const
{
	return sqrtf(powf(this->x, 2) + powf(this->y, 2));
}

float Vector2::dot(const Vector2& vec2) const
{
    return this->x * vec2.x + this->y * vec2.y;
}

float Vector2::distance(const Vector2& vec2) const
{
	return sqrtf(powf(this->x - vec2.x, 2) + powf(this->y - vec2.y, 2));
}