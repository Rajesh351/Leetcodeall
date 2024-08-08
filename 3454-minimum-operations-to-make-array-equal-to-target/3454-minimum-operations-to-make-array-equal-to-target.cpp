class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        
        int pre=0;
        int curr=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            curr=target[i]-nums[i];
            if(curr>0 && pre<0 || curr<0 && pre>0) ans+=abs(curr);
             else if(abs(curr)>abs(pre)) ans+=abs(curr-pre);
            pre=curr;
        }
        return ans;
    }
};