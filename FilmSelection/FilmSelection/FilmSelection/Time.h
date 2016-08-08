#ifndef TIME_H
#define TIME_H

#include <string>
#include <list>
#include <iostream>
#include <algorithm>
#include <memory>
#include <fstream>
#include <exception>
#include <unordered_map>

using namespace std;

class Time
{
	long double time_start;
	long double time_end;
	string id_channel;
public:
	Time(long double* start, long double* end, string* channel);
	long double* getTimeStart();
	long double* getTimeEnd();
	string * getChannel();
	void setTime(long double* start, long double* end, string* channel);
	void setTimeStart(long double* start);
	void setTimeEnd(long double* end);
	void setChannel(string* channel);
};

#endif // TIME_H
