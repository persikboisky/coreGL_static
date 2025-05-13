#include <core/core.hpp>

using namespace core;
using namespace core::math;

float vertexes[] = {
//     x    y    z  r  g  b
	-0.5, 0.5, 0.0, 1, 0, 0, // 0 
	-0.5,-0.5, 0.0, 0, 1, 0, // 1
	 0.5,-0.5, 0.0, 0, 0, 1, // 2
	 0.5, 0.5, 0.0, 1, 1, 0  // 3
};

unsigned int indexes[] = { 0, 1, 2, 0, 2, 3 };

static void program()
{
	Core::Init();
	Window window = Window(1280, 720, "first window", true);
	window.setIcon("./res/cubes.png");
	window.setContext();

	Cursor::custom_cursor cursor = window.cursor->create("./res/cursor.png", 0, 0);
	cursor.use();

	fbo::DepthTest(true);
	fbo::setColor(RGB(100, 100, 100));

	VAO vao = VAO(vertexes, sizeof(vertexes), 6);
	vao.addAttribute(0, 3, 0);
	vao.addAttribute(1, 3, 3);

	EBO ebo = EBO(indexes, sizeof(indexes));
	ebo.linkVAO(vao);

	Shader shader = Shader("./res/shaders/main.vert", "./res/shaders/main.frag");

	Camera cam = Camera(Vector3(0, 0, 4), 70.0, 100.0);
	cam.setMode(CAM_DYNAMIC);

	while (!window.event->close())
	{
		window.event->update();

		fbo::setSize(Vector2(window.width, window.height));
		fbo::clearBuffers(COLOR_BUFFER, DEPTH_BUFFER);

		Matrix4 model = Matrix4(1.0f);

		shader.use();
		cam.setUniformProjView(shader, window.width, window.height, "proj");
		ebo.draw(TRIANGLES);

		window.swapBuffers();
	}
}

int main()
{
	try
	{
		program();
	}
	catch (...)
	{
		Core::Terminate();
		return -1;
	}

	Core::Terminate();
	return 0;
}