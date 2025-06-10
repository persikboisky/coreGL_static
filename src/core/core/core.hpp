#ifndef SRC_CORE_CORE_HPP_
#define SRC_CORE_CORE_HPP_

// библиотеки
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include <iostream>

// моё говно
#include "../window/Window.hpp"
#include "../window/Event.hpp"
#include "../window/Cursor.hpp"
#include "../graphics/commons/vao.hpp"
#include "../graphics/commons/fbo.hpp"
#include "../graphics/commons/rbo.hpp"
#include "../graphics/commons/ebo.hpp"
#include "../graphics/commons/ubo.hpp"
#include "../graphics/commons/shader.hpp"
#include "../graphics/commons/texture.hpp"
#include "../graphics/commons/Camera.hpp"
#include "../graphics/commons/font.hpp"
#include "../graphics/commons/BufferText2D.hpp"
#include "../graphics/GUI/gui_style.hpp"
#include "../graphics/GUI/GUI.hpp"
#include "../graphics/GUI/Elements/Button.hpp"
#include "../graphics/GUI/Elements/Image.hpp"
#include "../graphics/renderer/Turtle.hpp"
#include "../graphics/renderer/Rect.hpp"
//#include "graphics/renderer/Scene.hpp"
#include "../file/png.hpp"
#include "../file/text.hpp"
#include "../file/wav.hpp"
#include "../file/binModel.hpp"
#include "../util/vector.hpp"
#include "../util/type.hpp"
#include "../util/array.hpp"
#include "../util/string.hpp"
#include "../math/math.hpp"
#include "../math/Vectors.hpp"
#include "../math/Matrixes.hpp"
#include "../audio/ADevice.hpp"
#include "../audio/Alistener.hpp"
#include "../audio/Abuffer.hpp"
#include "../audio/Asource.hpp"

namespace core
{
	
	struct Core
	{

		/// Инициализирует ядра
		static void Init();

		/// Выключает ядро
		static void Terminate();

		/// @brief Находит время с момента инициализации
		/// @return время с момента инициализации в секундах
		static double GetTime();

	};
}

#endif // !SRC_CORE_CORE_HPP_s