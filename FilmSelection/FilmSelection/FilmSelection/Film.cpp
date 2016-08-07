#include "Film.h"

Film::Film(string* id_item, long double* _duration, long double* _year, int* _genre, shared_ptr<list<string>> option) :
	id((*id_item)),
	duration((*_duration)),
	year((*_year)),
	genre((*_genre)),
	optional(option),
	count_likes(0)
{
}

Film::Film(string* id_item, shared_ptr<list<string>> option) :
	id((*id_item)),
	duration(0),
	year(0),
	genre(0),
	count_likes(0),
	optional(option)
{
	increaseLikes();
}

string *Film::getId()
{
	return &id;
}

void Film::setId(string* _id)
{
	id = (*_id);
}

void Film::setDuration(long double* _dur)
{
	duration = (*_dur);
}

void Film::setYear(long double* _year)
{
	year = (*_year);
}

void Film::setGenre(int* gen)
{
	genre = *gen;
}

void Film::increaseLikes()
{
	count_likes++;
}

