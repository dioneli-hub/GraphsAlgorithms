#pragma once
#ifndef DFS_H
#define DFS_H

void DFS() {

	int* size = new int;
	int* start = new int;

	int** G = set_matrix(size);

	show_matrix(G, size);

	int* colors = new int[*size];

	set_colors(colors, size);
	set_starting_point(start, size);

	// DFS
	stack<int> mystack;
	int u;

	colors[*start] = 1;
	mystack.push(*start);

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

	deallocate_matrix(G, size);
	delete[] colors;
	delete size;
	delete start;
}


#endif