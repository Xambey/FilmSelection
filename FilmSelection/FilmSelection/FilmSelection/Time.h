#ifndef TIME_H
#define TIME_H

class Time
{
	long double time_start;
	long double time_end;
public:
	long double* getTimeStart();
	long double* getTimeEnd();
	void setTime(long double* start, long double* end);
	void setTimeStart(long double* start);
	void setTimeEnd(long double* end);
};

#endif // TIME_H
