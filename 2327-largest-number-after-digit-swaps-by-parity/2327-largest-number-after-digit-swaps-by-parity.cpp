class Solution {
public:
    int largestInteger(int num) {
        
        vector<int>v;
        while(num>0)
        {
            v.push_back(num%10);
            num=num/10;
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                if((v[i]%2==0 && v[j]%2==0) && v[i]<v[j]) swap(v[i],v[j]);
                if((v[i]%2!=0 && v[j]%2!=0) && v[i]<v[j]) swap(v[i],v[j]);
            }
        }
          reverse(v.begin(),v.end());
        int sum=0;
        for(int i=v.size()-1;i>=0;i--)
        {
           sum=sum*10+v[i];
        }
        return sum;
    }
};