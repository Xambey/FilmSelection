#ifndef CHANNEL_H
#define CHANNEL_H
#include "Film.h"

class User;
//канал
class Channel
{
private:
	string id;
	unsigned int count_likes;
	list<shared_ptr<Film>> films;
	shared_ptr<User> parent;
public:
	void setId(string _id);
	inline string getId() const;
	inline unsigned int getCountLikes() const;
	void addFilm(shared_ptr<Film>ptr);
	void increaseLikes();
	shared_ptr<Film> findFilm(string id_film);
	Channel(string _id, shared_ptr<User> object = nullptr);
	Channel(shared_ptr<User> object = nullptr);
	~Channel() = default;
};

#endif // !CHANNEL_H
