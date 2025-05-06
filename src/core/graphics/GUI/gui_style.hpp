//#include "../../config.hpp"
//
//#if MODULE_GUI

#include "../../util/structs.hpp"
#include <string>

namespace core
{
	struct GuiElementStyle
	{
		position_2f pos = position_2f(0, 0);
		size_2f size = size_2f(0, 0);
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