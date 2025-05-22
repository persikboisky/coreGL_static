#ifndef SRC_CORE_WINDOW_EVENT_HPP_
#define SRC_CORE_WINDOW_EVENT_HPP_

#define MAX_KEY_CODE 360


enum KEY_CODE;
struct GLFWwindow;
typedef void (*GLFWkeyfun)(GLFWwindow* window, int key, int scancode, int action, int mods);

namespace core
{
	class Window;
	class Event
	{
	private:
		GLFWwindow* window;
		//void key_callbac(GLFWwindow* window, int key, int scancode, int action, int mods);
		void setCallbackKey(GLFWwindow* window, GLFWkeyfun callback);

	public:
		Event(GLFWwindow& addrWindow);
		Event(Window& window);

		/// @brief обновляет список событий
		void update();

		/// @brief проверяет событие закрытия окна
		/// @return true - если сработало событие на закрытие окна, иначе false
		bool close();

		/// @brief проверяет нажата ли ЛКМ
		/// @return true - нажата, false - отпущена
		bool GetMouseLeftButton();

		/// @brief проверяет нажата ли ПКМ
		/// @return true - нажата, false - отпущена
		bool GetMouseRightButton();

		/// @brief Проверяет состояние клавиши
		/// @param key название клавиши (Пример: K_ESCAPE, K_W, K_LEFT_SHIFT и т.д.)
		/// @return true - нажата, false - отпущена
		bool getKey(KEY_CODE key);

		/// @brief Проверяет состояние клавиши
		/// @param key номер клавиши соответсвует стандарту библиотеки GLFW
		/// @return true - нажата, false - отпущена
		bool getKey(int key);
	};
}

#endif // !SRC_CORE_WINDOW_EVENT_HPP_