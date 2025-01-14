class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        unordered_map<int, int> mp;
        vector<int> v;

        for (int i = 0; i < A.size(); i++) {
            int count = 0;

            if (mp.find(A[i]) != mp.end()) {
                count++;
            } else
                mp[A[i]]++;
            if (mp.find(B[i]) != mp.end()) {
                count++;
            } else
                mp[B[i]]++;
            if (v.empty())
                v.push_back(count);
            else {
                v.push_back(v[i - 1] + count);
            }
        }
        return v;
    }
};