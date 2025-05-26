#include "../config.hpp"
#include "core.hpp"

void core::Core::Init()
{
	//core::date = new Time::Date();

	if (!glfwInit())
	{
		std::cerr << "Failed init glfw" << std::endl;
		throw "FAILED_INIT_GLFW";
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, WINDOW_RESIZABLE);

	if (CORE_INFO) std::cout << "[0.0]      " << "OK: init glfw" << std::endl;
}

double core::Core::GetTime()
{
	return glfwGetTime();
}

void core::Core::Terminate()
{
	shader::DeleteALL();
	vao::DeleteALL();
	ebo::DeleteALL();
	//fbo::DeleteALL();
	//mtl::Delete();
	texture::DeleteALL();
	//fonts::Text2D::DeleteALL();

	glfwTerminate();
	//delete date;
}