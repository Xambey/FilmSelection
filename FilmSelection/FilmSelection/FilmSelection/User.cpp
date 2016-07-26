#include "User.h"

void User::setId(string _id)
{
	id = _id;
}

void User::addChannel(shared_ptr<Channel> ptr)
{
	channels.push_front(ptr);
}

inline string User::getId() const
{
	return id;
}

inline shared_ptr<list<shared_ptr<Channel>>> User::getChannels() const
{
	return make_shared<list<shared_ptr<Channel>>>(channels);
}

shared_ptr<Channel> User::findChannel(string id_channel)
{

	for (auto it = channels.begin(); it != channels.end(); it++)
		if (id_channel == (*it)->getId()) {
			(*it)->increaseLikes();
			return *it;
		}
	return nullptr;
}
