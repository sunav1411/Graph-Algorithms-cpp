#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming an undirected graph
    }

    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    
    cout << "DFS Traversal starting from node 0: ";
    g.DFS(0);

    return 0;
}
