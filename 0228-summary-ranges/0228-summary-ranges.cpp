class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        

          vector<string> str;
    int n = nums.size();
    
    if (n == 0) return str;

    int start = 0; // रेंज की शुरुआत
    
    for (int i = 1; i <= n; i++) {
        if (i == n || nums[i] != nums[i - 1] + 1) { // अगर अगला नंबर कनेक्टेड नहीं है
            if (start == i - 1) {
                str.push_back(to_string(nums[start]));
            } else {
                str.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
            }
            start = i; // नई रेंज शुरू करें
        }
    }
    
    return str;
    }
};