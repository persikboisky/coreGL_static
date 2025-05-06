#include "../../math/Vectors.hpp"
#include "../../math/Matrixes.hpp"

namespace core
{
    enum CAM_MODE
    {
        /// @brief Камера смотрит в одну точку
        DYNAMIC,

        /// @brief Камера смотрит в одно направление
        STATIC
    };

    /// @brief класс для работы с камерой
    class Camera
    {
    private:

        math::Vector3 startUP;
        math::Vector3 startTARGET;

        math::Vector3 up;
        math::Vector3 target;
        math::Vector3 pos;

        math::Matrix4 rot = math::Matrix4(1.0f);

        float fov;
        float distance;

        CAM_MODE mode;

        void update();

    public:
        /// @brief конструктор камеры
        /// @param posX позиция камеры по x
        /// @param posY позиция камеры по y
        /// @param posZ позиция камеры по z
        /// @param fov поле зрения в градусах
        /// @param distance дальность зрения
        Camera(float posX, float posY, float posZ, float fov, float distance);

        /// @brief конструктор камеры
        /// @param pos позиция камеры
        /// @param fov поле зрения в градусах
        /// @param distance дальность зрения
        Camera(math::Vector3 pos, float fov, float distance);

        /// @brief устанавливает режим камеры
        /// @param mode режим (Пример: STATIC, DYNAMIC)
        void setMode(CAM_MODE mode);

        /// @brief устанавливает поле зрения
        /// @param fov поле зрения в градусах
        void setFov(float fov);

        /// @brief устанавливает дальность зрения
        /// @param distance дальность зрения
        void setDistance(float distance);

        /// @brief поворачивает камеру по заданным осям
        /// @param x угол поворота по оси x в градусах
        /// @param y угол поворота по оси y в градусах
        /// @param z угол поворота по оси z в градусах
        void rotate(float x, float y, float z);

        /// @brief обнуляет поворот камеры(возвращает в исходное положение)
        void resetRotate();

        /// @brief перемещает камеру по заданным осям
        /// @param x сдвиг камеры по x
        /// @param y сдвиг камеры по y
        /// @param z сдвиг камеры по z
        void move(float x, float y, float z);

        /// @brief устанавливает камеру на заданные координаты
        /// @param x координата x
        /// @param y координата y
        /// @param z координата z
        void setPos(float x, float y, float z);

        /// @brief устанавливает камеру на заданные координаты
        /// @param pos вектор с координатами
        void setPos(const math::Vector3& pos);

        /// @brief устанавливает точку в которую смотрит камера
        /// @param x координата x
        /// @param y координата y
        /// @param z координата z
        void setTarget(float x, float y, float z);

        /// @brief устанавливает точку в которую смотрит камера
        /// @param target вектор с координатами
        void setTarget(const math::Vector3& target);

        /// @brief получает позицию камеры
        /// @param x переменная для хранения координаты x
        /// @param y переменная для хранения координаты y
        /// @param z переменная для хранения координаты z
        void getPos(float& x, float& y, float& z) const;

        /// @brief получает позицию камеры
        /// @param pos вектор для хранения координат
        void getPos(math::Vector3& pos) const;

        /// @brief получает координату куда смотрит камера
        /// @param x переменная для хранения координаты x
        /// @param y переменная для хранения координаты y
        /// @param z переменная для хранения координаты z
        void getTarget(float& x, float& y, float& z) const;

        /// @brief получает координату куда смотрит камера
        /// @param target вектор для хранения координат
        void getTarget(math::Vector3& target) const;

        /// @brief создаёт матрицу проекции камеры
        /// @param width ширина окна
        /// @param height высота окна
        /// @return возвращает матрицу проекции
        math::Matrix4 getProj(int width, int height) const;

        /// @brief создаёт видовую матрицу камеры
        /// @return возвращает видовую матрицу
        math::Matrix4 getView();
    };
}