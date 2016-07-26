#ifndef FILM_H
#define FILM_H

#include <string>
#include <list>
#include <iostream>
#include <memory>
#include <fstream>
#include <exception>
#include <unordered_map>

using namespace std;

/*‘ильм, ‘ильм, ‘ильм, ‘ииииииииильм! :p
* »звин€юсь за иерархию включений filmSelection->user->channel->film,
* не было времени обдумать все моменты
*/

class Channel;
class Film
{
private:
	string id;
	long long duration; //коэффициент продолжительности фильма
	long long year; //год
	int genre; //жанр 	
	unsigned int count_likes;
	shared_ptr<list<string>> optional; //указатель на список опциональных переменных
	shared_ptr<Channel> parent;
public:
	//конструктор без лайка
	Film(string id_item, long long _duration, long long _year, int _genre,shared_ptr<list<string>> ptr, shared_ptr<Channel> object = nullptr);
	Film(string id_item, shared_ptr<Channel> object = nullptr); //конструктор с лайком
	inline string getId() const;
	void increaseLikes();
	~Film() = default;
};

#endif //FILM_H

