#include <iostream>
using namespace std;
#include <limits.h>

#define V 6

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void print(int dist[], int src)
{
    double total = 0;
    cout << "\n" << "Shortest time for each city from city " << src << " are," << "\n" << endl;

	for (int i = 1; i < V; i++){
        cout << "From city " << src << " to city " << i << " is " << dist[i] << endl;
        total += dist[i];
    }
    cout << "Average time is " << total/(V-1)<< endl;
}


void dijkstra(int graph[V][V], int src)
{
	int dist[V]; 
	bool sptSet[V]; 

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	print(dist,src);
}

int main()
{
	int graph[V][V] = { { 0 , 10 , 0 , 0 , 15 , 5 },
						{ 10 , 0 , 10 , 30 , 0 , 0 },
						{ 0 , 10 , 0 , 12 , 5 , 0},
						{ 0 , 30 , 12 , 0 , 0 , 20 },
						{ 15 , 0 , 5 , 0 , 0 , 0 },
						{ 5 , 0 , 0 , 20 , 0 , 0}};

	dijkstra(graph, 0);
	return 0;
}

