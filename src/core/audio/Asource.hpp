#ifndef SRC_CORE_AUDIO_ASOURCE_HPP_
#define SRC_CORE_AUDIO_ASOURCE_HPP_

namespace audio
{
	class Buffer;

	class Source
	{
	private:
		unsigned int id;

	public:
		Source();
		~Source();

		void linkBuffer(Buffer buffer) const;
		void setVolume(float value = 1.0f) const;
		void setSpeed(float value = 1.0f) const;
		void looping(bool flag = false) const;
		void play() const;
	};
}

#endif // !SRC_CORE_AUDIO_ASOURCE_HPP_
