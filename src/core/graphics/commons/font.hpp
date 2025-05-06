#include <string>
#include <vector>

namespace core
{
	class Shader;
	class Texture;

	struct font
	{
		Texture* textureFont;

		float widthSymbol;
		float heightSymbol;

		font(const char* name = "standard");
		~font();
	};
}