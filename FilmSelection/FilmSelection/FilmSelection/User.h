#ifndef USER_H
#define USER_H

#include "Channel.h"


class User
{
private:
	//unordered_multimap<shared_ptr<Film>, double> time; //время просмотра фильма(не требуется)
	string id;
	list<shared_ptr<Channel>> channels;//список указателей на каналы
public:
	void setId(string* _id);
	void addChannel(shared_ptr<Channel> ptr); 
	string* getId();
	list<shared_ptr<Channel>> *getChannels();
	shared_ptr<Channel>findChannelLike(string* id_channel); //ищет канал с таким же id , если находит то увеличивает лайки
	User(string* _id);
	User();
	~User() = default;
};

#endif //USER_H

