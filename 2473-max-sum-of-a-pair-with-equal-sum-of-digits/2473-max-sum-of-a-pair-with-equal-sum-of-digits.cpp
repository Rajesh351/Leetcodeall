class Solution {
public:
    int maximumSum(vector<int>& nums) {

       vector<pair<int,int>>digitsum;
       for(int i=0;i<nums.size();i++)
       {
            int curr=nums[i];
            int sum=0;
            while(curr>0)
            {
              sum+=curr%10;
              curr=curr/10;
            }
            digitsum.push_back({sum,nums[i]});
       }
       sort(digitsum.begin(),digitsum.end());
       int ans=INT_MIN;
       int i=1;
       while(i<digitsum.size())
       {
           if(digitsum[i-1].first==digitsum[i].first)
           {
              ans=max(ans,digitsum[i-1].second+digitsum[i].second);
             
           }
            i++;
           
       } 
       return ans==INT_MIN?-1:ans;
    }
};