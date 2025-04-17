#ifndef SRC_CORE_AUDIO_DEVICE_HPP_
#define SRC_CORE_AUDIO_DEVICE_HPP_

#include <vector>
#include <string>

struct ALCdevice;
struct ALCcontext;

namespace audio
{
	class Device
	{
	private:
		ALCdevice* device;
		ALCcontext* context;

	public:
		Device();
		~Device();

		void setContext();
	};
}

#endif // !SRC_CORE_AUDIO_DEVICE_HPP_
