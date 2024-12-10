class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int>mp;
        for(int i=0;i<s.size();i++)
        {
            string curr="";
            for(int j=i;j<s.size();j++)
            {
                if(curr.empty() || curr.back()==s[j])
                {
                    curr.push_back(s[j]);
                    mp[curr]+=1;
                }
                else break;
            }
        }
        int ans=INT_MIN;
        for(auto it:mp)
        {
            string str=it.first;
            int n=str.size();
             if(it.second>2) ans=max(ans,n);
        }
        return ans==INT_MIN?-1:ans;
    }
};