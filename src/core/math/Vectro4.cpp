#include "Vectors.hpp"
#include "Matrixes.hpp"
#include <cmath>

using namespace core::math;

Vector4::Vector4() : x(0), y(0), z(0), w(1.0f) { }

Vector4::Vector4(const Vector4& vec4) : x(vec4.x), y(vec4.y), z(vec4.z), w(vec4.w) {}

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Vector4::Vector4(const Vector3& vec3, float w) : x(vec3.x), y(vec3.y), z(vec3.z), w(w) { }

Vector4 Vector4::operator+(const Vector4 &vec4)
{
    return Vector4(
        this->x + vec4.x,
        this->y + vec4.y,
        this->z + vec4.z,
        this->w + vec4.w
    );
}

Vector4 Vector4::operator-(const Vector4 &vec4)
{
    return Vector4(
        this->x - vec4.x,
        this->y - vec4.y,
        this->z - vec4.z,
        this->w - vec4.w
    );
}

Vector4 Vector4::operator*(const Vector4 &vec4)
{
    return Vector4(
        this->x * vec4.x,
        this->y * vec4.y,
        this->z * vec4.z,
        this->w * vec4.w
    );
}

Vector4 Vector4::operator/(const Vector4 &vec4)
{
    return Vector4(
        this->x / vec4.x,
        this->y / vec4.y,
        this->z / vec4.z,
        this->w / vec4.w
    );
}

Vector4 Vector4::operator*(const float &value)
{
    return Vector4(
        this->x * value,
        this->y * value,
        this->z * value,
        this->w * value
    );
}

Vector4 Vector4::operator/(const float &value)
{
    return Vector4(
        this->x / value,
        this->y / value,
        this->z / value,
        this->w / value
    );
}

Vector4 Vector4::normalize(const Vector4 &vec4)
{
    const float LENGTH = Vector4::length(vec4);
    return Vector4(
        vec4.x / LENGTH,
        vec4.y / LENGTH,
        vec4.z / LENGTH,
        vec4.w / LENGTH
    );
}

float Vector4::length(const Vector4 &vec4)
{
    return sqrtf(
        powf(vec4.x, 2) +
        powf(vec4.y, 2) +
        powf(vec4.z, 2) +
        powf(vec4.w, 2)
    );
}

float Vector4::dot(const Vector4 &vec4_1, const Vector4 &vec4_2)
{
    return vec4_1.x * vec4_2.x + vec4_1.y * vec4_2.y + 
    vec4_1.z * vec4_2.z + vec4_1.w * vec4_2.w;
}

float Vector4::distance(const Vector4&  vec4_1, const Vector4& vec4_2)
{
    return sqrtf(
        powf(vec4_1.x - vec4_2.x, 2) +
        powf(vec4_1.y - vec4_2.y, 2) +
        powf(vec4_1.z - vec4_2.z, 2) +
        powf(vec4_1.w - vec4_2.w, 2)
    );
}

Vector4 Vector4::normalize()
{
    const float LENGTH = this->length();
    return Vector4 (
        this->x / LENGTH,
        this->y / LENGTH,
        this->z / LENGTH,
        this->w / LENGTH
    );
}

void Vector4::normal()
{
    const float LENGTH = this->length();
    this->x /= LENGTH;
    this->y /= LENGTH;
    this->z /= LENGTH;
    this->w /= LENGTH;
}

float Vector4::length() const
{
    return sqrtf(
        powf(this->x, 2) +
        powf(this->y, 2) +
        powf(this->z, 2) +
        powf(this->w, 2)
    );
}

float Vector4::dot(const Vector4&  vec4) const
{
    return this->x * vec4.x + this->y * vec4.y + 
    this->z * vec4.z + this->w * vec4.w;
}

float Vector4::distance(const Vector4& vec4) const
{
    return sqrt(
        powf(this->x - vec4.x, 2) +
        powf(this->y - vec4.y, 2) +
        powf(this->z - vec4.z, 2) +
        powf(this->w - vec4.w, 2)
    );
}

auto Vector4::operator*(Matrix4 mat4) -> Vector4
{
    return Matrix4::multiply(Vector4(this->x, this->y, this->z, this->w), mat4.getArray());
}
