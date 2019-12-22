// A union-find algorithm to detect cycle in a graph  
#include <bits/stdc++.h> 
using namespace std; 
  
// a structure to represent an edge in graph  
class Edge  
{  
    public: 
    int src, dest;  
};  
  
// a structure to represent a graph  
class Graph  
{  
    public: 
    // V-> Number of vertices, E-> Number of edges  
    int V, E;  
  
    // graph is represented as an array of edges  
    Edge* edge;  
};  

struct subset {
  int parent;
  int rank;
};
  
// Creates a graph with V vertices and E edges  
Graph* createGraph(int V, int E)  
{  
    Graph* graph = new Graph(); 
    graph->V = V;  
    graph->E = E;  
  
    graph->edge = new Edge[graph->E * sizeof(Edge)];  
  
    return graph;  
}  
  
int
find(subset s[], int x) {

  while (s[x].parent != x) {
    s[x].parent =s[s[x].parent].parent;
    x = s[x].parent;
  }
  //cout << "find parent of " << a << " is "<< x << endl;
  return x;
}
  
void
Union(subset s[], int x, int y){
  int a = find(s, x);
  int b = find(s, y);

  if (a != b) {
    if (s[a].rank < s[b].rank) {
      s[a].parent = b;
    } else if  (s[a].rank > s[b].rank) {
      s[b].parent = a;
    } else {
      s[a].parent = b;
      s[b].rank++;
      cout << "union of " << a << "  "<< b << endl;
    }
  }
}
// The main function to check whether a given graph contains  
// cycle or not  
int isCycle( Graph* gr)  
{  
  subset *s = new subset[gr->V];

  for(int i=0; i<gr->V;i++) {
    s[i].parent = i;
    s[i].rank = 0;
  }

  for(int i=0; i<gr->E; i++) {
     cout << "edge " <<  gr->edge[i].src << "  "<<  gr->edge[i].dest << endl;
    int u = find(s, gr->edge[i].src);
    int v = find(s, gr->edge[i].dest);

    if (u != v) {
      Union(s, gr->edge[i].src, gr->edge[i].dest);
    } else {
      return true;
    }
  }
  return false;
}  
  
// Driver code 
int main()  
{  
    /* Let us create the following graph  
        0  
        | \  
        | \  
        1-----2 */
    int V = 3, E = 2;  
    Graph* graph = createGraph(V, E);  
  
    // add edge 0-1  
    graph->edge[0].src = 0;  
    graph->edge[0].dest = 1;  
  
    // add edge 1-2  
    graph->edge[1].src = 1;  
    graph->edge[1].dest = 2;  
  
    // add edge 0-2  
    //graph->edge[2].src = 0;  
    //graph->edge[2].dest = 2;  
  
    if (isCycle(graph))  
        cout<<"graph contains cycle";  
    else
        cout<<"graph doesn't contain cycle";  
  
    return 0;  
}  
  
