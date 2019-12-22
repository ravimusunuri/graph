#include <iostream> 
#include <list> 
#include <iterator>
#include<vector>
#include<queue>

using namespace std; 
class Graph
{ 
        int V;    
        list<int> *adj;
public: 
        Graph(int V);  
        void addEdge(int v, int w);  
        void dfs(int s);
        void dfs_util(int s, bool visited[]);
}; 

Graph::Graph(int V) {
        this->V = V;
        this->adj  = new list<int>[V];
}

void
Graph::addEdge(int u, int v) {
        adj[u].push_back(v);
}       

void 
Graph::dfs_util(int s, bool visited[]) {
    visited[s] = true;
    cout << s << " ";
    for(auto it=adj[s].begin(); it != adj[s].end(); it++) {
        if (!visited[*it])
            dfs_util(*it, visited);
    }
    
}

void
Graph::dfs(int s) {
        bool *visited = new bool[V];
        
        for (int i=0; i<V; i++) {
            if (!visited[i])
                dfs_util(s, visited);
        }
}


// Driver program to test methods of graph class
int main()
{ 
    // Create a graph given in the above diagram 
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2);
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.dfs(2);
  
    return 0;
}
