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

void BFS(int start) {
    int front = 0, rear = 0;
    int q[MAX];  
    q[rear++] = start; 
    visited[start] = true;
    
    while (front < rear) {
        int node = q[front++];  
        cout << node << " ";
        
        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q[rear++] = i;  
            }
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
    cout << "Enter starting node for BFS: ";
    cin >> start;
    
    cout << "BFS traversal starting from node " << start << ": ";
    BFS(start);
    
    return 0;
}
