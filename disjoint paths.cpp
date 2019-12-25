// C++ program for implementation of Ford Fulkerson algorithm 
#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
using namespace std; 
  
// Number of vertices in given graph 
#define V 8
  
bool
bfs(int rgraph[V][V], int parent[V], int s, int t) {
  bool visited[V] = {false};
  queue<int> q;
  q.push(s);
  parent[s] = -1;
  visited[s] = true;
  while(!q.empty()) {
    int u = q.front();
    q.pop(); 

    for(int v=0; v<V; v++) {
      if ((rgraph[u][v] > 0) && !visited[v]) {
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }
  return (visited[t]);
}
  
// Returns the maximum flow from s to t in the given graph 
int findDisjointPaths(int graph[V][V], int s, int t) 
{ 
  // create residual graph
  int rgraph[V][V];

  for(int i=0;i < V; i++)
    for(int j=0; j< V; j++)
      rgraph[i][j] = graph[i][j];

  int parent[V] = {-1};
  int max_flow = 0;

  while(bfs(rgraph, parent, s, t)) {
    int path_flow = INT_MAX;

    int u, v;
    // path flow
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      path_flow = min(path_flow, rgraph[u][v]);
    }
    // update residual graph
    for(int v= t; v !=s; v = parent[v]) {
      u = parent[v];
      rgraph[u][v] -= path_flow;
      rgraph[v][u] += path_flow;
    }
    
    max_flow += path_flow;
    // update max_flow
  }

  return max_flow;
}

// Driver program to test above functions 
int main() 
{ 
    // Let us create a graph shown in the above example 
    int graph[V][V] = { {0, 1, 1, 1, 0, 0, 0, 0}, 
                        {0, 0, 1, 0, 0, 0, 0, 0}, 
                        {0, 0, 0, 1, 0, 0, 1, 0}, 
                        {0, 0, 0, 0, 0, 0, 1, 0}, 
                        {0, 0, 1, 0, 0, 0, 0, 1}, 
                        {0, 1, 0, 0, 0, 0, 0, 1}, 
                        {0, 0, 0, 0, 0, 1, 0, 1}, 
                        {0, 0, 0, 0, 0, 0, 0, 0} 
                      }; 
  
    int s = 0; 
    int t = 7; 
    cout << "There can be maximum " << findDisjointPaths(graph, s, t) 
         << " edge-disjoint paths from " << s <<" to "<< t ; 
  
    return 0; 
}  
