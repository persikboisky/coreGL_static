//#include "../../config.hpp"
//
//#if MODULE_GUI

#include <string>

namespace core
{

	class Window;
	class Button;
	class Image;

	struct font;
	struct GuiElementStyle;

	class GUI
	{
	private:
		Window* addrWindow;
		font* objFont;

		static unsigned int ShaderID[2];

	public:
		GUI(Window& window, font& objFont);
		~GUI();

		Button* button = nullptr;
		Image* image = nullptr;
		//Text* text = nullptr;

		// void addFromXML(const char* path);

		void setStyle(std::string ID, GuiElementStyle style);
		void setStyle(const char* path);

		void render();
	};

}

//#endif // MODULE_GUI