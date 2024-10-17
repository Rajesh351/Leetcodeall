class Solution {
public:
    int maximumSwap(int num) {

      vector<int>v;
      int a=num;
      while(a>0)
      {
        v.push_back(a%10);
        a=a/10;
      }  
      reverse(v.begin(),v.end());

      for(int i=0;i<v.size()-1;i++)
      {
        if(v[i]==9) continue;
        int index=0;
        int maxele=INT_MIN;
        for(int j=v.size()-1;j>i;j--)
        {
            if(v[i]<v[j] && maxele<v[j])
            {
               maxele=v[j];
               index=j;
            }
        }
        if(index!=0)
        {
            v[index]=v[i];
           v[i]=maxele;
           break; 
        }
      }
      int ans=0;
      for(int i=0;i<v.size();i++)
      {
        ans=ans*10+v[i];
      }
      return ans;
    }
};