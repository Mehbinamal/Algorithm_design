#include<iostream>
using namespace std;
const int V = 9;

void printSolution(int dist[], int n)
{
    cout<<"\tVertex  \t\t Distance from Source\n";
    for (int i = 0; i < V; i++)
        printf("\t%d \t\t\t\t %d\n", i, dist[i]);
}

int minDistance(int dist[], bool sptSet[])
{
    
    int min = __INT_MAX__, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

void Dijkstras (int graph[V][V], int src){

    int dist[V];
    bool isShortestSet[V];

    for(int i=0;i<V;i++){
        dist[i] = __INT_MAX__;
        isShortestSet[i] = false;
    }

    dist[src] = 0;

    for(int count = 0; count <V-1;count++){
        int u = minDistance(dist, isShortestSet);

        isShortestSet[u] = true;

        for (int v=0;v<V;v++){
            if(!isShortestSet[v] && graph[u][v] && dist[u] != __INT_MAX__ && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);
}

int main()
{
    
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    Dijkstras(graph, 0);
 
    return 0;
}