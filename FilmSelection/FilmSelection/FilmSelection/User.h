#ifndef USER_H
#define USER_H

#include "Channel.h"

using namespace std;

class User
{
private:
	string id;
	list<shared_ptr<Channel>> channels;//список указателей на каналы
public:
	void setId(string _id);
	void addChannel(shared_ptr<Channel>ptr);
	User() = default;
	~User() = default;
};

#endif //USER_H

