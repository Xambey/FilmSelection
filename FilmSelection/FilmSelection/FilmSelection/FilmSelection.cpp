#include "FilmSelection.h"

void FilmSelection::loadDate(string filename)
{
	ifstream in(filename);
	if (!in.is_open())
		throw exception("file not found!");

	if (strstr(filename.c_str(), "train_likes")) { //парсинг train_likes.csv

		string buf;
		char c;

		Title mode = USER_ID;

		shared_ptr<User> user = make_shared<User>(User());
		shared_ptr<Channel> channel;

		//ВНИМАНИЕ

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
					t.addFilm(make_shared<Film>(Film(buf, )))
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
	}
	in.close();
}
