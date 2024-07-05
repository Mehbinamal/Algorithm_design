#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(vector<vector<int>> & adjList, int startnode, vector<bool> visited){
    queue <int> q;
    visited[startnode] = true;
    q.push(startnode);
    while(!q.empty()){
        int currentnode = q.front();
        q.pop();
        cout<<currentnode<<" ";
        for (int neighbor : adjList[currentnode] ){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }    
}

void addEdge(vector<vector<int> >& adjList, int u, int v)
{
    adjList[u].push_back(v);
}

int main()
{
    // Number of vertices in the graph
    int vertices = 5;

    // Adjacency list representation of the graph
    vector<vector<int> > adjList(vertices);

    // Add edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    // Mark all the vertices as not visited
    vector<bool> visited(vertices, false);

    // Perform BFS traversal starting from vertex 0
    cout << "Breadth First Traversal starting from vertex "
            "0: ";
    BFS(adjList, 2, visited);

    return 0;
}