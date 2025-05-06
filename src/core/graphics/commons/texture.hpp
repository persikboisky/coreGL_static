
#include <vector>

namespace core
{
    struct texture
    {
    private:
        static std::vector<unsigned int> id;

    public:
        /// @brief привязка текстуры
        /// @param id дескриптор текстуры
        /// @param Sample индекс привязки (этот индификатор нужен для шейдера(uniform Sample2D))
        static void bind(unsigned int id, unsigned int Sample = 0);

        /// @brief загружает текстуру из массивы цветов
        /// @param png_code массив
        /// @param width ширина
        /// @param height высота
        /// @param channels кол-во каналов
        /// @return возвращает дескриптор текстуры
        static unsigned int load(unsigned char* png_code, int width, int height, int channels);

        /// @brief загружает текстуру из вектора цветов
        /// @param png_code вектор
        /// @param width ширина
        /// @param height высота
        /// @param channels кол-во каналов
        /// @return возвращает дескриптор текстуры
        static unsigned int load(std::vector<unsigned char>& png_code, int width, int height, int channels);

        /// @brief загружает текстуру из png файла
        /// @param path путь к файлу
        /// @return возвращает дескриптор текстуры
        static unsigned int load(const char* path);

        /// @brief удаляет текстуру по её дескриптору
        /// @param id дескриптор
        static void Delete(unsigned int id);

        /// @brief удаляет все текстуры
        static void DeleteALL();
    };

    class Texture : private texture
    {
    private:
        unsigned int id;

    public:
        /// @brief конструктор, создаёт текстуру из массива цветов
        /// @param png_code массив
        /// @param width ширина
        /// @param height высота
        /// @param channels кол-во каналов
        Texture(unsigned char* png_code, int width, int height, int channels);

        /// @brief конструктор, создаёт текстуру из вектора цветов
        /// @param png_code вектор
        /// @param width ширина
        /// @param height высота
        /// @param channels кол-во каналов
        Texture(std::vector<unsigned char>& png_code, int width, int height, int channels);

        /// @brief конструктор, загружает текстуру из png файла
        /// @param path путь к файлу
        Texture(const char* path);
        ~Texture();

        /// @brief привязка текстуры
        /// @param Sample индекс привязки (этот индификатор нужен для шейдера(uniform Sample2D))
        void bind(unsigned int Sample = 0) const;
    };
}