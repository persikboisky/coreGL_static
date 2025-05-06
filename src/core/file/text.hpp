#ifndef SRC_CORE_LOADERS_TEXT_HPP_
#define SRC_CORE_LOADERS_TEXT_HPP_

#include <string>

namespace core
{
	/// @brief структура для работы с текстом
	struct text
	{
		/// @brief читает файл
		/// @param path путь к файлу
		/// @return текст файла
		static std::string load(const char* path);
	};
}

#endif // !SRC_CORE_LOADERS_TEXT_HPP_
