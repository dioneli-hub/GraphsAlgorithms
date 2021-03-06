#pragma once
#ifndef DIJKSTRA_H
#define DIJKSTRA_H



class Dijkstra {

private:

    static const int MAX_COST = 1000;

    static void init_costs(int** costs, int** graph, int countOfVertex) {
        for (int i = 0; i < countOfVertex; i++) {
            for (int j = 0; j < countOfVertex; j++) {
                if (graph[i][j] == 0) {
                    costs[i][j] = MAX_COST;
                }
                else {
                    costs[i][j] = graph[i][j];
                }
            }
        }
    }
    
    static void calc_distances(int** cost, int* distance, int* pred, int countOfVertex, int startVertex) {
        int* visited = new int[countOfVertex];
        int calculatedVertex = 0;
        int minDistance = MAX_COST;
        int nextNode = 0;


        for (int i = 0; i < countOfVertex; i++) {
            distance[i] = cost[startVertex][i];
            pred[i] = startVertex;
            visited[i] = 0;
        }

        distance[startVertex] = 0;
        visited[startVertex] = 1;
        calculatedVertex = 1;

        while (calculatedVertex < countOfVertex - 1) {
            minDistance = MAX_COST;
            for (int i = 0; i < countOfVertex; i++) {
                if (distance[i] < minDistance && !visited[i]) {
                    minDistance = distance[i];
                    nextNode = i;
                }
            }

            visited[nextNode] = 1;


            for (int i = 0; i < countOfVertex; i++) {
                if (!visited[i])
                    if (minDistance + cost[nextNode][i] < distance[i]) {
                        distance[i] = minDistance + cost[nextNode][i];
                        pred[i] = nextNode;
                    }

            }

            calculatedVertex++;
        }
    }

    static void print_distances(int* distance, int* pred, int countOfVertex, int startVertex) {
        for (int i = 0; i < countOfVertex; i++) {
            if (i != startVertex) {
                if (distance[i] == MAX_COST) {
                    cout << "No way from vertex #" << startVertex << " to vertex #" << i;
                }
                else {
                    cout << "Distance from vertex #" << startVertex << " to vertex #" << i
                        << " is equal to " << distance[i]
                        << ". Path: " << i;

                    int j = i;

                    do {
                        j = pred[j];
                        cout << " <= " << j;
                    } while (j != startVertex);
                }
                cout << endl;
            }
        }
    }


    static void dijkstra(int** graph, int startVertex, int countOfVertex) {
        int* distance = new int[countOfVertex];
        int* pred = new int[countOfVertex];
        int** costs = new int* [countOfVertex];

        for (int i = 0; i < countOfVertex; i++) {
            costs[i] = new int[countOfVertex];
        }


        init_costs(costs, graph, countOfVertex);
        calc_distances(costs, distance, pred, countOfVertex, startVertex);
        print_distances(distance, pred, countOfVertex, startVertex);
    }

    static void show_matrix(int** m, int const size) {
        cout << "Matrix:\n\n";

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)cout << m[i][j] << " ";
            cout << endl;
        }

        cout << "\n";
    }

    static void set_starting_vertex(int& start, int size) {
        cout << "Please, enter the starting vertex:" << endl;
        do {
            cin >> start;
        } while (!(start < size));
        
        cout << "\n";
    }

    static void deallocate_matrix(int** m, int const size) {

        for (int i = 0; i < size; i++)
            delete[] m[i]; //removing component arrays

        delete[] m;
    }


public:

    static void run() {
        int countOfVertices = 5;
        int startVertex;


        int** weights = new int* [countOfVertices] {
            new int[countOfVertices] { 0, 10, 3, 0, 0 },
                new int[countOfVertices] { 0, 0, 1, 2, 0 },
                new int[countOfVertices] { 0, 4, 0, 8, 2 },
                new int[countOfVertices] { 0, 0, 0, 0, 7 },
                new int[countOfVertices] { 0, 0, 0, 9, 0 }
        };

        show_matrix(weights, countOfVertices);

        set_starting_vertex(startVertex, countOfVertices);

        dijkstra(weights, startVertex, countOfVertices);

        system("pause");
        deallocate_matrix(weights, countOfVertices);
    }

    // alternative demo function
    static void run_with_input() {
        cout << "Please, enter the number of vertices: ";
        int countOfVertices = 0;

        cin >> countOfVertices;

        int** weights = new int* [countOfVertices];
        for (int i = 0; i < countOfVertices; i++) {
            weights[i] = new int[countOfVertices];
        }

        for (int i = 0; i < countOfVertices; i++) {
            for (int j = 0; j < countOfVertices; j++) {
                cout << "weights[" << i << ", " << j << "] = ";
                cin >> weights[i][j];
            }
        }

        int startVertex;

        set_starting_vertex(startVertex, countOfVertices);


        dijkstra(weights, startVertex, countOfVertices);

        system("pause");
        deallocate_matrix(weights, countOfVertices);
    }

};


#endif