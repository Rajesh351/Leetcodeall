class Solution {
public:
    int longestSubarray(vector<int>& arr) {


        int maxval=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            maxval=max(arr[i],maxval);
        }
        int ans=INT_MIN;
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==maxval)
            {
               count++;
            }
            else
            {
              ans=max(ans,count);
              count=0;
            }

        }
        ans=max(ans,count);
        return ans;
    }
};