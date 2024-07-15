#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Large value to represent infinity
const int INF = 1e9 + 7;

// Structure to represent an edge in the graph
struct Edge {
    int to, length;
};

// Function to perform Dijkstra's algorithm
vector<int> dijkstra(int n, const vector<vector<Edge>>& graph, int start) {
    vector<int> distance(n + 1, INF);
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distance[node]) continue;

        for (const auto& edge : graph[node]) {
            int newDist = dist + edge.length;
            if (newDist < distance[edge.to]) {
                distance[edge.to] = newDist;
                pq.push({newDist, edge.to});
            }
        }
    }

    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n + 1);

    // Read edges
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    // Run Dijkstra's algorithm from node 1
    vector<int> shortestRoutes = dijkstra(n, graph, 1);

    // Print the shortest distances to all nodes
    for (int i = 1; i <= n; ++i) {
        if (shortestRoutes[i] == INF) {
            cout << "INF ";
        } else {
            cout << shortestRoutes[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
