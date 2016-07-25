#ifndef USER_H
#define USER_H

#include "Channel.h"

enum Title
{
	USER_ID,
	ITEM_ID,
	CHANNEL,
	TIME,
	NO_TITLE
};

class User
{
private:
	string id;
	list<shared_ptr<Channel>> channels;//список указателей на каналы
public:
	void setId(string _id);
	void addChannel(shared_ptr<Channel>ptr);
	static void loadDate(string filename);
	User() = default;
	~User() = default;
};

#endif //USER_H

