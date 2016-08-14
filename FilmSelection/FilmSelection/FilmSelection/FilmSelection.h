#ifndef FILMSELECTION_H
#define FILMSELECTION_H
#include "User.h"
#include "Enums.h"

class FilmSelection
{
private:
	static list<shared_ptr<User>> users;
	static list<shared_ptr<Film>> all_films;
public:
	FilmSelection() = default;
	~FilmSelection() = default;
	static void loadDate(list<string> filenames);
	static shared_ptr<Film> findFilmEverywere(string* id);
	static unique_ptr<vector<shared_ptr<Time>>> getScheduleFilm(string * id, string * filename);
	void filmSelection(string* user_id);
	unique_ptr<User> findUser(string* user_id);
};

#endif //FILMSELECTION_H
