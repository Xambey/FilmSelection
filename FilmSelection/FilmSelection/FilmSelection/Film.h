#ifndef FILM_H
#define FILM_H

#include <string>
#include <list>
#include <iostream>
#include <memory>
#include <fstream>
#include <exception>

using namespace std;

/*‘ильм, ‘ильм, ‘ильм, ‘ииииииииильм! :p
* »звин€юсь за иерархию включений filmSelection->user->channel->film,
* не было времени обдумать все моменты
*/
enum Title
{
	USER_ID,
	ITEM_ID,
	CHANNEL,
	TIME,
	NO_TITLE
};

class Channel;
class Film
{
private:
	string id;
	long long duration; //коэффициент продолжительности фильма
	long long year; //год
	int genre; //жанр 	
	shared_ptr<list<string>> optional; //указатель на список опциональных переменных
	shared_ptr<Channel> parent;
public:
	Film(string id_item, long long _duration, long long _year, int _genre,shared_ptr<list<string>> ptr, shared_ptr<Channel> object);
	Film(string id_item, shared_ptr<Channel> object);
	~Film() = default;
};

#endif //FILM_H

