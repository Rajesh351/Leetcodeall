class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int count=0;
        string onemove="../";
        string same="./";

        for(auto a:logs)
        {
            if(onemove==a && count==0) continue;
            else if(onemove==a) count-=1;
            else if(same!=a) count+=1;
        }
        return count==0?0:count;
    }
};