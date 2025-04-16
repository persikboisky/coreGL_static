#include <string>

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

	void setStyle(std::string ID, GuiElementStyle style);
	void setStyle(const char* path);

	void render();
};