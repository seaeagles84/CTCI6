#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    private:
        vector<vector <int>> edges;
    public:
        Graph(int n) {
            edges.resize(n);
        }
    
        void add_edge(int u, int v) {
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            queue<int> node_queue;
            vector<int> distance(edges.size(),-1);
            distance[start] = 0;
            
            node_queue.push(start);
            
            while (!node_queue.empty()) {
                int current = node_queue.front();
                node_queue.pop();
                for (int i = 0; i < edges[current].size(); i++) {
                    if (distance[edges[current][i]] == -1) { // if not already visited! 
                        distance[edges[current][i]] = distance[current] + 6;
                        node_queue.push(edges[current][i]);
                    }
                }
            }
            
            return distance;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
