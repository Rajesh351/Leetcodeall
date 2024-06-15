class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
           vector<pair<int, int>> projects;
    for (int i = 0; i < Profits.size(); i++) {
        projects.push_back({Capital[i], Profits[i]});
    }
    sort(projects.begin(), projects.end());

    priority_queue<int> pq; // max heap
    int idx = 0;

    for (int i = 0; i < k; i++) {
        while (idx < projects.size() && projects[idx].first <= W) {
            pq.push(projects[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            W += pq.top();
            pq.pop();
        } else {
            break;
        }
    }

    return W; 
    }
};