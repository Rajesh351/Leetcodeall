class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        

       int count=0;
        for(int i=low;i<=high;i++)
        {
            string str=to_string(i);
            if(str.size()%2==0)
            {
                int n=str.size();
                int first=n/2;
                int sum=0;
                for(int j=0;j<first;j++) 
                {
                    sum+=str[j]-'0';
                }
                int sum1=0;
                for(int j=first;j<n;j++)
                {
                     sum1+=str[j]-'0';
                }
                if(sum==sum1) count++;
            }
        }
        return count;
    }
};