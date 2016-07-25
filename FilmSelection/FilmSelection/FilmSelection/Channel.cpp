#include "Channel.h"



void Channel::addFilm(shared_ptr<Film> ptr)
{
	films.push_back(ptr);
}

