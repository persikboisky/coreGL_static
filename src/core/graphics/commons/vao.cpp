#include "vao.hpp"
#include "../../util/vector.hpp"
#include "../../util/array.hpp"
#include "../../file/obj_loaders.hpp"
#include "../../util/type.hpp"
#include <GL/glew.h>
#include <iostream>
#include <vector>

using namespace core;

// настройка obj компилятора (не изменять параметры)
#define N_ELEMENT_TO_FACE 3
#define N_ELEMENT_TO_VERT 3
#define N_ELEMENT_TO_NORMAL_VERT 3
#define N_ELEMENT_TO_TEXTURE_VERT 2

unsigned int saveID;

#pragma region vao

std::vector<unsigned int> vao::idVAO;
std::vector<unsigned int> vao::idVBO;
unsigned int vao::selectID;

unsigned int vao::getSelectId()
{
    return vao::selectID;
}

void vao::bind(unsigned int id)
{
    //if (id != saveID)
    //{
    //    if (vector::searchElemntForValue(vao::id, id) == -1)
    //    {
    //        std::cerr << "FAILED: not found VAO width id: " << id << std::endl;
    //        throw "FAILED_BIND_VAO";
    //    }
    //}
    glBindVertexArray(id);
    saveID = id;
    selectID = id;
}

std::vector<float> vao::FileOBJtoVVO(const char* pathToObj, bool normal, bool textCoord)
{
    std::vector<float> v;
    std::vector<float> v_n;
    std::vector<float> v_t;
    std::vector<float> result;
    std::vector<int> f;

    obj_loaders::load(v, f, v_n, v_t, pathToObj);

    for (unsigned int index = 0; index < f.size() / N_ELEMENT_TO_FACE; index++)
    {
        unsigned int v_index = f[index * N_ELEMENT_TO_FACE] - 1;
        result.push_back(v[v_index * N_ELEMENT_TO_VERT]);
        result.push_back(v[v_index * N_ELEMENT_TO_VERT + 1]);
        result.push_back(v[v_index * N_ELEMENT_TO_VERT + 2]);

        if (normal)
        {
            unsigned int vn_index = f[index * N_ELEMENT_TO_FACE + 2] - 1;
            //std::cout << v_n[vn_index * N_ELEMENT_TO_NORMAL_VERT] << std::endl;
            result.push_back(v_n[vn_index * N_ELEMENT_TO_NORMAL_VERT]);
            result.push_back(v_n[vn_index * N_ELEMENT_TO_NORMAL_VERT + 1]);
            result.push_back(v_n[vn_index * N_ELEMENT_TO_NORMAL_VERT + 2]);
        }

        if (textCoord)
        {
            unsigned int vt_index = f[index * N_ELEMENT_TO_FACE + 1] - 1;

            result.push_back(v_t[vt_index * N_ELEMENT_TO_TEXTURE_VERT]);
            result.push_back(v_t[vt_index * N_ELEMENT_TO_TEXTURE_VERT + 1]);
        }
    }

    return result;
}

float* vao::FileOBJtoVAO(const char* pathToObj, int& sizeArray, bool normal, bool textCoord)
{
    std::vector<float> vec = vao::FileOBJtoVVO(pathToObj, normal, textCoord);
    sizeArray = vec.size();
    int size;
    return array::vectorToArray(vec, size);
}

std::vector<float> vao::addElementToVVO(std::vector<float> data, int n_elementForVert, std::vector<float> democratedData, int n_democratedElementForVert)
{
    std::vector<float> new_vector;

    const unsigned char finishVertIndex = n_elementForVert + n_democratedElementForVert;
    const unsigned int finishElementIndex = data.size() + democratedData.size();

    unsigned int i = 0, finish_i = n_elementForVert;
    unsigned int j = 0, finish_j = n_democratedElementForVert;

    for (unsigned int index = 0; index < finishElementIndex; index += finishVertIndex)
    {
        while (i < finish_i)
        {
            new_vector.push_back(data[i]);
            i++;
        }

        while (j < finish_j)
        {
            new_vector.push_back(democratedData[j]);
            j++;
        }
        
        finish_i += n_elementForVert;
        finish_j += n_democratedElementForVert;
    }

    return new_vector;
}

float* vao::addElementToVAO(float* data, int size_data, int n_elementForVert, float* democratedData, int size_democratedData, int n_democratedElementForVert, int& size_VAO)
{
    std::vector<float> v_data = vector::arrayToVector_float(data, size_data);
    std::vector<float> v_democratedData = vector::arrayToVector_float(democratedData, size_democratedData);

    std::vector<float> new_vector = vao::addElementToVVO(v_data, n_elementForVert, v_democratedData, n_democratedElementForVert);

    return array::vectorToArray(new_vector, size_VAO);
}

unsigned int vao::create(float* data, int sizeOfByte)
{
    unsigned int VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
  
    vao::idVAO.push_back(VAO);
    vao::idVBO.push_back(VBO);

    bind(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeOfByte, data, GL_STATIC_DRAW);
    bind(0);

    //for (int i = 0; i < sizeOfByte; i++)
    //{
    //    std::cout << i << " : " << data[i] << std::endl;
    //}

    return VAO;
}

unsigned int vao::create(std::vector<float> data)
{
    unsigned int VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    vao::idVAO.push_back(VAO);
    vao::idVBO.push_back(VBO);

    bind(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data[0]), data.data(), GL_STATIC_DRAW);
    bind(0);

    return VAO;
}

void vao::addAttribute(unsigned int id, int index, int n, int size, int indentation)
{
    bind(id);
    glVertexAttribPointer(
        index, n, GL_FLOAT, GL_FALSE, size * sizeof(GLfloat),
        (GLvoid *)(indentation * sizeof(GLfloat))
    );
    glEnableVertexAttribArray(index);
    bind(0);
}

void vao::Delete(unsigned int id)
{
    unsigned int index = vector::searchElementForValue(vao::idVAO, id);

    if (index != -1)
    {
        glDeleteVertexArrays(1, &id);
        glDeleteBuffers(1, &vao::idVBO[index]);

        std::vector<unsigned int>::const_iterator iterVAO = vao::idVAO.cbegin();
        std::vector<unsigned int>::const_iterator iterVBO = vao::idVBO.cbegin();

        vao::idVAO.erase(iterVAO + index);
        vao::idVBO.erase(iterVBO + index);
    }
}

void vao::DeleteALL()
{
    for (int i = 0; i < vao::idVAO.size(); i++)
    {
        glDeleteVertexArrays(1, &vao::idVAO[i]);
        glDeleteBuffers(1, &vao::idVBO[i]);
        //vao::id[i] = 0;
    }

    vao::idVAO.clear();
    vao::idVBO.clear();
}

void vao::draw(PRIMITIVE  Primitive, int first_vert, int count_vert)
{
    glDrawArrays(convertPrimitive(Primitive), first_vert, count_vert);
}

void vao::draw(PRIMITIVE  Primitive, unsigned int VAO, int first_vert, int count_vert)
{
    bind(VAO);
    glDrawArrays(convertPrimitive(Primitive), first_vert, count_vert);
    //bind(0);
}

void vao::setSizePoints(float sizePixel)
{
    glPointSize(sizePixel);
}

void vao::setWidthLine(float width)
{
    glLineWidth(width);
}

#pragma endregion
#pragma region VAO

VAO::VAO(float* data, int sizeOfByte, int elementToVert) : 
    elementToVert(elementToVert), size(sizeOfByte / sizeof(float))
{
    this->id = vao::create(data, sizeOfByte);
}

VAO::VAO(std::vector<float> data, int elementToVert) : 
    elementToVert(elementToVert), size(data.size())
{
    this->id = vao::create(data);
}

VAO::~VAO()
{
    vao::Delete(this->id);
}

void VAO::addAttribute(int index, int n, int indentation) const
{
    vao::addAttribute(this->id, index, n, this->elementToVert, indentation);
}

void VAO::bind() const
{
    vao::bind(this->id);
}

void VAO::draw(PRIMITIVE Primitive, int first_vert, int count_vert) const
{
    vao::setSizePoints(this->sizePoint);
    vao::setWidthLine(this->widthLine);

    if (vao::getSelectId() != this->id)
    {
        this->bind();
    }

    if (count_vert == 0)
    {
        vao::draw(Primitive, first_vert, this->size / this->elementToVert * 3);
    }
    else
    {
        vao::draw(Primitive, first_vert, count_vert);
    }
}

void core::VAO::setSizePoints(float sizePixel)
{
    this->sizePoint = sizePoint;;
}

void core::VAO::setWidthLine(float width)
{
    this->widthLine = width;
}

#pragma endregion