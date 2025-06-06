#ifndef SRC_CORE_WINDOW_EVENT_HPP_
#define SRC_CORE_WINDOW_EVENT_HPP_

#define MAX_KEY_CODE 360

struct GLFWwindow;
typedef void (*GLFWkeyfun)(GLFWwindow* window, int key, int scancode, int action, int mods);

namespace core
{
	enum KEY_CODE;
	class Window;
	class Event
	{
	private:
		GLFWwindow* window;
		//void key_callbac(GLFWwindow* window, int key, int scancode, int action, int mods);
		void setCallbackKey(GLFWkeyfun callback);
		bool* key = new bool[MAX_KEY_CODE];
		char* saveKey = new char[MAX_KEY_CODE];

	public:
		Event(GLFWwindow& addrWindow);
		Event(Window& window);

		~Event();

		/// @brief обновляет список событий
		void update();

		/// @brief проверяет событие закрытия окна
		/// @return true - если сработало событие на закрытие окна, иначе false
		[[nodiscard]] bool close();

		/// @brief проверяет нажата ли ЛКМ
		/// @return true - нажата, false - отпущена
		[[nodiscard]] bool GetMouseLeftButton();

		/// @brief проверяет нажата ли ПКМ
		/// @return true - нажата, false - отпущена
		[[nodiscard]] bool GetMouseRightButton();

		/// @brief Проверяет состояние клавиши
		/// @param key номер клавиши соответсвует стандарту библиотеки GLFW
		/// @return true - нажата, false - отпущена
		[[nodiscard]] bool stateKey(int key);

		/// @brief Проверяет состояние клавиши
		/// @param key название клавиши (Пример: K_ESCAPE, K_W, K_LEFT_SHIFT и т.д.)
		/// @return true - нажата, false - отпущена
		[[nodiscard]] bool stateKey(KEY_CODE key);

		[[nodiscard]] bool downKey(int key);
		[[nodiscard]] bool downKey(KEY_CODE key);

		[[nodiscard]] bool upKey(int key);
		[[nodiscard]] bool upKey(KEY_CODE key);
	};
}

#endif // !SRC_CORE_WINDOW_EVENT_HPP_