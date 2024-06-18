class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        //create a max heap to store (profit,difficulty)
        priority_queue<pair<int,int>>pq;
        int i;
        for(i=0;i<difficulty.size();i++){
            pq.push({profit[i],difficulty[i]});}
        //sort the worker array in descending order
        sort(worker.begin(),worker.end(),greater<>());
        i=0;
        int total_profit=0;
            while(!pq.empty() && i<worker.size()){
                if(pq.top().second<=worker[i]){
                    total_profit+=pq.top().first;
                    i++;}
                else{
                    pq.pop(); //pop the element only if the difficulty is greater than worker[i]
                }
            }
                    return total_profit;}};