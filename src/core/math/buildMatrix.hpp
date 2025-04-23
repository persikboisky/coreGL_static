#ifndef SRC_CORE_MATH_BUILDMATRIX_HPP_
#define SRC_CORE_MATH_BUILDMATRIX_HPP_

namespace math
{
	class Matrix4;
	struct Vector3;

	Matrix4 getScaleMatrix(Vector3 vec3);
	Matrix4 getScaleMatrix(Matrix4 mat4, Vector3 vec3);

	Matrix4 getTranslateMatrix(Vector3 vec3);
	Matrix4 getTranslateMatrix(Matrix4 mat4, Vector3 vec3);

	Matrix4 getRotateMatrix(float angle, Vector3 vec3);
	Matrix4 getRotateMatrix(Matrix4 mat4, float angle, Vector3 vec3);

	Matrix4 getPerspectiveMatrix(float FOV, float aspect, float near, float far);

	Matrix4 getLookAtMatrix(Vector3 pos, Vector3 up, Vector3 target);
}

#endif // !SRC_CORE_MATH_BUILDMATRIX_HPP_