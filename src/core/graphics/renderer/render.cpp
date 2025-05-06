#include "render.hpp"
#include "../commons/shader.hpp"
#include "../commons/vao.hpp"
#include <vector>

using namespace core;

constexpr const char* PATH_TO_FRAG_SHADER = "./res/renderer/shaders/frag.glsl";
constexpr const char* PATH_TO_VERT_SHADER = "./res/renderer/shaders/vert.glsl";

unsigned int render::shaderID = 0;

std::vector<std::vector<float>> render::vao;
std::vector<std::vector<unsigned int>> render::ebo;

void core::render::setModel(listRenderModel model)
{
	std::vector<float> Vao;
	std::vector<unsigned int> Ebo;

	if (model == M_CUBE) 
	{
		
	}
}

void render::draw()
{
	if (render::shaderID == 0)
	{
		render::shaderID = shader::createFromFile(PATH_TO_VERT_SHADER, PATH_TO_FRAG_SHADER);
	}
}
