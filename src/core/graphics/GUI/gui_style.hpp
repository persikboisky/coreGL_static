//#include "../../config.hpp"
//
//#if MODULE_GUI

#include "../../util/type.hpp"
#include <string>

namespace core
{
	struct GuiElementStyle
	{
		pos2f pos = pos2f(0, 0);
		size2f size = size2f(0, 0);
		RGBA background = RGBA(0, 0, 0, 0);
		RGBA activeBackground = RGBA(0, 0, 0, 0);

		bool hover = false;
		RGBA hoverBackground = RGBA(0, 0, 0, 0);

		std::string text = "";
		std::string pathToImage = "";
	};

	struct GUIstyle
	{

	};
}

//#endif // MODULE_GUI