#include "buildMatrix.hpp"
#include "Matrix4.hpp"
#include "Vectors.hpp"
#include <math.h>

constexpr auto PI = 3.141592;

using namespace math;

Matrix4 math::getScaleMatrix(Vector3 vec3)
{
	float mat[16] = {
		vec3.x, 0, 0, 0,
		0, vec3.y, 0, 0,
		0, 0, vec3.z, 0,
		0, 0, 0, 1
	};

	return Matrix4(mat);
}

Matrix4 math::getScaleMatrix(Matrix4 mat4, Vector3 vec3)
{
	return Matrix4(Matrix4::Change(
		mat4.getArray(),
		math::getScaleMatrix(vec3).getArray())
	);
}

Matrix4 math::getTranslateMatrix(Vector3 vec3)
{
	float mat[16] = {
		1, 0, 0, vec3.x,
		0, 1, 0, vec3.y,
		0, 0, 1, vec3.z,
		0, 0, 0, 1
	};

	return Matrix4(mat);
}

Matrix4 math::getTranslateMatrix(Matrix4 mat4, Vector3 vec3)
{
	return Matrix4(Matrix4::Change(
		mat4.getArray(), 
		math::getTranslateMatrix(vec3).getArray())
	);
}

Matrix4 math::getRotateMatrix(float angle, Vector3 vec3)
{
	float matX[16] = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	float matY[16] = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	float matZ[16] = {
	    1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	if (vec3.x == 1)
	{
		matX[5] = cos(angle);
		matX[6] = -sin(angle);
		matX[9] = sin(angle);
		matX[10] = cos(angle);
	}

	if (vec3.y == 1)
	{
		matX[0] = cos(angle);
		matX[2] = -sin(angle);
		matX[8] = sin(angle);
		matX[10] = cos(angle);
	}

	if (vec3.z == 1)
	{
		matX[0] = cos(angle);
		matX[1] = -sin(angle);
		matX[4] = sin(angle);
		matX[5] = cos(angle);
	}

	return math::Matrix4::Change(
		matX,
		math::Matrix4::Change(
			matY,
			matZ
		)
	);
}

Matrix4 math::getRotateMatrix(Matrix4 mat4, float angle, Vector3 vec3)
{
	return Matrix4(Matrix4::Change(
		mat4.getArray(),
		math::getRotateMatrix(angle, vec3).getArray()
	));
}

Matrix4 math::getPerspectiveMatrix(float fov, float aspect, float near, float far)
{
	float mat[16] = {
		1.0f / tan(PI / 180.0f * fov / 2.0f) * aspect, 0, 0, 0,
		0, 1.0f / tan(PI / 180.0f * fov / 2.0f), 0, 0,
		0, 0, -1.0f * ((far + near) / (near - far)), -1.0f * (2.0f * far * near / (far - near)),
		0, 0, -1.0f, 0
	};

	return Matrix4(mat);
}

Matrix4 math::getLookAtMatrix(Vector3 pos, Vector3 up, Vector3 target)
{
	float mat1[16] = {
		0, 0, 0, 0,
		up.x, up.y, up.z, 0,
		target.x, target.y, target.z, 0,
		0, 0, 0, 1
	};

	float mat2[16] = {
		1, 0, 0, -pos.x,
		0, 1, 0, -pos.y,
		0, 0, 1, -pos.z,
		0, 0, 0, 1
	};

	return Matrix4();
}
