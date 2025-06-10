
namespace core
{
	namespace math
	{
		/// @brief число пи
		constexpr double PI = 3.1415926535;

		/// @brief переводит градусы в радианы
		/// @param degrees градусы
		/// @return радианы
		float radians(float degrees);

		/// @brief переводит радианы в градусы
		/// @param radians радианы
		/// @return градусы
		float degrees(float radians);
	}
}