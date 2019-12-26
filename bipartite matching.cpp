// A C++ program to find maximal 
// Bipartite matching. 
#include <iostream> 
#include <string.h> 
using namespace std; 
  
// M is number of applicants  
// and N is number of jobs 
#define M 6 
#define N 6 
  
bool 
bpm(bool bgGraph[M][N], int u, int match[], bool visited[]){

  for(int v=0; v<N; v++) {
    if (bgGraph[u][v] && !visited[v]) {
      visited[v] = true;
      if ((match[v] < 0) ||  (bpm(bgGraph, match[v], match, visited))) {
        //cout << u << "-" << v << endl;
        match[v] = u;
        return true;
      }
    }
  }
  return false;
}

// Returns maximum number 
// of matching from M to N 
int maxBPM(bool bpGraph[M][N]) 
{ 
  int match[N] = {-1};
  memset(match, -1, sizeof(match));

  int match_count = 0;

  for (int i=0; i<M; i++) {
    bool visited[N] = {false};
    memset(visited, 0, sizeof(visited));

    if (bpm(bpGraph, i, match, visited)) {
      match_count++;
    }
  }

  return match_count;
} 
  
// Driver Code 
int main() 
{ 
    // Let us create a bpGraph  
    // shown in the above example 
    bool bpGraph[M][N] = {{0, 1, 1, 0, 0, 0}, 
                          {1, 0, 0, 1, 0, 0}, 
                          {0, 0, 1, 0, 0, 0}, 
                          {0, 0, 1, 1, 0, 0}, 
                          {0, 0, 0, 0, 0, 0}, 
                          {0, 0, 0, 0, 0, 1}}; 
  
    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph); 
  
    return 0; 
} 
