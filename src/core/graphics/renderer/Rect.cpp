#include "Rect.hpp"
#include "../commons/texture.hpp"
#include "../../util/type.hpp"

using namespace core;

unsigned int Rect::vaoID = 0;
unsigned int Rect::shaderID = 0;

Rect::Rect() : color(RGBA(255.f, 255.f, 255.f, 255.f))
{

}

void Rect::setTexture(unsigned int id)
{
	this->tID = id;
}

void Rect::setTexture(const Texture& texture)
{
	this->tID = texture.getID();
}

void Rect::setColor(float red, float green, float blue, float alpha)
{
	this->color.red = red;
	this->color.green = green;
	this->color.blue = blue;
	this->color.alpha = alpha;
}

void Rect::setColor(const RGB& color)
{
	this->color.red = color.red;
	this->color.green = color.green;
	this->color.blue = color.blue;
	this->color.alpha = 255.0f;
}

void Rect::setColor(const RGBA& color)
{
	this->color = color;
}

void Rect::draw(float x, float y, float width, float height)
{
}


