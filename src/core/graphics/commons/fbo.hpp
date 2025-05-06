#pragma once

#include <vector>

namespace core
{

	struct RGBA;

	enum Buffer
	{
		COLOR_BUFFER = 1,
		DEPTH_BUFFER = 2,
		NONE = 0
	};

	struct fbo
	{
	private:
		static std::vector<unsigned int> id;
		static unsigned int selectID;

		static RGBA color;

	public:
		static void bind(unsigned int id);
		static void bindDefault();

		static void DepthTest(bool flag);
		static void setSize(int width, int height);

		static void setColor(RGBA color);
		static void setColor(float red, float green, float blue, float alpha);

		static void clearBuffers(Buffer buffer1, Buffer beffer2 = NONE, Buffer buffer3 = NONE);

		static unsigned int create();

		static void linkTexture(unsigned int t_id);

		static void Delete(unsigned int id);
		static void DeleteALL();
	};

	class FBO : private fbo
	{

	};

}