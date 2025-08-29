class Solution {
public:
    long long flowerGame(int n, int m) {
        
     if(n%2==0)
     {
        long long num=n/2;
        return num*m;
     }
     else if(m%2==0)
     {
        
      long long num=m/2;
        return num*n;
     }
      return (n*m)/2;

    }
};