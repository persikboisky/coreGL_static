
namespace math
{

	class Matrix4 final
	{
	private:
		float matrix[16];

	public:
		Matrix4(float value = 1.0f);
		Matrix4(float value[]);
		~Matrix4();

		float* getArray();

		static float* Change(float mat1[], float mat2[]);

		//Matrix4 operator = (Matrix4 matrix);
	};

}