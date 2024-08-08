class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
         int pre=0;
        int curr=0;
        int ans=0;
        for(int i=0;i<target.size();i++)
        {
            curr=target[i];
            if(curr>0 && pre<0) ans+=abs(curr);
             else if(abs(curr)>abs(pre)) ans+=abs(curr-pre);
            pre=curr;
        }
        return ans;
    }
};