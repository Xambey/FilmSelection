#ifndef CHANNEL_H
#define CHANNEL_H
#include "Film.h"

//канал
class Channel
{
private:
	unsigned int count_likes;
	list<shared_ptr<Film>> films;
public:
	void addFilm(shared_ptr<Film>ptr);
	Channel() = default;
	~Channel() = default;
};

#endif // !CHANNEL_H
