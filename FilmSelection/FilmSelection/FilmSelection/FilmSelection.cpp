#include "FilmSelection.h"
list<shared_ptr<User>> FilmSelection::users;

Title& operator++(Title& m) {
	m = static_cast<Title>(static_cast<int>(m) + 1);
	return m;
}

void FilmSelection::loadDate(string filename)
{
	ifstream in(filename);
	if (!in.is_open())
		throw exception("file not found!");

	if (strstr(filename.c_str(), "test_train_likes")) { //������� train_likes.csv

		string buf,item_id;
		char c;

		Title mode = USER_ID;

		shared_ptr<User> user;
		shared_ptr<Channel> channel;
		bool channel_found = false;
		bool user_found = false;

		//��������

		in.seekg(29);//������� �� ������ ��������, ����� ���� �������� ���������� � ������?
		while (!in.eof())
		{
			in >> c;
			if (c == ','|| c == '.') {
				switch (mode)
				{
				case USER_ID:
					for (auto it = users.begin(); it != users.end(); ++it) {
						if ((*it)->getId() == buf) {
							user = (*it);
							user_found = true;
						}
					}
					if (!user_found) {
						user = make_shared<User>(User());
						user.get()->setId(buf);
						users.push_back(user);
					}
					break;
				case ITEM_ID:
					item_id = buf;
					break;
				case CHANNEL:
					//���� �����-�� ������������ ��� ����� ����� �����, �������������� ���
					for (auto it = users.begin(); it != users.end(); it++) {
						channel = (*it)->findChannel(buf); //���� ����� �� ������ - nullptr
						if (channel != nullptr) {
							if (channel.get()->findFilm(item_id) == nullptr) {
								channel->addFilm(make_shared<Film>(Film(item_id, channel)));
							}
							user.get()->addChannel(channel);
							channel_found = true;
							break;
						}
					}
						
					//����� �� ������, ������� �����
					if (!channel_found) {
						channel = make_shared<Channel>(Channel(user));
						channel.get()->increaseLikes(); //��������� ���������� ������
						channel->addFilm(make_shared<Film>(Film(item_id, channel)));
						user.get()->addChannel(channel);
					}
					break;
				case TIME:
					//��� ����� ���� ��������� ������� ��������� ��� ������� � unordered_multimap(time, ��. ���������) 
					break;
				case NO_TITLE:
					mode = INTERM; //���������� ������������� �����, �.� ������ ���� ������������� mode
					break;
				}
				user_found = false;
				channel_found = false;
				buf.clear();
				++mode;
			}
			else {
				buf += c;
			}
		}
	}
	in.close();
}
