#ifndef SRC_CORE_AUDIO_ABUFFER_HPP_
#define SRC_CORE_AUDIO_ABUFFER_HPP_

namespace core
{
	namespace audio
	{
		class Buffer
		{
		private:
			unsigned int id;

		public:
			unsigned int getID() const;

			Buffer(const char* path);
			~Buffer();
		};
	}
}
#endif // !SRC_CORE_AUDIO_ABUFFER_HPP_
