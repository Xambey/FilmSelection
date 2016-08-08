#include "Time.h"

Time::Time(long double * start, long double * end, string * channel)
	:	
	time_start(*start),
	time_end(*end),
	id_channel(*channel)
{
}

long double * Time::getTimeStart()
{
	return &time_start;
}

long double * Time::getTimeEnd()
{
	return &time_end;
}

string* Time::getChannel()
{
	return &id_channel;
}

void Time::setTime(long double * start, long double * end, string* channel)
{
	time_start = *start;
	time_end = *end;
	id_channel = *channel;
}

void Time::setTimeStart(long double * start)
{
	time_start = *start;
}

void Time::setTimeEnd(long double * end)
{
	time_end = *end;
}

void Time::setChannel(string * channel)
{
	id_channel = *channel;
}
