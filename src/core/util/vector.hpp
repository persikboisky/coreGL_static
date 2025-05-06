#pragma once

#include <vector>

namespace core
{
	namespace vector
	{
		int searchElementForValue(std::vector<int> vec, int value);
		int searchElementForValue(std::vector<unsigned int> vec, unsigned int value);
		int searchElementForValue(std::vector<unsigned short> vec, unsigned short value);

		std::vector<float> arrayToVector_float(float* array, unsigned int size_array);
		std::vector<int> arrayToVector_int(int* array, unsigned int size_array);
		std::vector<char> arrayToVector_char(char* array, unsigned int size_array);
	}
}