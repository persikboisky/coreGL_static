#ifndef SRC_CORE_FILE_WAV_HPP_
#define SRC_CORE_FILE_WAV_HPP_

#include <string>
#include <vector>
#include <cstdint>

typedef int ALsizei;

namespace core
{
	namespace wav
	{
		/// @brief считавает wav файл
		/// @param path путь к файлу
		/// @param channels адрес на переменную для хранения кол-ва каналов
		/// @param sampleRate адрес на переменную для хранения частоты дискретизации
		/// @param bitsPerSample адрес на переменную для хранения бит/сэмпл
		/// @param size адрес на переменную для хранения размера
		/// @return возвращает вектор в котором хранятся сэмплы
		std::vector<char> load(const char* path, std::uint8_t& channels, std::int32_t& sampleRate, std::uint8_t& bitsPerSample, ALsizei& size);
	}
}

#endif // !SRC_CORE_FILE_WAV_HPP_