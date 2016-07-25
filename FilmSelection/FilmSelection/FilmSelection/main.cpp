#include <fstream>
#include "FilmSelection.h"

using namespace std;

int main()
{
	try
	{
		FilmSelection::loadDate("Resources/train_likes.csv");
		system("pause");
	}
	catch (exception& e)
	{
		cout << e.what();
		system("pause");
	}
	return 0;
}