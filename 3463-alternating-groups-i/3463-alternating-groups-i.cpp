class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {

     int count=0;
     for(int i=1;i<colors.size()-1;i++)
     {
        if(colors[i-1]!=colors[i] && colors[i]!=colors[i+1]) count++;
     }   
     int n=colors.size()-1;
      if(colors[n-1]!=colors[n] && colors[n]!=colors[0]) count++;
      if(colors[n]!=colors[0] && colors[0]!=colors[1]) count++;
      return count;
    }
};