class Solution {
public:
       long long minimumSteps(string s) {
        
        int i=0;
        int j=s.size()-1;
        long long ans=0;
        while(i<j)
        {
            if(s[i]=='0' && s[j]=='1') 
            {
                i++;
                j--;
            }
            else if(s[i]=='0') i++;
            else if(s[j]=='1') j--;
            else
            {
                ans+=j-i;
                i++;
                j--;
            }
        }
        return ans;
    
      
    }
};