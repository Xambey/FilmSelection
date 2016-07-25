#include "Film.h"

Film::Film(string id_item, long long _duration, long long _year, int _genre, shared_ptr<list<string>> ptr, shared_ptr<Channel> object) :
	id(id_item),
	duration(_duration),
	year(_year),
	genre(_genre),
	optional(ptr)
{
}

Film::Film(string id_item, shared_ptr<Channel> object) :
	id(id_item),
	parent(object)
{
}
