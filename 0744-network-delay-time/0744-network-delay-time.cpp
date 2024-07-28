class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector<pair<int, int>>> g(n + 1); // Use n+1 to include all nodes from 1 to n
    for (int i = 0; i < times.size(); i++) {
        g[times[i][0]].push_back({times[i][1], times[i][2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(n + 1, INT_MAX);
    distTo[k] = 0;
    pq.push(make_pair(0, k));

    while (!pq.empty()) {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        for (auto it = g[prev].begin(); it != g[prev].end(); it++) {
            int next = it->first;
            int nextDist = it->second;
            if (distTo[next] > distTo[prev] + nextDist) {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (distTo[i] == INT_MAX) return -1;
        ans = max(ans, distTo[i]); // Use max instead of min to get the longest shortest path
    }

    return ans;
    }
};