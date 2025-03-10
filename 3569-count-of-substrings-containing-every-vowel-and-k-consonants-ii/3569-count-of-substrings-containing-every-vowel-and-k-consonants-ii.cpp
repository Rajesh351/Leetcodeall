class Solution {
public:
    long long solve(string &word, int k){
        int l = 0, r = 0, cnt = 0;
        long long ans = 0;
        unordered_map<char, int> mp;
        while(r < word.length()){
            if(word[r] == 'a' || word[r] == 'e' || word[r] == 'i' || word[r] == 'o' || word[r] == 'u') mp[word[r]]++;
            else cnt++;
            while(cnt >= k && mp.size() == 5){
                ans += word.length() - r;
                if(word[l] == 'a' || word[l] == 'e' || word[l] == 'i' || word[l] == 'o' || word[l] == 'u'){
                    mp[word[l]]--;
                    if(mp[word[l]] == 0) mp.erase(word[l]);
                }
                else cnt--;
                l++;
            }

            r++;
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return solve(word, k) - solve(word, k + 1);
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();