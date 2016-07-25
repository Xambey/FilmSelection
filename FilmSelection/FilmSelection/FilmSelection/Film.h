#ifndef FILM_H
#define FILM_H

#include <string>
#include <list>
#include <iostream>
#include <memory>
#include <fstream>
#include <exception>

using namespace std;

/*�����, �����, �����, �������������! :p
* ��������� �� �������� ��������� filmSelection->user->channel->film,
* �� ���� ������� �������� ��� �������
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
	long long duration; //����������� ����������������� ������
	long long year; //���
	int genre; //���� 	
	shared_ptr<list<string>> optional; //��������� �� ������ ������������ ����������
	shared_ptr<Channel> parent;
public:
	Film(string id_item, long long _duration, long long _year, int _genre,shared_ptr<list<string>> ptr, shared_ptr<Channel> object);
	Film(string id_item, shared_ptr<Channel> object);
	~Film() = default;
};

#endif //FILM_H

