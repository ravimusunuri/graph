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
        void bfs(int s);
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
Graph::bfs(int s) {
        bool *visited = new bool[V];
        queue<int> q;
        q.push(s);
        visited[s] = true;
        int v;

        while (!q.empty()) {
                v = q.front();
                q.pop();
                cout << v << " "; 

                for(auto it=adj[v].begin(); it!=adj[v].end(); it++) {
                        if (!visited[*it] ) {
                                visited[*it] = true;
                                q.push(*it);
                        }
                }

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
    g.bfs(2);
  
    return 0;
}
