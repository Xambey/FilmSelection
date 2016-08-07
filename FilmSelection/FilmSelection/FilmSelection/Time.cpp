#include "Time.h"

long double * Time::getTimeStart()
{
	return &time_start;
}

long double * Time::getTimeEnd()
{
	return &time_end;
}

void Time::setTime(long double * start, long double * end)
{
	time_start = *start;
	time_end = *end;
}

void Time::setTimeStart(long double * start)
{
	time_start = *start;
}

void Time::setTimeEnd(long double * end)
{
	time_end = *end;
}
