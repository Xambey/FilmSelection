#include "Film.h"

Film::Film(string id_item, long double _duration, long double _year, int _genre, shared_ptr<list<string>> ptr) :
	id(id_item),
	duration(_duration),
	year(_year),
	genre(_genre),
	optional(ptr),
	count_likes(0)
{
	increaseLikes();
}

Film::Film(string id_item) :
	id(id_item),
	count_likes(0)
{
	increaseLikes();
}

string Film::getId() const
{
	return id;
}

void Film::setId(string _id)
{
	id = _id;
}

void Film::setDuration(long double _dur)
{
	duration = _dur;
}

void Film::setYear(long double _year)
{
	year = _year;
}

void Film::setGenre(int gen)
{
	genre = gen;
}

void Film::increaseLikes()
{
	count_likes++;
}
