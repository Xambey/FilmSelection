#include "FilmSelection.h"

list<shared_ptr<User>> FilmSelection::users;
list<shared_ptr<Film>> FilmSelection::all_films;

//автоперевод в 0
Title& operator++(Title& m) {
	int x = static_cast<int>(m);
	if (x == 3)
		m = static_cast<Title>(0);
	else
		m = static_cast<Title>(x + 1);
	return m;
}

FTitle& operator++(FTitle& m) {
	int x = static_cast<int>(m);
	if (x == 3)
		m = static_cast<FTitle>(0);
	else
		m = static_cast<FTitle>(x + 1);
	return m;
}


void FilmSelection::loadDate(list<string> filenames)
{
	for (auto filename : filenames) {
		if (filename == "Resources/train_likes.csv") {
			ifstream in(filename);
			if (!in.is_open())
				throw "file not found!";
			std::string buf, item_id;
			char c;

			Title mode = USER_ID;
			string s;
			shared_ptr<User> user;
			shared_ptr<Channel> channel;
			bool channel_found = false;
			bool user_found = false;

			in.seekg(28);
			while (!in.eof())
			{
				in >> c;
				if (c == ',' || c == '.') {
					switch (mode)
					{
					case USER_ID:
						for (auto it = users.begin(); it != users.end(); ++it) {
							if (*((*it)->getId()) == buf) {
								user = (*it);
								user_found = true;
							}
						}
						if (!user_found) {
							user = make_shared<User>(User(&buf));
							users.push_back(user);
						}
						break;
					case ITEM_ID:
						item_id = buf;
						break;
					case CHANNEL:
						for (auto it = users.begin(); it != users.end(); it++) {
							channel = (*it)->findChannelLike(&buf); //���� ����� �� ������ - nullptr
							if (channel != nullptr) {
								channel_found = true; //Канал найден
								user->addChannel(channel);
								shared_ptr<Film> t = channel->findFilmLike(&item_id);
								if (t == nullptr) {
									t = make_shared<Film>(Film(&item_id));
									channel->addFilm(t);
									all_films.push_back(t);
								}
								else
									t.get()->increaseLikes();
								break;
							}
						}
						if (!channel_found) {
							channel = make_shared<Channel>(Channel(&buf));
							channel->increaseLikes(); //��������� ���������� ������

							shared_ptr<Film> t = make_shared<Film>(Film(&item_id));
							channel->addFilm(t);
							user->addChannel(channel);
							all_films.push_back(t);
							break;
						}
					case TIME:
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
			in.close();
		}
		else if (filename == "Resources/items.json") {
			ifstream in(filename);
			if (!in.is_open())
				throw "file not found!";
			string buff;
			string minibuf, id;
			long double duration, year;
			int genre;
			char s;
			bool active = false;
			FTitle mode = ID;
			size_t pos;

			while (!in.eof())
			{
				in >> s;
				if (s == '[' || s == ']')
					continue;
				else if (s == '{') {
					active = true;
					continue;
				}
				else if (s == '}') {
					active = false;
					continue;
				}
				else if (active) {
					buff += s;
					continue;
				}
				else if (!active) {
					minibuf = "id";
					pos = buff.find(minibuf) + 5;
					minibuf.clear();
					for (auto it = buff.begin() + pos; it != buff.end(); it++) {
						if (*it == '"')
							break;
						else
							minibuf += *it;
					}
					//cout << endl << "minibuff = " << minibuf << endl;
					id = minibuf;
					//if (id == "bf636dea4358b500f7441e8a621849b3")
					//	cout << "Found" << endl;
					//cout << "id = " << id << endl;
					minibuf = "duration";
					pos = buff.find(minibuf) + 10;
					minibuf.clear();
					for (auto it = buff.begin() + pos; it != buff.end(); it++) {
						if (*it == ',')
							break;
						else
							minibuf += *it;
					}
					//cout << "minibuff = " << minibuf << endl;
					duration = stold(minibuf);
					//cout << "duration = " << duration << endl;

					minibuf = "year";
					pos = buff.find(minibuf) + 6;
					minibuf.clear();
					for (auto it = buff.begin() + pos; it != buff.end(); it++) {
						if (*it == ',')
							break;
						else
							minibuf += *it;
					}
					//cout << "minibuff = " << minibuf << endl;
					year = stold(minibuf);
					//cout << "year = " << year << endl;

					minibuf = "genre";
					pos = buff.find(minibuf) + 7;
					minibuf.clear();
					for (auto it = buff.begin() + pos; it != buff.end(); it++) {
						if (*it == ',')
							break;
						else
							minibuf += *it;
					}
					//cout << "minibuff = " << minibuf << endl;
					genre = stoi(minibuf);
					//cout << "genre = " << genre << endl;
					auto film = findFilmEverywere(&id);

					if (film == nullptr) { //����������� �����
						all_films.push_back(make_shared<Film>(Film(&id, &duration, &year, &genre)));
					}
					else {
						film.get()->setDuration(&duration);
						film.get()->setGenre(&genre);
						film.get()->setYear(&year);
						//++mode;
					}
					buff.clear();
				}
			}
			in.close();
		}
		else if (filename == "Resources/schedule.csv") {

		}
	}
}

shared_ptr<Film> FilmSelection::findFilmEverywere(string* id)
{
	shared_ptr<Film> f = make_shared<Film>(Film(id));
	auto it = find(all_films.begin(), all_films.end(), f);
	if (it != all_films.end())
		return *it;
	return nullptr;
}
