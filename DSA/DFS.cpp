#include <iostream>

using namespace std;

#define MAX 100

int adj[MAX][MAX]; 
bool visited[MAX]; 
int V, E;

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; 
}

void DFS(int node) {
    cout << node << " ";
    visited[node] = true;
    
    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    
    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
        for (int j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
    }
    
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    
    int start;
    cout << "Enter starting node for DFS: ";
    cin >> start;
    
    cout << "DFS traversal starting from node " << start << ": ";
    DFS(start);
    
    return 0;
}

