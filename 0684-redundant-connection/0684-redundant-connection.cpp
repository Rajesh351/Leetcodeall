class Solution {
public:
 
bool bfs(unordered_map<int, vector<int>>& adj, vector<bool>& vis, int source) {
    queue<pair<int, int>> pq;
    pq.push({source, -1});
    vis[source] = true;

    while (!pq.empty()) {
        auto it = pq.front();
        pq.pop();
        int node = it.first;
        int parent = it.second;

        for (auto b : adj[node]) {
            if (!vis[b]) {
                pq.push({b, node});
                vis[b] = true;
            } 
            else if (b != parent) {
                return true;  // Cycle detected
            }
        }
    }
    return false;  // No cycle
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> adj;
    int n = edges.size();  // Total number of edges
    vector<bool> vis(n + 1, false);  // To mark visited nodes, assuming nodes are 1-indexed

    for (auto& it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);

        fill(vis.begin(), vis.end(), false);  // Reset vis array for each edge check
        if (bfs(adj, vis, it[0])) {
            return {it[0], it[1]};  // Return the redundant edge when a cycle is found
        }
    }

    return {0, 0};  // In case no cycle is found (should not reach here if input is valid)
}
};