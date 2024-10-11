class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        

        int ans=times[targetFriend][0];
        int n=times.size();
        vector<int>v(n,-1);
        sort(begin(times),end(times));

        for(vector<int>&vec:times)
        {
            int arrival=vec[0];
            int destination=vec[1];
            for(int i=0;i<n;i++)
            {
                if(v[i]<=arrival)
                {
                    v[i]=destination;
                if(arrival==ans) return i;
                break;
                }
            }
        }
        return 0;
    }
};