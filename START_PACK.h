#pragma once
#ifndef START_H
#define START_H


int** set_matrix(int* size) {

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

void show_matrix(int** m, int* const size) {

	cout << "\nMatrix:\n";

	for (int i = 0; i < *size; i++) {
		for (int j = 0; j < *size; j++)cout << m[i][j] << " ";
		cout << endl;
	}

	cout << "\n";
}

//refactor
void show_matrix(int m[][6], int* const size) {

	cout << "Matrix:\n";

	for (int i = 0; i < *size; i++) {
		for (int j = 0; j < *size; j++)cout << m[i][j] << " ";
		cout << endl;
	}
}

void set_colors(int* colors, int* const size) {
	// fill in colors

	for (int i = 0; i < *size; i++)
		colors[i] = 0;
}

void set_starting_point(int* start, int* const size) {

	cout << "Enter the starting point:" << endl;

	do {
		cin >> *start;
	} while (!(*start < *size));

	cout << "\n";
}

void deallocate_matrix(int** m, int* const size) {

	for (int i = 0; i < *size; i++)
		delete[] m[i]; //removing component arrays

	delete[] m;
}


#endif