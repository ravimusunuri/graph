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
        bool dfs_util(int s, bool visited[], bool rec[]);
}; 

Graph::Graph(int V) {
        this->V = V;
        this->adj  = new list<int>[V];
}

void
Graph::addEdge(int u, int v) {
        adj[u].push_back(v);
}       

bool 
Graph::dfs_util(int s, bool visited[], bool rec[]) {
    visited[s] = true;
    rec[s] = true;
    cout << s << " ";
    for(auto it=adj[s].begin(); it != adj[s].end(); it++) {
        if ((!visited[*it]) && dfs_util(*it, visited, rec))
                return true;
        else if(rec[*it])
            return true;
    }
    rec[s] = false;
    return false;
}

bool
Graph::dfs() {
        bool *visited = new bool[V];
        bool *rec = new bool[V];
        
        for (int i=0; i<V; i++) {
            if (!visited[i])
                if (dfs_util(i, visited, rec))
                    return true;
        }
        return false;
}


// Driver program to test methods of graph class
int main()
{ 
    // Create a graph given in the above diagram 
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2);
    //g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    //g.addEdge(3, 3);
  
    cout << "is cycle " << g.dfs(); 
  
    return 0;
}
