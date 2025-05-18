#ifndef SRC_CORE_AUDIO_ASOURCE_HPP_
#define SRC_CORE_AUDIO_ASOURCE_HPP_

namespace core
{
	struct pos3f;

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

			// команды управления
			void play() const;
			void pause() const;
			void stop() const;
			void resume() const;

			bool isPlaying() const;

			// 3D ОПЦИИ
			void setPos(float x, float y, float z) const;
			void setPos(pos3f pos) const;

			void setVelocity(float x, float y, float z) const;
		};
	}
}

#endif // !SRC_CORE_AUDIO_ASOURCE_HPP_
