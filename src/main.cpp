#include <core/core.hpp>
#include <cmath>

using namespace core;
using namespace core::math;

std::vector<float> vertexes = {
//   x  y  z  r  g  b
	-1, 1, 0, 1, 0, 0, // 0
	-1,-1, 0, 0, 1, 0, // 1
	 1,-1, 0, 0, 0, 1, // 2
	 1, 1, 0, 1, 1, 0  // 3
};

std::vector<unsigned int> indexes = { 0, 1, 2, 0, 2, 3 };

int main()
{
	try
	{
		Core::Init();
		Window window = Window(1280, 720, "first window", false);
		window.setIcon("./cubes.png");
		window.setContext();

		VAO vao = VAO(vertexes, 6);
		vao.addAttribute(0, 3, 0);
		vao.addAttribute(1, 3, 3);

		EBO ebo = EBO(indexes);
		ebo.linkVAO(vao);

		Shader shader = Shader();
		shader.add(VERTEX, "./main.vert");
		shader.add(FRAGMENT, "./main.frag");
		shader.create();

		float scale[16] = {
			0.5, 0, 0, 0,
			0, 0.5, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		Camera cam = Camera(Vector3(0, 0, 4), 70, 100);
		cam.setMode(CAM_DYNAMIC);
		cam.setTarget(0, 0, -1);

		while (!window.event->close())
		{
			window.event->update();

			shader.use();
			Matrix4 model = Matrix4(scale);
			shader.UniformMat4(model, "model");
			shader.UniformCamMat4(cam, window, "cam");

			ebo.draw(TRIANGLES);

			window.swapBuffers();
			fbo::setColor(RGB(100, 100, 100));
			fbo::clearBuffers(COLOR_BUFFER);
		}
	}
	catch (...)
	{
		Core::Terminate();
		return -1;
	}

	Core::Terminate();
	return 0;
}
