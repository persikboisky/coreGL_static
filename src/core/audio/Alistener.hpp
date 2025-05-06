#ifndef SRC_CORE_AUDIO_LISTENER_HPP_
#define SRC_CORE_AUDIO_LISTENER_HPP_

namespace core
{
	namespace listener
	{
		void setOrientation(float pX, float pY, float pZ, float upX, float upY, float upZ);

		void setPos3f(float x, float y, float z);
		void setUp3f(float x, float y, float z);

		void setVelocity3f(float x, float y, float z);
	};
}
#endif // !SRC_CORE_AUDIO_LISTENER_HPP_