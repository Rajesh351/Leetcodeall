class Solution {
public:
    string slove(string a ,string b)
     {
         int len=min(a.size(),b.size());
         string str="";
         for(int i=0;i<len;i++)
         {
             if(a[i]!=b[i]) break;
             else
             {
                 str+=a[i];
             }
         }
         return str;
     }
    string longestCommonPrefix1(vector<string> arr) {
      
       string prefix=arr[0];
       for(int i=1;i<arr.size();i++)
       {
           prefix=slove(arr[i],prefix);
       }
       return prefix;
    }
    string longestCommonPrefix(vector<string>& strs) {
        return longestCommonPrefix1(strs);
    }
};