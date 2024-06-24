class Solution {
public:
    bool checkPerfectNumber(int num) {
       
      int sum=0;
      for(int i=1;i<sqrt(num);i++)
      {
        if(num%i==0) 
          sum+=i;
      }
      for(int j=1;j<=sqrt(num);j++)
      {
        if(num%j==0 && num/j!=num) sum= sum+num/j;
      }

      if(sum==num) return true;
      return false;
    }
};