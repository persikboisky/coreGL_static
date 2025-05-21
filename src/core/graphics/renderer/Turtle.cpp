#include "Turtle.hpp"
#include "../../math/Vectors.hpp"
#include "../../math/math.hpp"
#include "../commons/shader.hpp"
#include "../commons/vao.hpp"
#include "../commons/texture.hpp"
#include "../../util/type.hpp"
#include "../../window/Window.hpp"
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

using namespace core;

unsigned int Turtle::shaderTurtle = 0;
unsigned int Turtle::shaderLine = 0;
unsigned int Turtle::idText = 0;

Turtle::Turtle(Window& window) : window(&window)
{
	if (Turtle::shaderTurtle == 0)
	{
		Turtle::shaderTurtle = shader::createProgramFromFile("./res/turtle/main.vert", "./res/turtle/main.frag");
		Turtle::shaderLine = shader::createProgramFromFile("./res/turtle/line.vert", "./res/turtle/line.frag");
		Turtle::idText = texture::load("./res/turtle/turtle.png");
	}

	this->vaoTurtle = vao::create({
	   -0.05, 0.05, 1, 0,
	   -0.05,-0.05, 1, 1,
		0.05,-0.05, 0, 1,
		0.05, 0.05, 0, 0
	});
	vao::addAttribute(this->vaoTurtle, 0, 2, 4, 0);
	vao::addAttribute(this->vaoTurtle, 1, 2, 4, 2);

	std::vector<float> coordP;
	this->coordPoint.push_back(coordP);
}

Turtle::~Turtle()
{
	shader::Delete(Turtle::shaderTurtle);
	vao::Delete(this->vaoTurtle);

	for (unsigned int index = 0; index < this->vaoPoints.size(); index++)
	{
		vao::Delete(this->vaoPoints[index]);
	}

	this->coordPoint.clear();
}

void Turtle::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Turtle::setPos(const math::Vector2& vec2)
{
	this->x = vec2.x;
	this->y = vec2.y;
}

void Turtle::clear()
{
	this->updateVao = true;
	this->coordPoint.clear();
	this->width.clear();	
	this->vaoPoints.clear();

	std::vector<float> v;
	this->coordPoint.push_back(v);
	this->width.push_back(1);
	this->vaoPoints.push_back(0);
}

void Turtle::setSpeed(float speed)
{
	this->speed = speed;
}

void Turtle::move()
{
	constexpr float A = 0.001f;

	if (this->Time + 1.0 / this->speed <= glfwGetTime())
	{
		this->updateVao = true;

		float velX = A * sin(math::radians(this->angle - 90.0f));
		float velY = A * cos(math::radians(this->angle - 90.0f)) * ((float)this->window->width / (float)this->window->height);

		this->x += velX;
		this->y += velY;//(1.0f / (float)this->window->height) 
		// * ((float)thi->window->width / (float)this->window->height);

		this->coordPoint[this->width.size() - 1].push_back(this->x);
		this->coordPoint[this->width.size() - 1].push_back(this->y);
		this->coordPoint[this->width.size() - 1].push_back(color.red / 255.0f);
		this->coordPoint[this->width.size() - 1].push_back(color.green / 255.0f);
		this->coordPoint[this->width.size() - 1].push_back(color.blue / 255.0f);
	
		this->Time = glfwGetTime();
	}
}

void Turtle::draw()
{
	if (this->updateVao)
	{
		for (unsigned int index = 0; index < this->vaoPoints.size(); index++)
		{
			vao::Delete(this->vaoPoints[index]);

			this->vaoPoints[index] = vao::create(this->coordPoint[index]);
			vao::addAttribute(this->vaoPoints[index], 0, 2, 5, 0);
			vao::addAttribute(this->vaoPoints[index], 1, 3, 5, 2);
		}
	}

	float x = this->x;
	float y = this->y;

	shader::use(Turtle::shaderLine);

	for (unsigned int index = 0; index < this->vaoPoints.size(); index++)
	{
		vao::bind(this->vaoPoints[index]);
		vao::setSizePoints(this->width[index]);
		vao::draw(POINTS, 0, this->coordPoint[index].size());
	}

	if (this->bodyTurtleDraw)
	{
		math::Matrix4 model = math::Matrix4(1.0f);
		model = math::Matrix4::getTranslate(math::Vector3(x, y, 0), model);
		model = math::Matrix4::getRotate(math::radians(this->angle), math::Vector3(0, 0, 1), model);

		texture::bind(Turtle::idText, 0);
		shader::use(Turtle::shaderTurtle);
		shader::UniformMat4(model, "model");
		vao::bind(this->vaoTurtle);
		vao::draw(TRIANGLES_FAN, 0, 4);
	}
}

void Turtle::setAngle(float degree)
{
	this->angle = degree;
}

void Turtle::setColor(RGB color)
{
	this->color = color;
}

void Turtle::setWidth(float width)
{
	if (this->width[this->width.size() - 1] != width)
	{
		this->width.push_back(width);
		this->vaoPoints.push_back(0);

		std::vector<float> v;
		this->coordPoint.push_back(v);
	}
}

void Turtle::enableDrawBody(bool flag)
{
	this->bodyTurtleDraw = flag;
}
