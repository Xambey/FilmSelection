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
//#include "jsoncpp\include\json\json.h" //���������� ���������� jsoncpp

using namespace std;

/*�����, �����, �����, �������������! :p
* ��������� �� �������� ��������� filmSelection->user->channel->film,
* �� ���� ������� �������� ��� �������
*/

class Channel;
class Film
{
private:
	string id;
	long double duration; //����������� ����������������� ������
	long double year; //���
	int genre; //���� 	
	unsigned int count_likes;
	shared_ptr<list<string>> optional; //��������� �� ������ ������������ ����������
public:
	//����������� ��� �����
	Film(string id_item, long double _duration, long double _year, int _genre,shared_ptr<list<string>> ptr);
	Film(string id_item); //����������� � ������
	string getId() const;
	void setId(string _id);
	void setDuration(long double _dur);
	void setYear(long double _year);
	void setGenre(int gen);
	void increaseLikes();
	~Film() = default;
};

#endif //FILM_H

