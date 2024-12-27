class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {


        int maxval=arr[0];
        int ans=0;
        for(int j=1;j<arr.size();j++)
        {
            ans=max(ans,arr[j] +maxval-j);
            maxval=max(maxval,arr[j]+j);
        }
        return ans;
    }

};