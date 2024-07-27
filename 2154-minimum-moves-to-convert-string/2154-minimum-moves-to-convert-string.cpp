class Solution {
public:
    int minimumMoves(string s) {
        int count=0;
        for (int i = 0; i < s.size() - 2; i++) {
           
           bool check=false;
           if(s[i]=='O' && i<s.size()-3) continue;
           for(int j=i;j<3+i;j++)
           {
             if(s[j]=='X')
             {
                s[j]='O';
                check=true;
             }
           }
           if(check) count++;
        }
        return count;
    }
};