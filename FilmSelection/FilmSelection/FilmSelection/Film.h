#ifndef FILM_H
#define FILM_H

#include <string>
#include <list>
#include <iostream>
#include <algorithm>
#include <memory>
#include <fstream>
#include <exception>
#include <unordered_map>
//#include "jsoncpp\include\json\json.h" //Подключаем библиотеку jsoncpp

using namespace std;

/*Фильм, Фильм, Фильм, Фииииииииильм! :p
* Извиняюсь за иерархию включений filmSelection->user->channel->film,
* не было времени обдумать все моменты
*/

class Channel;
class Film
{
private:
	string id;
	long double duration; //коэффициент продолжительности фильма
	long double year; //год
	int genre; //жанр 	
	unsigned int count_likes;
	shared_ptr<list<string>> optional; //указатель на список опциональных переменных
public:
	//конструктор без лайка
	Film(string id_item, long double _duration, long double _year, int _genre,shared_ptr<list<string>> ptr);
	Film(string id_item); //конструктор с лайком
	string getId() const;
	void setId(string _id);
	void setDuration(long double _dur);
	void setYear(long double _year);
	void setGenre(int gen);
	void increaseLikes();
	~Film() = default;
};

#endif //FILM_H

