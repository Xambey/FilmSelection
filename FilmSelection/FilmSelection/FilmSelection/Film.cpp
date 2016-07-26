#include "Film.h"

Film::Film(string id_item, long long _duration, long long _year, int _genre, shared_ptr<list<string>> ptr, shared_ptr<Channel> object) :
	id(id_item),
	duration(_duration),
	year(_year),
	genre(_genre),
	optional(ptr),
	parent(object),
	count_likes(0)
{
	increaseLikes();
}

Film::Film(string id_item, shared_ptr<Channel> object) :
	id(id_item),
	parent(object),
	count_likes(0)
{
}

inline string Film::getId() const
{
	return id;
}

void Film::increaseLikes()
{
	count_likes++;
}
