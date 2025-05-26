#include "Vectors.hpp"
#include <cmath>

using namespace core::math;

Vector3::Vector3() : x(0), y(0), z(0) { }

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector4& vec4): x(vec4.x), y(vec4.y), z(vec4.z) { }

Vector3 Vector3::operator+(const Vector3 &vec3)
{
    return Vector3(
        this->x + vec3.x,
        this->y + vec3.y,
        this->z + vec3.z
    );
}

Vector3 Vector3::operator-(const Vector3 &vec3)
{
    return Vector3(
        this->x - vec3.x,
        this->y - vec3.y,
        this->z - vec3.z
    );
}

Vector3 Vector3::operator*(const Vector3 &vec3)
{
    return Vector3(
        this->x * vec3.x,
        this->y * vec3.y,
        this->z * vec3.z
    );
}

Vector3 Vector3::operator/(const Vector3 &vec3)
{
    return Vector3(
        this->x / vec3.x,
        this->y / vec3.y,
        this->z / vec3.z
    );
}

Vector3 Vector3::operator*(const float &value)
{
    return Vector3 (
        this->x * value,
        this->y * value,
        this->z * value
    );
}

Vector3 Vector3::operator/(const float &value)
{
    return Vector3 (
        this->x / value,
        this->y / value,
        this->z / value
    );
}

void Vector3::operator=(const Vector3& vec3)
{
    this->x = vec3.x;
    this->y = vec3.y;
    this->z = vec3.z;
}

Vector3 Vector3::normalize(const Vector3& vec3) 
{
    const float length = Vector3::length(vec3);
    return Vector3 (
        vec3.x / length,
        vec3.y / length,
        vec3.z / length
    );
}

Vector3 Vector3::cross(const Vector3& vec3_1, const Vector3& vec3_2)
{
    return Vector3(
        vec3_1.y * vec3_2.z - vec3_1.z * vec3_2.y,
        vec3_1.z * vec3_2.x - vec3_1.x * vec3_2.z,
        vec3_1.x * vec3_2.y - vec3_1.y * vec3_2.x
    );
}

float Vector3::length(const Vector3& vec3)
{
    return sqrtf(powf(vec3.x, 2) + powf(vec3.y, 2) + powf(vec3.z, 2));
}

float Vector3::dot(const Vector3& vec3_1, const Vector3&  vec3_2) 
{
    return vec3_1.x * vec3_2.x + vec3_1.y * vec3_2.y + vec3_1.z * vec3_2.z; 
}

float Vector3::distance(const Vector3&  vec3_1, const Vector3&  vec3_2)
{
    return sqrtf(
        powf(vec3_1.x - vec3_2.x, 2) + 
        powf(vec3_1.y - vec3_2.y, 2) + 
        powf(vec3_1.z - vec3_2.z, 2)
    );
}

Vector3 Vector3::normalize()
{
    const float LENGTH = this->length();
    return Vector3(
        this->x / LENGTH,
        this->y / LENGTH,
        this->z / LENGTH
    );
}

void Vector3::normal()
{
    const float LENGTH = this->length();
    this->x /= LENGTH;
    this->y /= LENGTH;
    this->z /= LENGTH;
}

float Vector3::length() const
{
    return sqrtf(powf(this->x, 2) + powf(this->y, 2) + powf(this->z, 2));
}

float Vector3::dot(const Vector3&  vec3) const
{
    return this->x * vec3.x + this->y * vec3.y + this->z * vec3.z;
}

float Vector3::distance(const Vector3& vec3) const
{
    return sqrtf(
        powf(this->x - vec3.x, 2) + 
        powf(this->y - vec3.y, 2) + 
        powf(this->z - vec3.z, 2)
    );
}