class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       if (nums.size() < 2) return 0;
priority_queue<long long , vector<long long>, greater<long long>> pq;
for (int a : nums) {
    pq.push(a);
}

int ans = 0;
while (pq.top() < k && pq.size() > 1) {  // Fixed condition
    long long x = pq.top();
    pq.pop();
    long long y = pq.top();
    pq.pop();
    ans++;
    pq.push(min(x, y) * 2 + max(x, y));
}

    return ans;

    }
};