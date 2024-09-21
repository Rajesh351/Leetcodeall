class Solution {
public:
    void slove(int i,int n,vector<int>&v)
    {
        if(i>n) return;
        v.push_back(i);
        for(int j=0;j<=9;j++)
        {
            int num=(i*10)+j;
            if(num>n) return;
            slove(num,n,v);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        vector<int>v;
        for(int i=1;i<=9;i++)
        {
            slove(i,n,v);
        }
        return v;
    }
};