#include "ebo.hpp"
#include "vao.hpp"
#include "../../util/vector.hpp"
#include "../../util/type.hpp"
#include <GL/glew.h>
#include <vector>
#include <iostream>

using namespace core;

#pragma region ebo

std::vector<unsigned int> ebo::id;
unsigned int ebo::SelectID = 0;
unsigned int ebo::SelectVAO = 0;

void ebo::bind(unsigned int id)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

unsigned int ebo::create(unsigned int* indexes, unsigned int sizeOfByte)
{
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	
	if (EBO <= 0)
	{
		std::cerr << "Failed create VAO" << "\n";
		throw "FAILED_CREATE_VAO";
	}

	ebo::bind(EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeOfByte, indexes, GL_STATIC_DRAW);
	ebo::bind(0);

	ebo::id.push_back(EBO);
	return EBO;
}

unsigned int ebo::create(std::vector<unsigned int> indexes)
{
	unsigned int EBO;
	glGenBuffers(1, &EBO);

	if (EBO <= 0)
	{
		std::cerr << "Failed create VAO" << "\n";
		throw "FAILED_CREATE_VAO";
	}

	ebo::bind(EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexes.size() * sizeof(indexes[0]), indexes.data(), GL_STATIC_DRAW);
	ebo::bind(0);

	ebo::id.push_back(EBO);
	return EBO;
}

void ebo::draw(PRIMITIVE Primitive, unsigned int nVert)
{
	glDrawElements(convertPrimitive(Primitive), nVert, GL_UNSIGNED_INT, (void*)0);
}

void ebo::draw(PRIMITIVE Primitive, unsigned int ebo, unsigned int nVert)
{
	if (ebo::SelectID != ebo)
	{
		ebo::bind(ebo);
		ebo::SelectID = ebo;
	}

	ebo::draw(Primitive, nVert);
}

void ebo::draw(PRIMITIVE Primitive, unsigned int ebo, unsigned int vao, unsigned int nVert)
{
	if (ebo::SelectID != ebo)
	{
		ebo::bind(ebo);
		ebo::SelectID = ebo;
	}

	if (ebo::SelectVAO != vao)
	{
		vao::bind(vao);
		ebo::SelectVAO = vao;
	}

	ebo::draw(Primitive, nVert);
}

void ebo::draw(PRIMITIVE Primitive, unsigned int ebo, VAO& vao, unsigned int nVert)
{
	if (ebo::SelectID != ebo)
	{
		ebo::bind(ebo);
		ebo::SelectID = ebo;
	}

	vao.bind();
	ebo::draw(Primitive, nVert);
}

void ebo::Delete(unsigned int id)
{
	int index = vector::searchElementForValue(ebo::id, id);

	if (index != -1)
	{
		glDeleteBuffers(1, &ebo::id[index]);
		std::vector<unsigned int>::const_iterator Iter = ebo::id.cbegin();
		ebo::id.erase(Iter + index);
	}
}

void ebo::DeleteALL()
{
	for (unsigned int index = 0; index < ebo::id.size(); index++)
	{
		glDeleteBuffers(1, &ebo::id[index]);
	}
}

void ebo::setSizePoints(float sizePixel)
{
	vao::setSizePoints(sizePixel);
}

void ebo::setWidthLine(float width)
{
	vao::setWidthLine(width);
}

#pragma endregion ebo

#pragma region EBO

EBO::EBO(unsigned int* indexes, unsigned int sizeOfByte) : 
	vao(0), Vao(nullptr), id(0), nVert(sizeOfByte / sizeof(unsigned int))
{
	this->id = ebo::create(indexes, sizeOfByte);
}

EBO::EBO(std::vector<unsigned int> indexes) : 
	vao(0), Vao(nullptr), id(0), nVert(indexes.size())
{
	this->id = ebo::create(indexes);
}

EBO::~EBO()
{
	ebo::Delete(this->id);
}

void EBO::linkVAO(unsigned int vao)
{
	this->vao = vao;
	this->typeVao = 'v';
}

void EBO::linkVAO(VAO& vao)
{
	this->Vao = &vao;
	this->typeVao = 'V';
}

void EBO::draw(PRIMITIVE Primitive, unsigned int nVert)
{
	switch (this->typeVao)
	{
	case 'V':
		this->Vao->bind();
		break;

	case 'v':
		vao::bind(this->vao);
		break;

	default:
		break;
	}

	if (nVert == 0)
	{
		nVert = this->nVert;
	}

	ebo::bind(this->id);
	vao::setSizePoints(this->sizePoint);
	vao::setWidthLine(this->widthLine);
	ebo::draw(Primitive, nVert);
}

void EBO::setSizePoints(float sizePixel)
{
	this->sizePoint = sizePoint;
}

void EBO::setWidthLine(float width)
{
	this->widthLine = width;
}

#pragma endregion EBO