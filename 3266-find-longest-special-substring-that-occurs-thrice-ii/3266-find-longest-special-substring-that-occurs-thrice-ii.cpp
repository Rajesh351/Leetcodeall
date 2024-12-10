class Solution {
public:
    int maximumLength(string s) {
            int n=s.size();
        vector<vector<int>>matrix(26,vector<int>(n+1,0));
        char pre=s[0];
        int len=0;
        for(int i=0;i<n;i++)
        {
            char curr=s[i];
            if(curr==pre)
            {
                len++;
                matrix[curr-'a'][len]+=1;
            }
            else
            {
                len=1;
                matrix[curr-'a'][len]+=1;
                pre=s[i];
            }
        }
        int res=0;
        for(int i=0;i<26;i++)
        {
            int sum=0;
            for(int j=n;j>=1;j--)
            {
                sum+=matrix[i][j];
                if(sum>=3)
                {
                    res=max(res,j);
                    break;
                }
            }
        }
        return res==0?-1:res;
    }
};