class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        set<int>s;
        for(int i=0;i<allowed.size();i++)
        {
            s.insert(allowed[i]);
        }
       int count=0;
        for(int i=0;i<words.size();i++)
        {
            string str=words[i];
            int a=0;
            for(int j=0;j<words[i].size();j++)
            {

                if(s.find(str[j])==s.end()) a=1;
            }
            if(a==0) count++;
        }
        return count;
        
    }
};