#include <fstream>
#include "FilmSelection.h"
#include <ctime>
using namespace std;

int main()
{
	try
	{
		list<string>filenames; //Последовательность важна!
		filenames.push_back("Resources/train_likes.csv");
		filenames.push_back("Resources/items.json");
		//filenames.push_back("Resources/schedule.csv");
		FilmSelection::loadDate(filenames);
		shared_ptr<vector<shared_ptr<Time>>> t = move(FilmSelection::getScheduleFilm(new string("66e090fe09ee02393f8c5c87986ed041"), new string("Resources/schedule.csv")));
		cout << clock() / (double)CLOCKS_PER_SEC;
		system("pause");
	}
	catch (exception& e)
	{
		cout << endl << e.what();
		system("pause");
		return -1;
	}
	catch (string& str)
	{

	}
	return 0;
}
