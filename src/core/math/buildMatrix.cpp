#include "buildMatrix.hpp"
#include "Matrix4.hpp"
#include "Vector3.hpp"
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

	const float SIN_ANGLE = sin(angle);
	const float COS_ANGLE = cos(angle);

	if (vec3.x == 1)
	{
		matX[5] = COS_ANGLE;
		matX[6] = -SIN_ANGLE;
		matX[9] = SIN_ANGLE;
		matX[10] = COS_ANGLE;
	}

	if (vec3.y == 1)
	{
		matX[0] = COS_ANGLE;
		matX[2] = -SIN_ANGLE;
		matX[8] = SIN_ANGLE;
		matX[10] = COS_ANGLE;
	}

	if (vec3.z == 1)
	{
		matX[0] = COS_ANGLE;
		matX[1] = -SIN_ANGLE;
		matX[4] = SIN_ANGLE;
		matX[5] = COS_ANGLE;
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
	const float TAN_FOV = tan(fov / 2.0f);
	const float DIFFERENCE_FAR_ASPECT = far - near;

	float mat[16] = {
		1.0f / (TAN_FOV * aspect), 0, 0, 0,
		0, 1.0f / TAN_FOV, 0, 0,
		0, 0, -(far + near) / DIFFERENCE_FAR_ASPECT, -1.0f,
		0, 0, -((2.0f * far * near) / DIFFERENCE_FAR_ASPECT), 0
	};

	return Matrix4(mat);
}

Matrix4 math::getLookAtMatrix(const Vector3& pos, const Vector3& up, const Vector3& target)
{
	Vector3 vecUp = Vector3(0, 1, 0);
	Vector3 vecTarget = Vector3(0, 0, -1);
	Vector3 vecPos = Vector3(0, 0, 4);

	Vector3 forward = vecPos - vecTarget;
	forward.normalize();

	Vector3 vecLeft = forward.cross(vecUp);
	vecLeft.normalize();

	vecUp = vecLeft.cross(forward);
		
	float matLookAt[16] = {
		vecLeft.x, vecLeft.y, vecLeft.z,  -vecLeft.dot(pos),
		vecUp.x,   vecUp.y,   vecUp.z,    -vecUp.dot(pos),
		-forward.x, -forward.y, -forward.z,   forward.dot(pos),
		0,         0,         0,           1
	};

	float matTranslate[16] = {
		1, 0, 0, -pos.x,
		0, 1, 0, -pos.y,
		0, 0, 1, -pos.z,
		0, 0, 0,  1
	};

	return Matrix4(Matrix4::Change(matLookAt, matTranslate));
}
