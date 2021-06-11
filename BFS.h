#pragma once
#ifndef BFS_H
#define BFS_H



// void BFS();
void BFS() {
	int* size = new int;
	int* start = new int;

	int** G = set_matrix(size);

	show_matrix(G, size);

	int* colors = new int[*size];

	set_colors(colors, size);
	set_starting_point(start, size);

	// BFS

	int u;
	queue<int>Q;

	colors[*start] = 1;
	Q.push(*start);

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

	deallocate_matrix(G, size);
	delete[] colors;
	delete size;
	delete start;
}

#endif