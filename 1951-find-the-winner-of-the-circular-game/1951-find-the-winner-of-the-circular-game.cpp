class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int>q;
        for(int i=1;i<=n;i++) q.push(i);

        while(q.size()>1)
        {
            int j=k;
             while(j>1)
             {
                 q.push(q.front());
                 q.pop();
                 j--;
             }
             q.pop();
        }
        return q.front();
    }
};