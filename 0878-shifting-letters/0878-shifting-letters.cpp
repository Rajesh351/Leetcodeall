class Solution {
public:
    string shiftingLetters(string s, vector<int>& arr) {
        vector<long long > v;
        long long  count = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            count += arr[i];
            v.push_back(count);
        }
         reverse(v.begin(),v.end());
        string str;
        for (int i = 0; i < s.size(); i++) {
            int val = int(s[i] - 'a'); 
              
            if (val + v[i] > 25) {
                long long rem = (val + v[i]) % 26; 
                str.push_back('a' + rem);
            } else {
                str.push_back('a' + val + v[i]); 
            }
        }

        return str;
    }
};