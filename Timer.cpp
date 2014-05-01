#include "Timer.h"


Timer::Timer(void)
{
}


Timer::~Timer(void)
{
}

void Timer::start() 
{
	begTime = clock();		
}

unsigned long Timer::elapsedTime() 
{
	return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
}
	

