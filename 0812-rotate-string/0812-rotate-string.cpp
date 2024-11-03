class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        if(s==goal) return true;
        for(int i=0;i<goal.size();i++)
        {
            string newstr = goal.substr(i, goal.size() - i) + goal.substr(0, i);
             if(newstr==s) return true;
        }
        return false;
    }
};