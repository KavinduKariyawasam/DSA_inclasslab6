// The following code shows the implementation of Prim's algorithm:

#include <bits/stdc++.h>
using namespace std;

#define V 6

//Function to find min vertex
int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

//Function to print the constructed
void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

//Function to construct MST
void primMST(int graph[V][V]) 
{
    bool mstSet[V];
    for (int i = 0; i < V; i++) {
        mstSet[i] = false;
    }

    int parent[V];
    int key[V];
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        key[i] = INT_MAX;
    }

    key[0] = 0;       //Setting starting node

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {

        if (graph[u][v] > 0 && mstSet[v] == false && graph[u][v] < key[v]) {
            parent[v] = u;
            key[v] = graph[u][v];
        }
        }
    }
    printMST(parent, graph);
}

int main()
{
    //Adjacancy matrix of the graph
	int graph[V][V] = { { 0, 3, 0, 0, 0, 1 },
						{ 3, 0, 2, 1, 10, 0},
						{ 0, 2, 0, 3, 0, 5 },
						{ 0, 1, 3, 0, 5, 0 },
						{ 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0 } };
	primMST(graph);
    cout << minKey;
	return 0;
}
