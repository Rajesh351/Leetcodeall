class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        auto Compare = [&](pair<int,int>& a, pair<int,int>& b) { 
            return nums[a.first][a.second]>nums[b.first][b.second];
         };
        priority_queue< pair<int,int> , vector< pair <int , int> > ,  decltype(Compare)> pq(Compare);
        int big = -1e7;
        for(int i=0;i< k;i++){
            pq.push({i,0});
            big=max(big, nums[i][0]);
        }
        vector<int> ans(2);
        // cout<<pq.top().first <<" : "<< pq.top().second << " ; "<<endl;
        ans[0]=nums[pq.top().first][pq.top().second];
        // cout<<ans[0]<<" ;"<<big <<endl;
        ans[1]=big;
        while(!pq.empty()){
            pair<int,int> temp= pq.top();
            // cout<<"Ans :"<<ans[0] <<" : "<< ans[1] << " ; "<<endl;
            // cout<<"Min :"<<pq.top().first <<" : "<< pq.top().second << " ; "<<endl;
            
            pq.pop();
            int small=nums[temp.first][temp.second];
            if(big-small<ans[1]-ans[0]){
                ans[1]=big;
                ans[0]=small;
            }
            if(temp.second+1>=nums[temp.first].size()){break;}
            pq.push({temp.first,temp.second+1});
            big=max(big,nums[temp.first][temp.second+1]);
        }
        return ans;
    }
};