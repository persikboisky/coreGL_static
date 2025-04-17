#include <string>

class Script
{
private:
	std::string code;

public:
	Script(const char* path);

	void run();
};