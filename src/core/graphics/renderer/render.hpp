#ifndef SRC_CORE_GRAPHICS_RENDERER_HPP_
#define SRC_CORE_GRAPHICS_RENDERER_HPP_

#include <vector>

namespace core
{
	enum listRenderModel
	{
		M_CUBE
	};

	struct render
	{
	private:
		static unsigned int shaderID;

		static std::vector<std::vector<float>> vao;
		static std::vector<std::vector<unsigned int>> ebo;

	public:
		static void setModel(listRenderModel model);
		static void draw();
	};

}

#endif // !SRC_CORE_GRAPHICS_RENDERER_HPP_