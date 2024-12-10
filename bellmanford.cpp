#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Edge {
    int src, dest, weight;
};
void bellmanford(int V,int E,vector<Edge> &edges,int src){
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){
            int u=edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;

        // If we can still relax any edge, it indicates a negative-weight cycle
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    // Input all edges of the graph
    cout << "Enter edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};  // Storing edges in the vector
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    // Run Bellman-Ford algorithm
    bellmanford(V, E, edges, src);

    return 0;
}