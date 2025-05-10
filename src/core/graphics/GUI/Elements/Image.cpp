#include "Image.hpp"
#include "../GUI_Style.hpp"
#include "../../../graphics/commons/texture.hpp"
#include "../../../util/type.hpp"
#include "../../commons/vao.hpp"
#include <GL/glew.h>
#include <string>
#include <vector>
#include <iostream>

using namespace core;

static void addElementToVAO(
	std::vector<float>& vao,
	position_4f data,
	position_2f cooredTexture
)
{

}

void Image::compileVAO()
{
	if (this->vaoID > 0)
	{
		vao::Delete(this->vaoID);
	}

	std::vector<float> vao;
}

void Image::add(GUIstyle style, std::string ID)
{
	this->flagCompileVAO = true;
}

void Image::render()
{
	if (this->flagCompileVAO == true)
	{
		this->compileVAO();
	}
}