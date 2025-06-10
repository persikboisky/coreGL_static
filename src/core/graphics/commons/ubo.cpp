#include "ubo.hpp"
#include <GL/glew.h>
#include <vector>

using namespace core;

[[maybe_unused]] std::vector<unsigned int> ubo::id;


unsigned int ubo::create(std::vector<void*> data, int size)
{
	return 0;
}

unsigned int ubo::create(const void* data, int size)
{
	unsigned int Id;
	glCreateBuffers(1, &Id);


}

void ubo::bind(unsigned int id)
{
	glBindBuffer(GL_UNIFORM_BUFFER, id);
}
