#ifndef SRC_CORE_WINDOW_WINDOW_HPP_
#define SRC_CORE_WINDOW_WINDOW_HPP_

struct GLFWwindow;

namespace core
{
	class Event;
	class Cursor;

	/// @brief класс для работы с окном
	class Window
	{
	private:
		GLFWwindow* window = nullptr;

		static bool flagGLewInit;

		void Init();
		void getSizeWindow();

	public:

		/// @brief возвращает объект окна, тип GLFWwindow
		GLFWwindow* getGlfwWindowObject();

		Event* event = nullptr;
		Cursor* cursor = nullptr;

		/// @brief текущая ширина окна (обновляется при вызове swapBuffers)
		int width;

		/// @brief текущая высота окна (обновляется при вызове swapBuffers)
		int height;

		/// @brief конструктор окна (создаёт окно и его объект)
		/// @param width     ширина 
		/// @param height    высота 
		/// @param title     заголовок
		/// @param resizable разрешение на изменение размера окна
		Window(int width, int height, const char* title = "", bool resizable = true);

		~Window();

		/// @brief сменяет буферы кадра.
		/// В openGL два буфера на одном мы рисуем, другой отображается на экране.
		/// swapBuffers() - меняяет буферы местами.
		/// Теперь отображается тот, на котором мы рисовали,
		/// а рисуем мы на том, который отображался.
		/// Расписал как мог : )
		void swapBuffers();

		/// @brief устанавливает иконку для окна
		/// @param path путь к png картинке
		void setIcon(const char* path);

		/// @brief вызывает событие закрытия окна
		void close();

		/// @brief делает окна контекстом (То где мы рисуем)
		void setContext();

		/// @brief устанавливает размер буфера кадра
		/// @param width  ширина
		/// @param height высота
		void setSizeBuffer(int width, int height);

		/// @brief проверяет является ли окно контекстом
		/// @return true - если является, false - если не является
		bool isContext();
	};
}

#endif // !SRC_CORE_WINDOW_WINDOW_HPP_