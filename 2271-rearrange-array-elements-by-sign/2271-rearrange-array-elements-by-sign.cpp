class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(auto a:nums)
        {
            if(a>=0) pos.push_back(a);
            else neg.push_back(a);
        }
        vector<int>res;
        for(int i=0;i<pos.size();i++)
        {
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        return res;
    }
};