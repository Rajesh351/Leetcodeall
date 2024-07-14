class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        


        vector<pair<int,int>>v;
        for(int i=0;i<positions.size();i++)
        {
            v.push_back({positions[i],i});
        }
        sort(v.begin(),v.end());
        stack<int>st;
        for(auto it:v)
        {
            if(directions[it.second]=='R') st.push(it.second);
            else
            {
                while(st.size()>0 && healths[it.second]>0)
                {
                    if(healths[it.second]>healths[st.top()])
                    {
                              healths[st.top()]=0;
                               st.pop();
                                healths[it.second]--;
                    }
                    else if(healths[it.second]<healths[st.top()])
                    {
                            healths[st.top()]--;
                                healths[it.second]=0;
                    }
                    else
                    {   healths[st.top()]=0;
                         st.pop();
                         healths[it.second]=0;
                    }
                }
            }
        }
        vector<int>ans;
        for(auto it:healths)
        {
            if(it!=0) ans.push_back(it);
        }
        return ans;
    }
};