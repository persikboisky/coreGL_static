

namespace Time
{
	class Date
	{
	private:
		//char timebuf[26];

	public:
		Date();
	};

	class Timer
	{
	private:
		double startTime;

	public:
		Timer();

		void start();
		double finish() const;
	};
}