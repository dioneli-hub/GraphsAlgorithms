class utils
{
private:
	static string prefix(int selected, int menu) {
		return selected % 4 == menu ? ">> " : "";
	}

	static string suffix(int selected, int menu) {
		return selected % 4 == menu ? " <<" : "";
	}

	static void menu_item(string text, int selected, int number) {
		cout << "\t    " << prefix(selected, number) << text << suffix(selected, number) << endl;
	}

	static void refresh_menu(int selected) {
		clearScreen();
		cout << endl << endl << endl << endl;
		cout << "\t\tMENU" << endl << endl;
		menu_item("BFS/DFS", selected, 0);
		menu_item("Dijkstra", selected, 1);
		menu_item("Author ", selected, 2);
		menu_item("Exit  ", selected, 3);
	}

	static bool handle_keys(int& selectedMenu) {
		DWORD w;
		HANDLE keyboard = GetStdHandle(STD_INPUT_HANDLE);
		INPUT_RECORD input[1];

		ReadConsoleInput(keyboard, input, 1, &w);

		if (input[0].EventType == KEY_EVENT && input[0].Event.KeyEvent.bKeyDown)
		{
			switch (input[0].Event.KeyEvent.wVirtualScanCode) {
			case 72:
				selectedMenu = abs(selectedMenu - 1);
				break;

			case 80:
				selectedMenu++;
				break;

			case 28:
				return true;
			}
		}

		return false;
	}

public:
	static int abs(int val) {
		return val > 0 ? val : val * -1;
	}

	static int get_menu() {
		int selectedMenu = 0;
		//char key;

		do {
			refresh_menu(selectedMenu);
		} while (!handle_keys(selectedMenu));

		return selectedMenu % 4;
	}

	static void set_console_title() {
		TCHAR title[MAX_PATH];

		StringCchPrintf(title, MAX_PATH, TEXT("Graphs Algorithms. Powered by Diana Levchenko."));
		SetConsoleTitle(title);
	}

	static void resize_window(int width, int height)
	{
		HWND console = GetConsoleWindow(); // Get a console handle
		RECT r; // The RECT structure defines a rectangle by the coordinates of its upper-left and lower-right corners.
		GetWindowRect(console, &r); // stores the console's current dimensions
		MoveWindow(console, r.left, r.top, width, height, TRUE); // changes the size and position of the window
	}

	static void clearScreen()
	{
		HANDLE hStdOut;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD count;
		DWORD cellCount;
		COORD homeCoords = { 0, 0 };

		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

		if (hStdOut == INVALID_HANDLE_VALUE) {
			return;
		}

		if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
			return;
		}

		cellCount = csbi.dwSize.X *csbi.dwSize.Y;

		if (!FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', cellCount, homeCoords, &count)) {
			return;
		}

		if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) {
			return;
		}

		SetConsoleCursorPosition(hStdOut, homeCoords);
	}
};