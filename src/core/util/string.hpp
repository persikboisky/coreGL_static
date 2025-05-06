#include <string>

namespace core
{
	namespace string
	{
		std::string searchFromString(std::string search_string, std::string string);
		std::string searchFromFile(std::string search_string, const char* path);
	}
}