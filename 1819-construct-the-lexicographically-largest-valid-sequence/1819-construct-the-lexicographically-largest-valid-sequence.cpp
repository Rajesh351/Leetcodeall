class Solution {
public:
     bool solve(vector<int>&ans,vector<bool>&vis,int n,int idx)
     {
        if(idx>=ans.size()) return true;
        if(ans[idx]!=-1)
        {
            return solve(ans,vis,n,idx+1);
        }
         for(int i=n;i>=1;i--)
         {
            if(vis[i]==true) continue;
            vis[i]=true;
            ans[idx]=i;
            if(i==1)
            {
                if(solve(ans,vis,n,idx+1)==true) return true;
            }
            else
            {
                int j=ans[idx]+idx;
                if(j<ans.size() && ans[j]==-1)
                {
                    ans[j]=i;
                    if(solve(ans,vis,n,idx+1)==true) return true;
                    ans[j]=-1;
                }

            }
             vis[i]=false;
            ans[idx]=-1;
         }
         return false;
     }
    vector<int> constructDistancedSequence(int n) {
        vector<int>ans(2*n-1,-1);
        vector<bool>vis(n+1,false);
        solve(ans,vis,n,0);
        return ans;
    }
};