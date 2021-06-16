
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

#include <list>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include "utils.h"
#include "FSA.h"
#include "Dijkstra.h"

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
/*TODO
* 
* -fix dijkstra
* 

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


			int const n = 5;
			Graph G(n);
			int dist[n], prev[n];
			int start = 2;


			G.addEdge(0, 1, 10);
			G.addEdge(0, 2, 3);
			G.addEdge(1, 2, 1);
			G.addEdge(1, 3, 2);
			G.addEdge(2, 1, 4);
			G.addEdge(2, 3, 8);
			G.addEdge(2, 4, 2);
			G.addEdge(3, 4, 7);
			G.addEdge(4, 3, 9);

			Dijkstra::run(G, dist, prev, start);

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



