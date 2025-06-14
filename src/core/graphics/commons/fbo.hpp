#ifndef SRC_CORE_GRAPHICS_COMMONS_FBO_HPP_
#define SRC_CORE_GRAPHICS_COMMONS_FBO_HPP_

#include "../../util/type.hpp"
#include <vector>

namespace core
{

	namespace math
	{
		class Vector2;
	}

	struct fbo
	{
	private:
		static std::vector<unsigned int> id;
		static unsigned int selectID;

		/*static RGBA color;*/

	public:
		static void bind(unsigned int id);
		static void bindDefault();

		/// @brief включает Z-буфер
		/// @param flag состояние(true - включенно, false - выключенно)
		static void DepthTest(bool flag);

		/// @brief устанавливает размер буфера кадра для текущего контекста
		/// @param width ширина
		/// @param height высота
		static void setSize(int width, int height);
		static void setSize(math::Vector2 size);

		static void setColor(color::RGB color);
		static void setColor(color::RGBA color);
		static void setColor(float red, float green, float blue, float alpha);

		/// @brief чистит указанный(ные) буфер(ы)
		/// @param buffer1 буфер
		/// @param beffer2 буфер (необязательно)
		/// @param buffer3 буфер (необязательно)
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

#endif // !SRC_CORE_GRAPHICS_COMMONS_FBO_HPP_