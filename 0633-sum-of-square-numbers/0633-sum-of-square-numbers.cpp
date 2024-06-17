class Solution {
public: 
    bool raj(int x)
    {
        int root=sqrt(x);
        if(root*root==x) return true;
        else return false;
    }
    bool judgeSquareSum(int c) {
        
     int x=0;
     int y=c;
     while(x<=y)
     {
         if(raj(x) && raj(y))
         {
             return true;
         }
         else if(!raj(y))
         {
             y=(int)sqrt(y) *( int) sqrt(y);
             x=c-y;
         }
         else
         {
             x=((int)sqrt(x)+1)*((int)sqrt(x)+1);
             y=c-x;
         }
     }
     return false;
    }
};