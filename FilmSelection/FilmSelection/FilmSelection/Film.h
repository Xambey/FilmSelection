#ifndef FILM_H
#define FILM_H

#include <string>
#include <list>
#include <iostream>
#include <memory>
using namespace std;

/*‘ильм, ‘ильм, ‘ильм, ‘ииииииииильм! :p
извин€юсь за иерархию включений user->channel->film
не было времени обдумать все моменты
*/
class Channel;
class Film
{
private:
	string id;
	long long duration; //коэффициент продолжительности фильма
	long long year; //год
	int genre; //жанр 	
	shared_ptr<list<string>> optional; //указатель на список опциональных переменных
	unique_ptr<Channel> parent;
public:
	Film(string id_item, long long _duration, long long _year, int _genre,shared_ptr<list<string>> ptr, shared_ptr<Channel> object);
	Film(string id_item, shared_ptr<Channel> object);
	~Film() = default;
};

#endif //FILM_H

