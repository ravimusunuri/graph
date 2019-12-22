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
        bool dfs();
        bool dfs_util(int s, bool visited[], int parent);
}; 

Graph::Graph(int V) {
        this->V = V;
        this->adj  = new list<int>[V];
}

void
Graph::addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
}       

bool 
Graph::dfs_util(int s, bool visited[], int parent) {
    visited[s] = true;
    for(auto it=adj[s].begin(); it != adj[s].end(); it++) {
        if (!visited[*it]) {
            if (dfs_util(*it, visited, s)) {
                return true;
            }
        } else if(*it != parent) {
            return true;
        }
    }
    return false;
}

bool
Graph::dfs() {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++) 
            visited[i] = false; 
        
        for (int i=0; i<V; i++) {
            if (!visited[i])
                if (dfs_util(i, visited, -1))
                    return true;
        }
        return false;
}


// Driver program to test methods of graph class
int main()
{ 
    
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.dfs()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    Graph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.dfs()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    return 0; 
    
}
