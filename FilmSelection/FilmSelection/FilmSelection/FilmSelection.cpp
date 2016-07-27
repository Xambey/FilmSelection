#include "FilmSelection.h"
list<shared_ptr<User>> FilmSelection::users;

//оператор инкремента, перечисляемого типа
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
	for (auto filename : filenames) { //У МЕНЯ ЗАНИМАЕТ 10 МИН
		if (filename == "Resources/train_likes.csv") { //парсинг train_likes.csv
			ifstream in(filename);
			if (!in.is_open())
				throw "file not found!";
			string buf, item_id;
			char c;

			Title mode = USER_ID;

			shared_ptr<User> user;
			shared_ptr<Channel> channel;
			bool channel_found = false;
			bool user_found = false;

			//ВНИМАНИЕ

			in.seekg(28);//перевод на начало описания, зачем туда закинули именования в начале?
			while (!in.eof())
			{
				in >> c;
				if (c == ',' || c == '.') {
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
						//если какой-то пользователь уже имеет такой канал, инкрементируем его
						for (auto it = users.begin(); it != users.end(); it++) {
							channel = (*it)->findChannelLike(buf); //если канал не найден - nullptr
							if (channel != nullptr) {
								if (channel->findFilmLike(item_id) == nullptr) {
									channel->addFilm(make_shared<Film>(Film(item_id)));
								}
								user.get()->addChannel(channel);
								channel_found = true;
								break;
							}
						}

						//канал не найден, создаем новый
						if (!channel_found) {
							channel = make_shared<Channel>(Channel());
							channel.get()->increaseLikes(); //увеличить количество лайков
							channel.get()->setId(buf);
							channel->addFilm(make_shared<Film>(Film(item_id)));
							user.get()->addChannel(channel);
						}
						break;
					case TIME:
						//тут могла быть установка времени просмотра для фильмов в unordered_multimap(time, см. интерфейс) 
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
			//Опциональные данные игнорируются, времени на них нет, для примерной точности они особо и не нужны


			//Json::Reader reader;
			//Json::Value root;
			////взято с https://stackoverflow.com/questions/4273056/jsoncpp-not-reading-files-correctly
			//reader.parse(in, root, false);
			//
			//string encoding = root.get("encoding", "UTF-8").asString();
			ifstream in(filename);
			if (!in.is_open())
				throw "file not found!";

			string buff("");
			string minibuf, id;
			long double duration, year;
			int genre;
			char s;
			bool miss = false;
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
					//считываем данные для обновления
					minibuf = "id";
					pos = buff.find(minibuf) + 5;
					minibuf.clear();
					for (auto it = pos; it < buff.size(); it++) {
						if (buff[it] == '"')
							break;
						else
							minibuf += buff[it];
					}
					id = minibuf;
					minibuf = "duration";
					pos = buff.find(minibuf) + 10;
					minibuf.clear();
					for (auto it = pos; it < buff.size(); it++) {
						if (buff[it] == ',')
							break;
						else
							minibuf += buff[it];
					}
					duration = stold(minibuf);
					minibuf = "year";
					pos = buff.find(minibuf) + 6;
					minibuf.clear();
					for (auto it = pos; it < buff.size(); it++) {
						if (buff[it] == ',')
							break;
						else
							minibuf += buff[it];
					}
					year = stold(minibuf);

					minibuf = "genre";
					pos = buff.find(minibuf) + 7;
					minibuf.clear();
					for (auto it = pos; it < buff.size(); it++) {
						if (buff[it] == ',')
							break;
						else
							minibuf += buff[it];
					}
					genre = stoi(minibuf);
					auto film = findFilmEverywere(id);
					if (film == nullptr) throw "Film not found! ";
					film.get()->setDuration(duration);
					film.get()->setGenre(genre);
					film.get()->setYear(year);
					//++mode;
					buff.clear();
					in.get();
					if (!in.eof())
						in.get();
				}
			}
			in.close();
		}
	}
}

shared_ptr<Film> FilmSelection::findFilmEverywere(string id)
{
	for (auto it: users) {
		for (auto f = it->getChannels()->begin(); f != it->getChannels()->end(); f++) {
			shared_ptr<Film> t (f->get()->findFilmUnlike(id));
			if (t == nullptr)
				continue;
			else
				return t;
		}
	}
	return nullptr;
}

