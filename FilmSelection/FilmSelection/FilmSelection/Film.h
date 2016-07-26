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

/*�����, �����, �����, �������������! :p
* ��������� �� �������� ��������� filmSelection->user->channel->film,
* �� ���� ������� �������� ��� �������
*/

class Channel;
class Film
{
private:
	string id;
	long long duration; //����������� ����������������� ������
	long long year; //���
	int genre; //���� 	
	unsigned int count_likes;
	shared_ptr<list<string>> optional; //��������� �� ������ ������������ ����������
	shared_ptr<Channel> parent;
public:
	//����������� ��� �����
	Film(string id_item, long long _duration, long long _year, int _genre,shared_ptr<list<string>> ptr, shared_ptr<Channel> object = nullptr);
	Film(string id_item, shared_ptr<Channel> object = nullptr); //����������� � ������
	inline string getId() const;
	void increaseLikes();
	~Film() = default;
};

#endif //FILM_H

