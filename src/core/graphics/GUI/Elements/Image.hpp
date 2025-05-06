#pragma once

#include <vector>
#include <string>

namespace core
{
	class VAO;
	class Texture;

	struct GUIstyle;

	class Image
	{
	private:
		std::vector<std::string> vID;
		std::vector<GUIstyle> vStyle;
		std::vector<unsigned int> texture;

		void compileVAO();
		bool flagCompileVAO = false;

		unsigned int vaoID = 0;

	public:
		void add(
			GUIstyle style,
			std::string ID = "image"
		);

		void render();
	};
}

