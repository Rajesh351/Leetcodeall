class Solution {
public:
    void reverseString(vector<char>& s) {

       int n=s.size()-1;
       int j=0;
       while(j<n)
       {
           swap(s[j],s[n]);
           j++;
           n--;
       } 
    }
};