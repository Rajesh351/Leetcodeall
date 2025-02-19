class Solution {
public:
    vector<string> ans;
    string res = "";

    void solve(string s, int n, int k) {
        if (s.size() == n) {
            ans.push_back(s);
            if (ans.size() == k)
                res = s;
            return;
        }
        if (!res.empty())
            return; 

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (s.empty() || s.back() != ch) {
                solve(s + ch, n, k);
            }
        }
    }
    string getHappyString(int n, int k) {
        string str = "";
        solve(str, n, k);
        return res;
    }
};