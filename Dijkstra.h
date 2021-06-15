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
    

public:
    //Graph g, int* dist, int* prev, int start
    static void run(Graph g, int* dist, int* prev, int start) {
        int n = g.n;
        
        
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
        //g.showList(2, *g.adjList);
        for (int i = 0; i < n; i++)
            if (i != start) {
                if (dist[i] == 9999) {
                    cout << start << " to " << i << ", way impassable." << endl;
                    continue;
                }
                cout << start << " to " << i << ", cost: " << dist[i] << ", previous: " << prev[i] << endl;
            }
                
    };
    friend class Graph;
};



#endif