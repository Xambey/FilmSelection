#include <fstream>
#include "User.h"

using namespace std;

enum Title
{
	USER_ID,
	ITEM_ID,
	CHANNEL,
	TIME,
	NO_TITLE
};

int main()
{
	//парсинг train_likes.csv
	ifstream in("Resources/train_likes.csv");

	if (!in.is_open()) cout << "File not found";

	string buf;
	char c;
	
	Title mode = USER_ID;

	shared_ptr<User> user = make_shared<User>(User());
	shared_ptr<Channel> channel;

	in.seekg(30);//перевод на начало описания, зачем туда закинули именования в начале?
	while (!in.eof())
	{
		in >> c;
		if (c == ',') {
			switch (mode)
			{
			case NO_TITLE:
				mode = USER_ID;
				continue;
			case USER_ID:
				user.get()->setId(buf);
				break;
			case ITEM_ID:
				Channel t;
				t.addFilm(make_shared<Film>(Film(buf,)))
				channel = make_shared<Channel>();
				user.get()->addChannel();
				break;
			case CHANNEL:
				break;
			case TIME:
				break;
				break;
			default:
				user = make_shared<User>(User());
				break;
			}
		}
		else {
			buf += c;
		}
		switch ()
		{
		default:
			break;
		}
	}
	in.close();
	system("pause");
	return 0;
}