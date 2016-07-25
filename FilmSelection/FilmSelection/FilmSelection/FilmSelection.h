#ifndef FILMSELECTION_H
#define FILMSELECTION_H
#include "User.h"
#include "Enums.h"

class FilmSelection
{
public:
	FilmSelection() = default;
	~FilmSelection() = default;
	static void loadDate(string filename);
};

#endif //FILMSELECTION_H
