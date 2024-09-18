class Solution {
public:
    // bool compare(string& a, string& b) { return a + b > b + a; }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            str.push_back(s);
        }
        sort(str.begin(), str.end(), [](string &a, string &b) {
        return a + b > b + a;  // Compare concatenated strings
    });
        string ans = "";
        for (int i = 0; i < str.size(); i++) {
            ans += str[i];
        }
        if(ans[0]=='0') ans='0';
        return ans;
    }
};