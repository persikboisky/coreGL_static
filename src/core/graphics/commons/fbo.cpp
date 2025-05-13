#include "fbo.hpp"
#include "../../util/vector.hpp"
#include "../../util/type.hpp"
#include "../../math/Vectors.hpp"
#include <GL/glew.h>
#include <vector>
#include <iostream>

using namespace core;

std::vector<unsigned int> fbo::id;
unsigned int fbo::selectID = 0;

//RGBA fbo::color = RGBA();

void fbo::bind(unsigned int id)
{
	glBindFramebuffer(GL_FRAMEBUFFER, id);
	fbo::selectID = id;
}

void fbo::bindDefault()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	fbo::selectID = 0;
}

void fbo::DepthTest(bool flag)
{
	if (flag)
	{
		glEnable(GL_DEPTH_TEST);
	}
	else
	{
		glDisable(GL_DEPTH_TEST);
	}
}

void fbo::setSize(int width, int height)
{
	glViewport(0, 0, width, height);
}

void core::fbo::setSize(math::Vector2 size)
{
	fbo::setSize(size.x, size.y);
}

void fbo::setColor(RGB color)
{
	glClearColor(
		color.red / 255.0f,
		color.green / 255.0f,
		color.blue / 255.0f,
		1.0f
	);
}

void fbo::setColor(RGBA color)
{
	glClearColor(
		color.red / 255.0f, 
		color.green / 255.0f, 
		color.blue / 255.0f, 
		color.alpha / 255.0f
	);
}

void fbo::setColor(float red, float green, float blue, float alpha)
{
	glClearColor(
		red / 255.0f,
		green / 255.0f,
		blue / 255.0f,
		alpha / 255.0f
	);
}

void fbo::clearBuffers(Buffer buffer1, Buffer buffer2, Buffer buffer3)
{
	Buffer array[3] = { buffer1, buffer2, buffer3 };
	for (unsigned int index = 0; index < 3; index++)
	{
		switch (array[index])
		{
		case COLOR_BUFFER:
			glClear(GL_COLOR_BUFFER_BIT);
			break;

		case DEPTH_BUFFER:
			glClear(GL_DEPTH_BUFFER_BIT);
			break;

		default:
			break;
		}
	}
}

unsigned int fbo::create()
{
	unsigned int FBO;
	glGenFramebuffers(1, &FBO);

	if (FBO <= 0)
	{
		std::cerr << "Failed: create FBO" << std::endl;
		throw "FAILED_CREATE_FBO";
	}

	fbo::id.push_back(FBO);
	return FBO;
}

void fbo::linkTexture(unsigned int t_id)
{
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, t_id, 0);
}

void fbo::Delete(unsigned int id)
{
	unsigned int index = vector::searchElementForValue(fbo::id, id);

	if (index != -1)
	{
		glDeleteFramebuffers(1, &fbo::id[index]);
		std::vector<unsigned int>::const_iterator iterID = fbo::id.cbegin();
		fbo::id.erase(iterID + index);
	}
}

void fbo::DeleteALL()
{
	for (unsigned int index = 0; index < fbo::id.size(); index++)
	{
		glDeleteFramebuffers(1, &fbo::id[index]);
	}

	fbo::id.clear();
}