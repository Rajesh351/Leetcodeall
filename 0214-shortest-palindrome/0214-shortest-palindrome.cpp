class Solution {
public:
    string shortestPalindrome(string s) {
        
        string rev=s;
        reverse(rev.begin(),rev.end());
        int n=s.size();
       // if(s==rev) return s;
        for(int i=0;i<s.size();i++)
        {
            if(!memcmp(s.c_str(),rev.c_str()+i,n-i)) return rev.substr(0,i)+s;
        }
        return rev+s;
    }
};