
namespace math
{
	struct Vector2;
	struct Vector3;

	struct Vector4 final
	{
		float x;
		float y;
		float z;
		float w;

		Vector4(float x = 0, float y = 0, float z = 0, float w = 1);
		Vector4(float x, Vector3 vector3);
		Vector4(Vector3 vector3, float w = 1);
		Vector4(Vector2 vector2_1, Vector2 vector2_2);
		Vector4(Vector2 vector2, float z = 0, float w = 1);
		Vector4(float x, Vector2 vector2, float w = 1);
		Vector4(float x, float y, Vector2 vector2);

		Vector4 operator + (Vector4 vector4);
		Vector4 operator - (Vector4 vector4);
		Vector4 operator * (Vector4 vector4);
		Vector4 operator / (Vector4 vector4);

		void normalize();
	};
}