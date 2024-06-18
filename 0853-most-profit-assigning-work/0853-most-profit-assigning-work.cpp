class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
          int n = difficulty.size();
    
    vector<pair<int, int>> jobs(n);
    for (int i = 0; i < n; i++) {
        jobs[i] = make_pair(difficulty[i], profit[i]);
    }
    
    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());
    
    int totalProfit = 0;
    int maxProfit = 0;
    int j = 0;
    
    for (int ability : worker) {
        while (j < n && jobs[j].first <= ability) {
            maxProfit = max(maxProfit, jobs[j].second);
            j++;
        }
        totalProfit += maxProfit;
    }
    
    return totalProfit;
    }
};