#ifndef CHANNEL_H
#define CHANNEL_H
#include "Film.h"

class User;
//�����
class Channel
{
private:
	string id;
	unsigned int count_likes;
	list<shared_ptr<Film>> films;
public:
	void setId(string* _id);
	string* getId();
	const unsigned int *getCountLikes() const;
	void addFilm(shared_ptr<Film>ptr);
	void increaseLikes();
	shared_ptr<Film> findFilmLike(string* id_film); //����� � ������ ��� ����������
	shared_ptr<Film> findFilmUnlike(string* id_film);
	Channel(string* _id);
	Channel();
	~Channel() = default;
};

#endif // !CHANNEL_H
