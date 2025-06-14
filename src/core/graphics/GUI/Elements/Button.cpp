#include "Button.hpp"
#include "../GUI_Style.hpp"
#include "../../../window/Window.hpp"
#include "../../../util/type.hpp"
#include "../../commons/vao.hpp"
#include "../../commons/BufferText2D.hpp"
#include "../../commons/font.hpp"
#include "../../commons/shader.hpp"
#include <GL/glew.h>
#include <string>
#include <vector>
#include <iostream>

using namespace core;

static void addVertexesButton(
	std::vector<float> &vec,
	pos4f data,
	color::RGBA color
)
{
	vec.push_back(data.x);
	vec.push_back(data.y);
	vec.push_back(color.red / 255.0f);
	vec.push_back(color.green / 255.0f);
	vec.push_back(color.blue / 255.0f);
	vec.push_back(color.alpha / 255.0f);

	vec.push_back(data.x);
	vec.push_back(data.y - data.w);
	vec.push_back(color.red / 255.0f);
	vec.push_back(color.green / 255.0f);
	vec.push_back(color.blue / 255.0f);
	vec.push_back(color.alpha / 255.0f);

	vec.push_back(data.x + data.z);
	vec.push_back(data.y - data.w);
	vec.push_back(color.red / 255.0f);
	vec.push_back(color.green / 255.0f);
	vec.push_back(color.blue / 255.0f);
	vec.push_back(color.alpha / 255.0f);

	vec.push_back(data.x);
	vec.push_back(data.y);
	vec.push_back(color.red / 255.0f);
	vec.push_back(color.green / 255.0f);
	vec.push_back(color.blue / 255.0f);
	vec.push_back(color.alpha / 255.0f);

	vec.push_back(data.x + data.z);
	vec.push_back(data.y - data.w);
	vec.push_back(color.red / 255.0f);
	vec.push_back(color.green / 255.0f);
	vec.push_back(color.blue / 255.0f);
	vec.push_back(color.alpha / 255.0f);

	vec.push_back(data.x + data.z);
	vec.push_back(data.y);
	vec.push_back(color.red / 255.0f),
	vec.push_back(color.green / 255.0f);
	vec.push_back(color.blue / 255.0f);
	vec.push_back(color.alpha / 255.0f);
}

Button::Button(Window& window, font& addrFont) : addrWindow(&window), BT2D(new BufferText2D()), Font(&addrFont)
{
	this->BT2D->linkFont(this->Font);
	this->BT2D->linkWindow(window);
}

Button::~Button()
{
	this->vFunction.clear();
	this->vStyle.clear();
	this->vID.clear();
	this->vHover.clear();
	this->vActive.clear();

	if (this->vaoID != 0)
	{
		vao::Delete(this->vaoID);
	}

	delete this->BT2D;
}

void Button::add(
	GuiElementStyle style,
	void(*function)(),
	std::string ID
)
{
	bool flag = true;

	this->vID.push_back(ID);
	this->vStyle.push_back(style);
	this->vHover.push_back(false);
	this->vActive.push_back(false);
	this->vFunction.push_back(function);

	this->flagCompileVAO = true;
	this->nButton++;
}

void Button::setStyle(std::string ID, GuiElementStyle style)
{
	for (unsigned int index = 0; index < this->nButton; index++)
	{
		if (this->vID[index] == ID)
		{
			this->vStyle[index] = style;
		}
	}

	this->flagCompileVAO = true;
}

void Button::Delete(std::string ID)
{
	for (unsigned int index = 0; index < this->nButton; index++)
	{
		if (this->vID[index] == ID)
		{
			std::vector<std::string>::const_iterator iterStr = this->vID.cbegin();
			this->vID.erase(index + iterStr);

			std::vector<GuiElementStyle>::const_iterator iterStyle = this->vStyle.cbegin();
			this->vStyle.erase(index + iterStyle);

			std::vector<void(*)()>::const_iterator iterVoid = this->vFunction.cbegin();
			this->vFunction.erase(index + iterVoid);

			std::vector<bool>::const_iterator iterBool_1 = this->vHover.cbegin();
			this->vHover.erase(index + iterBool_1);

			std::vector<bool>::const_iterator iterBool_2 = this->vActive.cbegin();
			this->vActive.erase(index + iterBool_2);

			index--;
			this->nButton--;
		}
	}

	this->flagCompileVAO = true;
}

void Button::DeleteALL()
{
	this->flagCompileVAO = true;
	this->nButton = 0;
	this->vFunction.clear();
	this->vStyle.clear();
	this->vID.clear();
	this->vHover.clear();
	this->vActive.clear();
}

void Button::compileVAO()
{
	if (this->vaoID != 0)
	{
		vao::Delete(this->vaoID);
	}

	std::vector<float> vertexes;

	for (unsigned int index = 0; index < this->nButton; index++)
	{
		pos4f pos = pos4f(
			this->vStyle[index].pos.x,
			this->vStyle[index].pos.y,
			this->vStyle[index].size.width,
			this->vStyle[index].size.height
		);

		color::RGBA background;
		if (this->vActive[index])
		{
			background = this->vStyle[index].activeBackground;
		}
		else if (this->vStyle[index].hover && vHover[index])
		{
			background = this->vStyle[index].hoverBackground;
		}
		else
		{
			background = this->vStyle[index].background;
		}

		addVertexesButton(vertexes, pos, background);

		this->BT2D->addText(
			this->vStyle[index].text, 
			0,
			0,
			0.2
		);
	}

	this->vaoID = vao::create(vertexes);
	vao::addAttribute(this->vaoID, 0, 2, 6, 0);
	vao::addAttribute(this->vaoID, 1, 4, 6, 2);

	vertexes.clear();
}

void Button::update(double mouseX, double mouseY, bool LBM)
{
	for (unsigned int index = 0; index < this->nButton; index++)
	{
		bool saveActive = this->vActive[index];
		bool saveHover = this->vHover[index];

		if (
			mouseX >= double(this->vStyle[index].pos.x) &&
			mouseX <= double(this->vStyle[index].pos.x + this->vStyle[index].size.width) &&
			mouseY <= this->vStyle[index].pos.y &&
			mouseY >= this->vStyle[index].pos.y - this->vStyle[index].size.height
		)
		{
			this->vActive[index] = LBM;
			this->vHover[index] = true;
			if (LBM)
			{
				if (this->vFunction[index] != nullptr)
				{
					this->vFunction[index]();
				}
			}
		}
		else
		{
			this->vHover[index] = false;
			this->vActive[index] = false;
		}

		if (this->vHover[index] != saveHover || this->vActive[index] != saveActive)
		{
			this->flagCompileVAO = true;
		}
	}

	if (this->flagCompileVAO)
	{
		this->flagCompileVAO = false;
		this->compileVAO();
	}
}

void Button::render()
{
	if (this->flagCompileVAO)
	{
		this->flagCompileVAO = false;
		this->compileVAO();
	}

	vao::bind(this->vaoID);
	vao::draw(TRIANGLES, 0, this->nButton * 6);
	this->BT2D->render();
}