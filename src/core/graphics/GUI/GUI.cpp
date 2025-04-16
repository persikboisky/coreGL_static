#include "GUI.hpp"
#include "Elements/Button.hpp"
#include "Elements/Image.hpp"
//#include "Elements/Text.hpp"
#include "GUI_Style.hpp"
#include "../../window/Window.hpp"
#include "../commons/shader.hpp"
#include "../commons/font.hpp"

// путь к шейдерам для интерфейса
constexpr const char* PATH_TO_VERTEX_SHADER[2] = {
	"./res/gui/main_gui_v.glsl",
	"./res/gui/main_gui_texture_v.glsl"
};
constexpr const char* PATH_TO_FRAGMENT_SHADER[2] = {
	"./res/gui/main_gui_f.glsl",
	"./res/gui/main_gui_texture_f.glsl"
};

unsigned int GUI::ShaderID[2] = { 0, 0 };

GUI::GUI(Window& window, font& objFont) : 
	addrWindow(&window), objFont(&objFont), button(new Button(window, *this->objFont)), 
	image(new Image())//, text(new Text())
{
	if (GUI::ShaderID[0] == 0)
	{
		GUI::ShaderID[0] = shader::createFromFile(
			PATH_TO_VERTEX_SHADER[0],
			PATH_TO_FRAGMENT_SHADER[0]
		);
	}

	if (GUI::ShaderID[1] == 0)
	{
		GUI::ShaderID[1] = shader::createFromFile(
			PATH_TO_VERTEX_SHADER[1],
			PATH_TO_FRAGMENT_SHADER[1]
		);
	}
}

GUI::~GUI()
{
	delete this->button;
	delete this->image;
}

void GUI::setStyle(std::string ID, GuiElementStyle style)
{
	this->button->setStyle(ID, style);
}

void GUI::setStyle(const char* path)
{

}

void GUI::render()
{
	bool leftButtonMouse = this->addrWindow->event->GetMouseLeftButton();

	double MouseX, MouseY;
	this->addrWindow->cursor->getCordCursor(MouseX, MouseY);
	MouseX = MouseX / double(addrWindow->width / 2.0) - 1.0;
	MouseY = -(MouseY / double(addrWindow->height / 2.0) - 1.0);

	shader::use(GUI::ShaderID[0]);
	this->button->update(MouseX, MouseY, leftButtonMouse);
	this->button->render(/*fonts*/);
}