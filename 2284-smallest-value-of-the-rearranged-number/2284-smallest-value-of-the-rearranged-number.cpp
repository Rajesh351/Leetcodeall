class Solution {
public:
    long long smallestNumber(long long num) {
        
      if(num==0) return 0;
      if(num<0)
      {
         vector<int>v;
         num=abs(num);
         while(num>0)
         {
            v.push_back(num%10);
            num=num/10;
         }
         sort(v.begin(),v.end());
         long long ans=0;
         for(int i=v.size()-1;i>=0;i--)
         {
            ans=ans*10+v[i];
         }
         return -ans;
      }
      else
      {
          vector<int>v;
         num=abs(num);
         int count=0;
         while(num>0)
         {
            if(num%10==0) count++;
            else
            v.push_back(num%10);
            num=num/10;
         }
         sort(v.begin(),v.end());
         long long ans=0;
         for(int i=0;i<v.size();i++)
         {
            ans=ans*10+v[i];
            while(count>0)
            {
              ans=ans*10;
              count--;
            }
         }  
         return ans;
      }
     
    }
};