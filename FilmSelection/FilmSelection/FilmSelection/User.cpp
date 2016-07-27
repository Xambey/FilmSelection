#include "User.h"

void User::setId(string _id)
{
	id = _id;
}

void User::addChannel(shared_ptr<Channel> ptr)
{
	channels.push_front(ptr);
}

string User::getId() const
{
	return id;
}

shared_ptr<list<shared_ptr<Channel>>> User::getChannels()
{
	return make_shared<list<shared_ptr<Channel>>>(channels);
}

shared_ptr<Channel> User::findChannelLike(string id_channel)
{

	for (auto it = channels.begin(); it != channels.end(); it++)
		if (id_channel == (*it)->getId()) {
			(*it)->increaseLikes();
			return *it;
		}
	return nullptr;
}
