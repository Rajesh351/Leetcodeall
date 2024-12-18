class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
      vector<int>ans;
       bool check;
       for(int i=0;i<prices.size();i++)
       {
             check=false;
           for(int j=i;j<prices.size();j++)
           {
              if(j>i && prices[j]<=prices[i])
              {
                 ans.push_back(abs(prices[j]-prices[i]));
                 check=true;
                 break;
               
              }
           }
           if(check==false) ans.push_back(prices[i]);
       }
       // if(check==false)  ans.push_back(prices[prices.size()-1]);
       return ans;
    }
};