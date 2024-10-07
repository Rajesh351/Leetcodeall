class Solution {
public:
    int minLength(string s) {
        
        int i=0;
        while( !s.empty() &&i<s.size()-1){ 
            if (s[i] == 'A' && s[i + 1] == 'B') {
                s.erase(i, 2);
                if (i > 0) i--;  
            } 
            else if (s[i] == 'C' && s[i + 1] == 'D') {
                s.erase(i, 2);  
                if (i > 0) i--; 
            } 
            else {
                i++;  
            }
        }
        return s.size();
    }
};