class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& nums) {

        vector<int>ans,v;
        set<char> s = {'a', 'e', 'i', 'o', 'u'};
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            string str=words[i];
            if(s.find(str[0])!=s.end() && s.find(str[str.size()-1])!=s.end())
            {
               count+=1;
            }
            ans.push_back(count);
        }
        for(auto query:nums)
        {
             int left = query[0];
        int right = query[1];
        int result = ans[right] - (left > 0 ? ans[left - 1] : 0); // Handle range
        v.push_back(result);
            
        }
         
        
        return v;
    }
       
};