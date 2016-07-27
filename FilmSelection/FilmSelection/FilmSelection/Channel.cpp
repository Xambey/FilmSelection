#include "Channel.h"

void Channel::setId(string _id)
{
	id = _id;
}

string Channel::getId() const
{
	return id;
}

unsigned int Channel::getCountLikes() const
{
	return count_likes;
}

void Channel::addFilm(shared_ptr<Film> ptr)
{
	films.push_back(ptr);
}

void Channel::increaseLikes()
{
	++count_likes;
}

shared_ptr<Film> Channel::findFilmLike(string id_film)
{
	for (auto it = films.begin(); it != films.end(); it++)
		if (id_film == (*it)->getId()) {
			(*it)->increaseLikes();
			return (*it);
		}
	return nullptr;
}

shared_ptr<Film> Channel::findFilmUnlike(string id_film)
{
	this->films;
	for (auto it: films)
		if (id_film ==  it->getId()) {
			return it;
		}
	return nullptr;
}

Channel::Channel(string _id) :
	id(_id),
	count_likes(0)
{
}
Channel::Channel() :
	count_likes(0)
{
}

