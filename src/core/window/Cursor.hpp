#ifndef SRC_CORE_WINDOW_CURSOR_HPP_
#define SRC_CORE_WINDOW_CURSOR_HPP_

#include <vector>

enum Cursor_mode;
struct GLFWwindow;
struct GLFWcursor;

namespace core
{
	class Window;

	struct cursor
	{
		static double getCordCursorX(GLFWwindow* window);
		static double getCordCursorY(GLFWwindow* window);
		static void getCordCursor(GLFWwindow* window, double& x, double& y);
	};

	class Cursor
	{
	private:
		GLFWwindow* window;

	public:
		static class custom_cursor
		{
		private:
			GLFWcursor* cursor_objs = nullptr;
			GLFWwindow& addrWindow;

		public:
			custom_cursor(const char* pathToPng, int x, int y, GLFWwindow* window);
			~custom_cursor();

			/// @brief включает кастомный курсор
			void use();

			/// @brief сбрасывает курсор
			void unUse();
		};

		Cursor(GLFWwindow& addrWindow);
		Cursor(Window& window);
		~Cursor();

		/// @brief устанавливает режим курсора
		/// @param mode режим курсора соответсвует стандарту библиотеки GLFW 
		void setCursorMode(int mode);

		/// @brief разрешает рисовать курсор
		/// @param flag true - разрешает рисовать false - запрещает рисовать
		void showCursor(bool flag);

		/// @brief выключает курсор
		/// @param flag true - выключен, false - включён
		void disableCursor(bool flag);

		/// @brief устанавливает курсор на указанные координаты
		/// @param x ось x (от 0 до ширины окна)
		/// @param y ось y (от 0 до высоты окна)
		void setPosition(double x, double y);

		/// @brief возвращает координату курсора по оси x
		double getCordCursorX();

		/// @brief возвращает координату курсора по оси y
		double getCordCursorY();

		/// @brief передаёт координату курсора в указанные переменные
		/// @param x адрес на переменную для x
		/// @param y адрес на переменную для y
		void getCordCursor(double& x, double& y);

		/// @brief Создаёт кастомный курсор
		/// @brief Пример: 
		/// @brief Cursor::custom_cursor cursor = объект_окна.cursor->create("./res/aim.png", 0, 0);
		///	@brief cursor.use();
		/// @param path путь к png картинке
		/// @param x координата по x
		/// @param y координата по y
		/// @return возвращает объект курсора
		custom_cursor create(const char* path, int x = 0, int y = 0);

		/*void setCursor(custom_cursor cursor);*/
	};
}

#endif // !SRC_CORE_WINDOW_CURSOR_HPP_
