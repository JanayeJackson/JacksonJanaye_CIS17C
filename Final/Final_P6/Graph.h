/* 
 * File:   Graph.h
 * Author: Janaye Jackson
 * Created on June 4, 2024, 6:28 PM
 * Purpose: C++ Program to find Dijkstra's shortest path
 *          and to find Prim's minimum spanning tree
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
#include<iostream>
#include<map>           //map library
using namespace std;

//iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using adjacency list representation
class Graph {
    int V; // No. of vertices
    // Store vertex and weight pair for every edge
    list<pair<int, int> >* adj;
    int **cost;
public:
    Graph(int V); // Constructor
    // function to add an edge to graph
    void addEdge(string, string, int, map<string, int>);
    // prints shortest path from source to destination
    void shortestPath(string, string, map<string, int>);
    bool isValidEdge(int, int, vector<bool>);
    void primMST(map<int, string>, int);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    const int size = V;
    adj = new list<iPair>[V];
    cost = new int *[V];
    for(int i = 0; i < V; i++){
        cost[i] = new int[V];
        for(int j = 0; j < V; j++)
            cost[i][j] = INT_MAX;
    }
}

void Graph::addEdge(string u, string v, int w, map<string, int> val){
    adj[val[u]].push_back(make_pair(val[v], w));
    adj[val[v]].push_back(make_pair(val[u], w));
    cost[val[u]][val[v]] = w;
}

// Prints shortest path from source to destination
void Graph::shortestPath(string src, string des, map<string, int> val)
{
    // Create a priority queue to store vertices being preprocessed
    priority_queue<iPair, vector<iPair>, greater<iPair> >pq;

    // Create a vector for distances, initialize all to infinite
    vector<int> dist(V, INT_MAX);

    // Insert source in priority queue, initialize its distance as 0.
    pq.push(make_pair(0, val[src]));
    dist[val[src]] = 0;

    //Looping until priority queue is empty
    while (!pq.empty()) {
        //First vertex
        int u = pq.top().second;
        pq.pop();

        //Get all adajacent vertex
        list<pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            // Get vertex label and weight of current adjacent of u.
            int v = (*i).first;
            int weight = (*i).second;
            // If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight) {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    // Print shortest distances from source to destination
    cout<<"Distance from "<<src<<" to "<<des<<" is "<<dist[val[des]]<<endl;
}

bool Graph::isValidEdge(int u, int v, vector<bool> inMST){
   if (u == v)
       return false;
   if (inMST[u] == false && inMST[v] == false)
        return false;
   else if (inMST[u] == true && inMST[v] == true)
        return false;
   return true;
}
 
void Graph::primMST(map<int, string> val, int V){  
    vector<bool> inMST(V, false);
    // Include first vertex in MST
    inMST[0] = true;
    // Keep adding edges while number of included
    // edges does not become V-1.
    int edge_count = 0, mincost = 0;
    while (edge_count < V - 1) {
        //Find minimum weight valid edge.  
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {               
                if (cost[i][j] < min) {
                    if (isValidEdge(i, j, inMST)) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            cout<<"Edge "<<edge_count++<<":("<<val[a]<<", "<<val[b]<<") cost: "<<min<<endl; 
            mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
    cout<<"Minimum cost = "<<mincost<<endl;
}
#endif /* GRAPH_H */

