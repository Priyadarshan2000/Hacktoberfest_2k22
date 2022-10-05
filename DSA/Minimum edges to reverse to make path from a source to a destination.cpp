#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
 
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;
    list<pair<int, int>> *graph;
 
public:
    // Constructor:
    Graph(int V)
    {
        this->V = V;
        graph = new list<pair<int, int>>[V];
    }
 
    // Adding edges into the graph:
    void addEdge(int u, int v, int w)
    {
        graph[u].push_back(make_pair(v, w));
    }
 
    // Returns shortest path from source to all other vertices.
    vector<int> shortestPath(int source)
    {
        // Create a set to store vertices that are being preprocessed
        set<pair<int, int>> setds;
 
        // Create a vector for distances and initialize all
        // distances as infinite (INF)
        vector<int> distance(V, INF);
 
        // Insert source itself in Set and initialize its distance as 0.
        setds.insert(make_pair(0, source));
        distance = 0;
 
        /* Looping till all shortest distance are finalized
           then setds will become empty */
        while (!setds.empty())
        {
            // The first vertex in Set is the minimum distance
            // vertex, extract it from set.
            pair<int, int> tmp = *(setds.begin());
            setds.erase(setds.begin());
 
            // vertex label is stored in second of pair (it
            // has to be done this way to keep the vertices
            // sorted distance (distance must be first item
            // in pair)
            int u = tmp.second;
 
            list<pair<int, int>>::iterator i;
            for (i = graph[u].begin(); i != graph[u].end(); ++i)
            {
                // Get vertex label and weight of current adjacent
                // of u.
                int v = (*i).first;
                int weight = (*i).second;
 
                //  If there is shorter path to v through u.
                if (distance[v] > distance[u] + weight)
                {
                    /*  If distance of v is not INF then it must be in
                        our set, so removing it and inserting again
                        with updated less distance.
                        Note : We extract only those vertices from Set
                        for which distance is finalized. So for them,
                        we would never reach here.  */
                    if (distance[v] != INF)
                        setds.erase(setds.find(make_pair(distance[v], v)));
 
                    // Updating distance of v
                    distance[v] = distance[u] + weight;
                    setds.insert(make_pair(distance[v], v));
                }
            }
        }
        return distance;
    }
 
    Graph modelGraphWithEdgeWeight(int edge[][2], int E, int V)
    {
        Graph g(V);
        for (int i = 0; i < E; i++)
        {
            // original edge : weight 0
            g.addEdge(edge[i][0], edge[i][1], 0);
 
            // reverse edge : weight 1
            g.addEdge(edge[i][1], edge[i][0], 1);
        }
        return g;
    }
 
    int getMinEdgeReversal(int edge[][2], int E, int V, int source, int destination)
    {
        // get modified graph with edge weight.
        Graph g = modelGraphWithEdgeWeight(edge, E, V);
 
        // distance vector stores shortest path.
        vector<int> dist = g.shortestPath(source);
 
        // If distance of destination is still INF then we cannot reach destination. Hence, not possible.
        if (dist[destination] == INF)
            return -1;
        else
            return dist[destination];
    }
};
 
int main()
{
    int V = 7;
    Graph g(V);
 
    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, {4, 5}, {6, 4}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);
 
    int minEdgeToReverse = g.getMinEdgeReversal(edge, E, V, 0, 6);
 
    if (minEdgeToReverse != -1)
        cout << minEdgeToReverse << endl;
    else
        cout << "Not Possible." << endl;
 
    return 0;
}
