class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int a:nums)
        {
            mp[a]++;
        }
        int count=0;
        for(auto it:mp)
        {
            if(it.second==1) return false;
            if(it.second%2!=0) return false;
            count+=it.second/2;
        }
        return n/2==count;
    }
};