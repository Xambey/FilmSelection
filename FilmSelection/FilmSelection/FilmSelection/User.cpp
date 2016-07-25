#include "User.h"

void User::setId(string _id)
{
	id = _id;
}

void User::addChannel(shared_ptr<Channel> ptr)
{
	channels.push_front(ptr);
}
