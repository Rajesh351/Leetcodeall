class Solution {
public:
    int upperBound(vector<vector<int>>& events,int i,int n){
        int l=i+1,h=n-1;
        while(l<=h){
            int mid=l+((h-l)/2);
            if(events[mid][0]>events[i][1]){
                n=mid;
                h=mid-1;
            }else l=mid+1;
        }
        return n;
    }
    int solve(vector<vector<int>>& events,int i,int k,int n,vector<vector<int>>& dp){
        if(k==2||i>=n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int next=upperBound(events,i,n);
        int inc=events[i][2]+solve(events,next,k+1,n,dp);
        int exc=solve(events,i+1,k,n,dp);
        return dp[i][k]=max(inc,exc);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(events,0,0,n,dp);
    }
};