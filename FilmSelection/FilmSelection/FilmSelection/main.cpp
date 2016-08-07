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
		FilmSelection::loadDate(filenames);
		cout << clock() / (double)CLOCKS_PER_SEC;
		system("pause");
	}
	catch (exception& e)
	{
		cout << endl << e.what();
		system("pause");
		return -1;
	}
	return 0;
}
