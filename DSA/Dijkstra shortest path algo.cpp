#include <iostream>
#include <limits.h>

using namespace std;

#define n 100
#define INF 999999

int graph[n][n];
int Distance[n];
bool visited[n];
int nodes, edges;

void addEdge(int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
}

int findMinNode() {
    int minNode = -1;
    for (int i = 0; i < nodes; i++) {
        if (!visited[i] && (minNode == -1 || Distance[i] < Distance[minNode])) {
            minNode = i;
        }
    }
    return minNode;
}

void dijkstra(int start) {
    for (int i = 0; i < nodes; i++) {
        Distance[i] = INF;
        visited[i] = false;
    }
    Distance[start] = 0;

    for (int i = 0; i < nodes - 1; i++) {
        int u = findMinNode();
        if (u == -1) break;
        visited[u] = true;
        
        for (int v = 0; v < nodes; v++) {
            if (graph[u][v] && !visited[v] && Distance[u] != INF && Distance[u] + graph[u][v] < Distance[v]) {
                Distance[v] = Distance[u] + graph[u][v];
            }
        }
    }
}

int main() {
    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of edges: ";
    cin >> edges;
    
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    
    cout << "Enter edges (from to weight):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    
    int start;
    cout << "Enter starting node for Dijkstra: ";
    cin >> start;
    
    dijkstra(start);
    
    cout << "Shortest distances from node " << start << "\n";
    for (int i = 0; i < nodes; i++) {
        cout << "To " << i << " : ";
        if (Distance[i] == INF) cout << "INF";
        else cout << Distance[i];
        cout << endl;
    }
    
    return 0;
}
