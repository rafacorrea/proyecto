#pragma once
#include <time.h>

class Timer
{
	private:
		unsigned long begTime;

public:
	Timer(void);
	~Timer(void);

	void start(); 
	unsigned long elapsedTime();

};

