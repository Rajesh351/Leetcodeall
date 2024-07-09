class Solution {
public:
    int largestInteger(int num) {
        
        string str=to_string(num);
        for(int i=0;i<str.size();i++)
        {
            bool even=(str[i]-'0')%2==0;
            for(int j=i+1;j<str.size();j++)
            {
                if(even==(str[j]-'0')%2==0)
                {
                    if(str[i]<str[j]) swap(str[i],str[j]);
                }
            }
        }
           return stoi(str);
    }
};