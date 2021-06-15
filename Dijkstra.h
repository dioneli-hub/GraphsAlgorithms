#pragma once
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

typedef struct nodes {
    int dest;
    int cost;
}node;

class Graph {
    int n;
    list<node>* adjList;
private:
    void showList(int src, list<node> lt) {
        list<node> ::iterator i;
        node tempNode;

        for (i = lt.begin(); i != lt.end(); i++) {
            tempNode = *i;
            cout << "(" << src << ")---(" << tempNode.dest << "|" << tempNode.cost << ") ";
        }
        cout << endl;
    }
public:
    Graph() {
        n = 0;
    }

    Graph(int nodeCount) {
        n = nodeCount;
        adjList = new list<node>[n];
    }

    void addEdge(int source, int dest, int cost) {
        node newNode;
        newNode.dest = dest;
        newNode.cost = cost;
        adjList[source].push_back(newNode);
    }

    void displayEdges() {
        for (int i = 0; i < n; i++) {
            list<node> tempList = adjList[i];
            showList(i, tempList);
        }
    }
    friend class Dijkstra;
};


class Dijkstra
{
private:
    /*static int const n = 5;
    static int dist[n], prev[n];
    static int const start = 1;*/
    static Graph graph1() {
        int const n = 5;
        Graph G(n);
        //int dist[n], prev[n];
        //int start = 1;


        G.addEdge(0, 1, 10);
        G.addEdge(0, 2, 3);
        G.addEdge(1, 2, 1);
        G.addEdge(1, 3, 2);
        G.addEdge(2, 1, 4);
        G.addEdge(2, 3, 8);
        G.addEdge(2, 4, 2);
        G.addEdge(3, 4, 7);
        G.addEdge(4, 3, 9);

        return G;
    }

public:
    //Graph g, int* dist, int* prev, int start
    static void run() {
        Graph g = graph1();
        int n = g.n;
        int start;
        int* dist = new int[n];
        int* prev = new int[n];

        cout << "Enter the starting point:\n";
        cin >> start;
        
        
        for (int u = 0; u < n; u++) {
            dist[u] = 9999;   //set as infinity
            prev[u] = -1;    //undefined previous
        }
        dist[start] = 0;   //distance of start is 0
        set<int> S;       //create empty set S
        list<int> Q;
        for (int u = 0; u < n; u++) {
            Q.push_back(u);    //add each node into queue
        }
        while (!Q.empty()) {
            list<int> ::iterator i;
            i = min_element(Q.begin(), Q.end());
            int u = *i; //the minimum element from queue
            Q.remove(u);
            S.insert(u); //add u in the set
            list<node> ::iterator it;
            for (it = g.adjList[u].begin(); it != g.adjList[u].end(); it++) {
                if ((dist[u] + (it->cost)) < dist[it->dest]) { //relax (u,v)
                    dist[it->dest] = (dist[u] + (it->cost));
                    prev[it->dest] = u;
                }
            }
        }
        cin >> start;
    };
    friend class Graph;
};



#endif