#pragma once
#ifndef FSA_H
#define FSA_H


list<int> l1 = {
	    0, 1, 1, 1, 0, 0,
		0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1,
		0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 1, 0,
};

list<int> l2 = {
		0, 1, 0, 0, 1, 
		1, 0, 1, 1, 1, 
		0, 1, 0, 1, 0, 
		0, 1, 1, 0, 1, 
		1, 1, 0, 1, 0, 
};

list<int> l3 = {
		0, 1, 0, 0, 1,
		0, 0, 1, 1, 1,
		0, 0, 0, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 0, 1, 0,
};

list<int> l4 = {
		0, 1, 1, 0, 0,
		0, 0, 1, 0, 1,
		0, 0, 0, 1, 0,
		0, 0, 0, 0, 1,
		0, 0, 0, 0, 0,
};

vector<list<int>> TESTS = { l1,l2,l3,l4 };


class FSA 
{
private:
	static int** set_matrix(int* size) {
		cout << "Enter the size of the matrix: " << endl;
		cin >> *size;

		// creating the adjacency matrix
		int** Matrix = new int* [*size];
		for (int i = 0; i < *size; i++)
			*(Matrix + i) = new int[*size];

		cout << "Fill the matrix with values: " << endl;

		// filling the matrix with values
		for (int i = 0; i < *size; i++)
			for (int j = 0; j < *size; j++)
				cin >> Matrix[i][j];
		cout << "\n\n";

		return Matrix;
	}

	static int** set_matrix_example(int* size) {

		int test_No = rand() % TESTS.size();
		list <int> test = TESTS[test_No];
		*size = sqrt(test.size());

		int** Matrix = new int* [*size];
		
		// creating the adjacency matrix
		for (int i = 0; i < *size; i++)
			*(Matrix + i) = new int[*size];

		list<int>::iterator x=test.begin();

		// filling the matrix with the example values
		for (int i = 0; i < *size; i++)
			for (int j = 0; j < *size; j++) {
				Matrix[i][j] = *x;
				++x;
			}
				

		return Matrix;
	}

	static void show_matrix(int** m, int* const size) {
		cout << "Matrix:\n\n";

		for (int i = 0; i < *size; i++) {
			for (int j = 0; j < *size; j++)cout << m[i][j] << " ";
			cout << endl;
		}

		cout << "\n";
	}

	static void set_colors(int* colors, int* const size) {
		// fill in colors

		for (int i = 0; i < *size; i++)
			colors[i] = 0;
	}

	static void set_starting_point(int* start, int* const size) {
		cout << "Please, enter the starting point:" << endl;

		do {
			cin >> *start;
		} while (!(*start < *size));

		cout << "\n";
	}

	static void deallocate_matrix(int** m, int* const size) {

		for (int i = 0; i < *size; i++)
			delete[] m[i]; //removing component arrays

		delete[] m;
	}


public:
	static void run() {

		/*
			 {0,1,1,1,0,0},
			 {0,0,0,0,1,0},
			 {0,1,0,0,0,0},
			 {0,0,0,0,0,1},
			 {0,0,0,0,0,0},
			 {0,0,1,0,1,0},
		*/
		int* size = new int;
		int* start = new int;

		int** G = set_matrix_example(size);
		
		//int** G = set_matrix(size); // alternative way of filling the matriz via the input

		show_matrix(G, size);

		int* colors = new int[*size];

		set_colors(colors, size);
		set_starting_point(start, size);

		// BFS

		int u;
		queue<int>Q;

		colors[*start] = 1;
		Q.push(*start);

		cout << ">>>> BFS <<<<" << endl;
		cout << "Starting node: " << *start << endl;
		while (!Q.empty()) {
			u = Q.front();
			Q.pop();
			for (int i = 0; i < *size; i++) {
				if (G[u][i] == 1) {
					if (colors[i] == 0) {
						colors[i] = 1;
						Q.push(i);
						cout << "Node " << i << endl;
					}

					colors[u] = 2;
				}
			}
		}
		cout << "\n\n";


		// DFS
		set_colors(colors, size);

		stack<int> mystack;

		colors[*start] = 1;
		mystack.push(*start);

		cout << ">>>> DFS <<<<" << endl;
		cout << "Starting node: " << *start << endl;
		while (!mystack.empty()) {
			u = mystack.top();
			mystack.pop();
			for (int i = 0; i < *size; i++) {
				if (G[u][i] == 1) {
					if (colors[i] == 0) {
						colors[i] = 1;
						mystack.push(i);
						cout << "Node " << i << endl;

					}
				}
			}
		}

		system("pause");

		deallocate_matrix(G, size);
		delete[] colors;
		delete size;
		delete start;
	};

};


#endif