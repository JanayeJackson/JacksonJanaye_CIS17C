/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 * Created on June 4, 2024, 6:28 PM
 * Purpose: C++ Program to find Dijkstra's shortest path
 *          and to find Prim's minimum spanning tree
 */

#include "Graph.h"

// Driver's code
int main(int argc, char** argv){
    // create the graph with all vertices and edges
    int V = 7;
    Graph g(V);
    //create maps for vertices in graphs
    map<string, int> val;
    val["SFO"] = 0;
    val["ORD"] = 1;
    val["JFK"] = 2;
    val["DFW"] = 3;
    val["MIA"] = 4;
    val["LAX"] = 5;
    val["BOS"] = 6;
    map<int, string> vCost;
    vCost[0] = "SFO";
    vCost[1] = "ORD";
    vCost[2] = "JFK";
    vCost[3] = "DFW";
    vCost[4] = "MIA";
    vCost[5] = "LAX";
    vCost[6] = "BOS";

    //make graph
    g.addEdge("SFO", "BOS", 2703, val);
    g.addEdge("SFO", "ORD", 1847, val);
    g.addEdge("ORD", "BOS", 868, val);
    g.addEdge("ORD", "JFK", 743, val);
    g.addEdge("JFK", "BOS", 189, val);
    g.addEdge("SFO", "DFW", 1465, val);
    g.addEdge("DFW", "ORD", 803, val);
    g.addEdge("DFW", "MIA", 1124, val);
    g.addEdge("MIA", "JFK", 1093, val);
    g.addEdge("MIA", "BOS", 1257, val);
    g.addEdge("SFO", "LAX", 338, val);
    g.addEdge("LAX", "DFW", 1234, val);
    g.addEdge("LAX", "MIA", 2341, val);

    //Shortest path between specified destinations
    g.shortestPath("ORD", "LAX",val);
    g.shortestPath("JFK", "SFO", val);
    cout<<endl;
    //Minimum Spanning Tree
    g.primMST(vCost, V);

    return 0;
}