#include <vector>
#include <string>

struct GuiElementStyle;
class Window;
class VAO;
class BufferText2D;
class font;

class Button
{
private:
	std::vector<std::string> vID;
	std::vector<GuiElementStyle> vStyle;
	std::vector<void(*)()> vFunction;
	std::vector<bool> vActive;
	std::vector<bool> vHover;

	unsigned int nButton = 0;

	Window* addrWindow = nullptr;
	BufferText2D* BT2D = nullptr;
	font* Font = nullptr;

	void compileVAO();
	bool flagCompileVAO = false;

	unsigned int vaoID = 0;

public:
	Button(Window& window, font& addrFont);
	~Button();

	void add(
		GuiElementStyle style,
		void(*function)() = nullptr,
		std::string ID = "button"
	);

	void setStyle(std::string ID, GuiElementStyle style);
	//void setPos(std::string ID, float x, float y);

	void Delete(std::string ID);
	void DeleteALL();

	void update(double mouseX, double mouseY, bool LBM);
	void render();
};