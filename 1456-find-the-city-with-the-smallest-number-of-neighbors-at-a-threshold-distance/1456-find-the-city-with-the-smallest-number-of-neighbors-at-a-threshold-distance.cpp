class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Initialize the distance matrix
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd-Warshall algorithm to find shortest paths between all pairs of cities
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Find the city with the smallest number of reachable cities within the threshold
    int minReachableCities = INT_MAX;
    int resultCity = -1;
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                ++count;
            }
        }
        if (count < minReachableCities || (count == minReachableCities && i > resultCity)) {
            minReachableCities = count;
            resultCity = i;
        }
    }

    return resultCity;
    }
};