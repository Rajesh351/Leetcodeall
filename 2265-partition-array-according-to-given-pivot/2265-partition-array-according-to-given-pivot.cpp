class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       vector<int>small,big;
       int count=0;
       for(auto a:nums)
       {
         if(pivot>a) small.push_back(a);
         else if(pivot==a) count++;
         else big.push_back(a);
       }
        vector<int>ans;
        for(int i=0;i<small.size();i++) ans.push_back(small[i]);
        for(int i=0;i<count;i++) ans.push_back(pivot);
        for(int j=0;j<big.size();j++) ans.push_back(big[j]);
        return ans;

    }
};