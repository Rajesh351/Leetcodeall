class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
         vector<int> one, zero;
    int onecount = 0;
    int zerocount = 0;

    // Reverse cumulative counts
    for (int i = nums.size() - 1; i >= 0; i--)
    {

        if (nums[i] == 1)
            onecount++;
        one.push_back(onecount);
    }
    reverse(one.begin(), one.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            zerocount++;
        zero.push_back(zerocount);
    }

   int maxval = 0;
    vector<pair<int, int>> v;

    // Calculate scores and find max score
    for (int i = 0; i <= nums.size(); i++) {
        int leftscore = i > 0 ? zero[i - 1] : 0;
        int rightscore = i < nums.size() ? one[i] : 0;
        int score = leftscore + rightscore;
        v.push_back({i, score});
        maxval = max(maxval, score);
    }

    vector<int> ans;

    // Collect indices with max score
    for (int i = 0; i < v.size(); i++) {
        //cout<<v[i].second<<endl;
        if (v[i].second == maxval) {
            ans.push_back(v[i].first);
        }
    }

    return ans;
}
};