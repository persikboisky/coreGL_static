#ifndef SRC_CORE_CORE_GRAPHICS_COMMONS_UBO_HPP_
#define SRC_CORE_CORE_GRAPHICS_COMMONS_UBO_HPP_

#include <vector>

namespace core
{
	struct ubo
	{
	private:
		[[maybe_unused]] static std::vector<unsigned int> id;

	public:
		[[nodiscard]] static unsigned int create(std::vector<void*> data, int size);
		[[nodiscard]] static unsigned int create(const void* data, int size);
		static void bind(unsigned int id);
	};

	class UBO : private ubo
	{

	};
}

#endif // !SRC_CORE_CORE_GRAPHICS_COMMONS_UBO_HPP_
