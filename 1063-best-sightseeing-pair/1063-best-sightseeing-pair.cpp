class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {


      vector<int>v;
      int maxval=0;
      for(int i=0;i<arr.size();i++)
      {
         maxval=max(arr[i]+i,maxval);
         v.push_back(maxval);
      }
       int ans=0;
       for(int i=1;i<arr.size();i++)
       {
          ans=max(ans,v[i-1]+arr[i]-i);
       }
       return ans;
    }

};