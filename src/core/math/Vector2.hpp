
namespace math
{
	struct Vector2 final
	{
		float x;
		float y;

		Vector2(float x = 0, float y = 0);

		Vector2 operator + (Vector2 vector2);
		Vector2 operator - (Vector2 vector2);
		Vector2 operator * (Vector2 vector2);
		Vector2 operator / (Vector2 vector2);

		void normalize();
	};
}