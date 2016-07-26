#include "Channel.h"

void Channel::setId(string _id)
{
	id = _id;
}

inline string Channel::getId() const
{
	return id;
}

inline unsigned int Channel::getCountLikes() const
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

shared_ptr<Film> Channel::findFilm(string id_film)
{
	for (auto it = films.begin(); it != films.end(); it++)
		if (id_film == (*it)->getId()) {
			(*it)->increaseLikes();
			return (*it);
		}
	return nullptr;
}

Channel::Channel(string _id, shared_ptr<User> object) :
	id(_id),
	parent(object),
	count_likes(0)
{
}
Channel::Channel(shared_ptr<User> object) :
	parent(object),
	count_likes(0)
{
}

