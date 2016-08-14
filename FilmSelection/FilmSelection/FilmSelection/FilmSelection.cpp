#include "FilmSelection.h"

list<shared_ptr<User>> FilmSelection::users;
list<shared_ptr<Film>> FilmSelection::all_films;

Schedule& operator++(Schedule& m) {
	int x = static_cast<int>(m);
	if (x == 3)
		m = static_cast<Schedule>(0);
	else
		m = static_cast<Schedule>(x + 1);
	return m;
}

//автоперевод в 0
Title& operator++(Title& m) {
	int x = static_cast<int>(m);
	if (x == 3)
		m = static_cast<Title>(0);
	else
		m = static_cast<Title>(x + 1);
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

			Title mode = Title::USER_ID;
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
					case Title::USER_ID:
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
					case Title::ITEM_ID:
						item_id = buf;
						break;
					case Title::CHANNEL:
						for (auto it = users.begin(); it != users.end(); it++) {
							channel = (*it)->findChannelLike(&buf);
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
							channel->increaseLikes(); 

							shared_ptr<Film> t = make_shared<Film>(Film(&item_id));
							channel->addFilm(t);
							user->addChannel(channel);
							all_films.push_back(t);
							break;
						}
					case Title::TIME:
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
					id = minibuf;

					minibuf = "duration";
					pos = buff.find(minibuf) + 10;
					minibuf.clear();
					for (auto it = buff.begin() + pos; it != buff.end(); it++) {
						if (*it == ',')
							break;
						else
							minibuf += *it;
					}
					duration = stold(minibuf);

					minibuf = "year";
					pos = buff.find(minibuf) + 6;
					minibuf.clear();
					for (auto it = buff.begin() + pos; it != buff.end(); it++) {
						if (*it == ',')
							break;
						else
							minibuf += *it;
					}
					year = stold(minibuf);


					minibuf = "genre";
					pos = buff.find(minibuf) + 7;
					minibuf.clear();
					for (auto it = buff.begin() + pos; it != buff.end(); it++) {
						if (*it == ',')
							break;
						else
							minibuf += *it;
					}
					genre = stoi(minibuf);
					auto film = findFilmEverywere(&id);

					if (film == nullptr) {
						all_films.push_back(make_shared<Film>(Film(&id, &duration, &year, &genre)));
					}
					else {
						film.get()->setDuration(&duration);
						film.get()->setGenre(&genre);
						film.get()->setYear(&year);
					}
					buff.clear();
				}
			}
			in.close();
		}
		else if (filename == "Resources/schedule.csv") {
			ifstream in(filename);
			if (!in.is_open())
				throw "file not found!";

			string buffer, _item_id;
			long double time_start, time_end;
			char n;
		    Schedule s_mode = Schedule::TIME_END;

			in.seekg(35);

			while (!in.eof()) {
				in >> n;
				if (n == ',' || n == '.') {
					switch (s_mode)
					{
					case Schedule::TIME_END:
						buffer += '.';
						if (n == '.')
							while ((n = in.get()) != ',')
								buffer += n;
						else
							buffer += ".0";
						time_end = stold(buffer);
						break;
					case Schedule::TIME_START:
						if (n == '.') {
							buffer += '.';
							while ((n = in.get()) != ',')
								buffer += n;
						}
						else
							buffer += ".0";
						time_start = stold(buffer);
						break;
					case Schedule::ITEM_ID:
						_item_id = buffer;
						cout << (int)in.tellg();
						break;
					case Schedule::CHANNEL:
						auto it = findFilmEverywere(&buffer);
						if (it == nullptr) break;//film not found
						Time t(&time_start,&time_end,&buffer);

						it->getTime()->push_back(t);
						break;
					}
					buffer.clear();
					++s_mode;
				}
				else {
					buffer += n;
				}
			}
			in.close();
		}
	}
}

shared_ptr<Film> FilmSelection::findFilmEverywere(string* id)
{
	for (auto it = all_films.begin(); it != all_films.end(); ++it)
		if (*((*it)->getId()) == *id)
			return *it;

	return nullptr;
}

unique_ptr<vector<shared_ptr<Time>>> FilmSelection::getScheduleFilm(string* id, string* filename)
{
	string buf, str;
	long double time_start, time_end;
	Schedule mode = Schedule::TIME_END;
	ifstream in(*filename);
	vector<shared_ptr<Time>> time;
	int count = 0;
	int count2 = 0;

	getline(in, buf);

	while (!in.eof()) {
		getline(in, buf);
		if (buf.find(*id) != string::npos)
		{
			count++;
			for (auto it = buf.begin(); it != buf.end(); it++) {
				while (*it != ',') {
					str += *it;
					it++;
					if (it == buf.end()) {
						it--;
						break;
					}
				}
				switch (mode)
				{
				case Schedule::TIME_END:
					time_end = stold(str);
					break;
				case Schedule::TIME_START:
					time_start = stold(str);
					break;
				case Schedule::ITEM_ID:
					break;
				case Schedule::CHANNEL:
					count2++;
					time.push_back(make_shared<Time>(Time(&time_start, &time_end, &str)));
					break;
				}
				str.clear();
				++mode;
			}
		}
		buf.clear();
	}
	cout << count2 << endl;
	cout << count;
	in.close();	
	return make_unique<vector<shared_ptr<Time>>>(time);
}

void FilmSelection::filmSelection(string * user_id)
{
	shared_ptr<User> user(findUser(user_id));
	
	if (!user) throw "user not found\n";
	

}

unique_ptr<User> FilmSelection::findUser(string * user_id)
{
	for (auto it = users.begin(); it != users.end(); it++)
		if (*((*it)->getId()) == *user_id)
			return make_unique<User>(*it);
	return nullptr;
}
