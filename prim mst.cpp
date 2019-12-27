// A C++ program for Prim's Minimum  
// Spanning Tree (MST) algorithm. The program is  
// for adjacency matrix representation of the graph  
#include <bits/stdc++.h> 
using namespace std; 
  
// Number of vertices in the graph  
#define V 5  
  
// A utility function to find the vertex with  
// minimum key value, from the set of vertices  
// not yet included in MST  
int minKey(int key[], bool mstSet[])  
{  
    // Initialize min value  
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
  
// A utility function to print the  
// constructed MST stored in parent[]  
void printMST(int parent[], int graph[V][V])  
{  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}  

// Function to construct and print MST for  
// a graph represented using adjacency  
// matrix representation  
void primMST(int graph[V][V])  
{  
    int weight[V], parent[V];
    bool mst[V];

    for(int i=0; i<V; i++){
      weight[i] = INT_MAX;
      mst[i] = 0;
      parent[i]=i;
    }

    weight[0] = 0;
    parent[0] = -1;
    mst[0] = 1;

    for (int i=0; i< V-1; i++ ) {
      int u=minKey(weight,mst);
      mst[u] = 1;

      for (int v=0; v<V; v++) {
        if (!mst[v] && (graph[u][v]>0) && (weight[v]>graph[u][v])) {
          weight[v]=graph[u][v];
          parent[v] = u;
        }
      }
    }

    printMST(parent, graph);


}

// Driver code 
int main()  
{  
    /* Let us create the following graph  
        2 3  
    (0)--(1)--(2)  
    | / \ |  
    6| 8/ \5 |7  
    | / \ |  
    (3)-------(4)  
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
  
    // Print the solution  
    primMST(graph);  
  
    return 0;  
}  
