#ifndef FILM_H
#define FILM_H

#include "Time.h"
//#include "jsoncpp\include\json\json.h" //подключение библиотеки jsoncpp
/*
* Здесь присутствует следующая иерархия включений:
* filmSelection->user->channel->film->Time,
*/

class Channel;
class Film
{
private:
	string id;
	long double duration; //Коэффициент продолжительности фильма
	long double year; //год
	int genre; //жанр
	unsigned int count_likes;
	shared_ptr<list<Time>> time;
	shared_ptr<list<string>> optional; //список указателей на опциональные переменные
public:
	Film(string* id_item, long double* _duration, long double* _year, int* _genre,shared_ptr<list<string>> option = nullptr, shared_ptr<list<Time>> _time = nullptr);
	Film(string* id_item, shared_ptr<list<string>> option = nullptr, shared_ptr<list<Time>> _time = nullptr); //конструктор, с лайком
	string *getId();
	shared_ptr<list<Time>> getTime();
	void setId(string* _id);
	void setDuration(long double* _dur);
	void setYear(long double* _year);
	void setGenre(int* gen);
	void increaseLikes();
	//Сделать генератор фильмов 

	~Film() = default;
};

#endif //FILM_H
