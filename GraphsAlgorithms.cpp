
#include <string>
#include <ostream>
#include <istream>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <strsafe.h>
#include <tchar.h>

using namespace std;

#include <queue>
#include <stack>
#include "utils.h"
#include "FSA.h"

/*

	int G[6][6] = {
		 {0,1,1,1,0,0},
		 {0,0,0,0,1,0},
		 {0,1,0,0,0,0},
		 {0,0,0,0,0,1},
		 {0,0,0,0,0,0},
		 {0,0,1,0,1,0},
	};

*/


int main()
{
	int EXIT = 3;
	int choice;
	utils::set_console_title();

	do
	{
		utils::resize_window(300, 300);
		utils::clearScreen();
		choice = utils::get_menu();

		switch (choice)
		{
		case 0: {
			utils::resize_window(700, 700);
			utils::clearScreen();

			FSA::run();

			getchar();
			break;
		}
		case 1: {
			utils::resize_window(700, 700);
			utils::clearScreen();

			cout << "dijkstra" << endl;

			getchar();
			break;
		}
		case 2: {
			utils::clearScreen();
			cout << "Created by Diana Levchenko" << endl;
			getchar();
			break;
		}
		}
	} while (choice != EXIT);

	return EXIT_SUCCESS;
}



