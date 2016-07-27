#ifndef FILMSELECTION_H
#define FILMSELECTION_H
#include "User.h"
#include "Enums.h"

class FilmSelection
{
private:
	static list<shared_ptr<User>> users;
public:
	FilmSelection() = default;
	~FilmSelection() = default;
	static void loadDate(list<string>filenames);
	static shared_ptr<Film> findFilmEverywere(string id);
};

#endif //FILMSELECTION_H
