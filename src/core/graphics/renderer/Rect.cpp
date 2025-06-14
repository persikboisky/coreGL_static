#include "Rect.hpp"
#include "../../window/Window.hpp"
#include "../commons/vao.hpp"
#include "../commons/texture.hpp"
#include "../commons/shader.hpp"
#include "../../util/type.hpp"
#include "../../math/Vectors.hpp"
#include <iostream>

using namespace core;

unsigned int Rect::shaderID = 0;
unsigned int Rect::textureID = 0;

Rect::Rect() : color(color::RGBA(255.f, 255.f, 255.f, 255.f))
{
	if (Rect::shaderID == 0)
	{
		shader::compileFromFile(VERTEX, "./res/rect/main.vert");
		shader::compileFromFile(FRAGMENT, "./res/rect/main.frag");
		Rect::shaderID = shader::createProgram();

		Rect::textureID = texture::load("./res/white.png");
	}
}

void Rect::setTexture(unsigned int id)
{
	this->userTID = id;
}

void Rect::setTexture(const Texture& texture)
{
	this->userTID = texture.getID();
}

void Rect::setTextureCoord(float u1, float v1, float u2, float v2)
{
	this->u1 = u1;
	this->u2 = u2;
	this->v1 = v1;
	this->v2 = v2;
}

void Rect::setTextureCoord(math::Vector2 vec2_1, math::Vector2 vec2_2)
{
	this->setTextureCoord(vec2_1.x, vec2_1.y, vec2_2.x, vec2_2.y);
}

void Rect::setColor(float red, float green, float blue, float alpha)
{
	this->color.red = red;
	this->color.green = green;
	this->color.blue = blue;
	this->color.alpha = alpha;
}

void Rect::setColor(const color::RGB& color)
{
	this->color.red = color.red;
	this->color.green = color.green;
	this->color.blue = color.blue;
	this->color.alpha = 255.0f;
}

void Rect::setColor(const color::RGBA& color)
{
	this->color = color;
}

void core::Rect::setColor(const color::COLOR& color)
{
	this->color = color::RGBA(color);
}

void core::Rect::setCoordType(TYPE_COORD typeCoord)
{
	this->typeCoord = typeCoord;
}

void Rect::draw(float x, float y, float width, float height, Window& window) const
{
	if (!window.isContext())
	{
		window.setContext();
	}

	float x2 = x + width;
	float y2 = y - height;

	if (this->typeCoord == WINDOW_COORD)
	{
		y2 = y + height;
		x = x / ((float)window.width / 2.0);
		y = y / ((float)window.height / 2.0);
		x2 = x2 / ((float)window.width / 2.0);
		y2 = y2 / ((float)window.height / 2.0);
	}
	else if (this->typeCoord == POSITIVE_WINDOW_COORD)
	{
		y2 = y + height;
		x = x / ((float)window.width / 2.0) - 1.0;
		y = -(y / ((float)window.height / 2.0) - 1.0);
		x2 = x2 / ((float)window.width / 2.0) - 1.0;
		y2 = -(y2 / ((float)window.height / 2.0) - 1.0);
	}
	else if (this->typeCoord == POSITIVE_RELATIVE_COORD)
	{
		x = (x - 0.5) * 2.0;
		y = (y - 0.5) * 2.0;
		x2 = (x2 - 0.5) * 2.0;
		y2 = (y2 - 0.5) * 2.0;

		std::cout << x2 << ":" << y2 << std::endl;
	}
	
	VAO vao = VAO({
		x, y, this->u1, this->v2,
		x, y2, this->u1, this->v1,
		x2, y2, this->u2, this->v1,
		x, y, this->u1, this->v2,
		x2, y2, this->u2, this->v1,
		x2, y, this->u2, this->v2,
	}, 4);
	vao.addAttribute(0, 2, 0);
	vao.addAttribute(1, 2, 2);

	shader::use(Rect::shaderID);
	shader::UniformRGBA(this->color, "uColor");

	if (this->userTID > 0)
	{
		shader::UniformSample2D(1, "uTexture");
		texture::bind(this->userTID, 1);
	}
	else
	{
		shader::UniformSample2D(0, "uTexture");
		texture::bind(textureID, 0);
	}

	vao.draw(TRIANGLES);
}


