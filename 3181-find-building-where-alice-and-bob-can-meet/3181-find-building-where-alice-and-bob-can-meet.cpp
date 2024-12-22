class Solution {
public:
   vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> NGE(n, -1);
        stack<int> st;
        for(int i = n-1; i >=0; --i){
            while(!st.empty() && heights[st.top()] <= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                NGE[i] = st.top();
            }
            st.push(i);
        }
        unordered_map<long long, int> cache;
        function<int(int, int, int)> dfs = [&](int x, int y, int i) -> int {
            // Compute h = max(heights[x], heights[y])
            int h = max(heights[x], heights[y]);
            // Encode (h, i) into a single key
            long long key = ((long long)h << 32) | (unsigned int)i;
            
            // Check if the result is already in the cache
            if(cache.find(key) != cache.end()){
                return cache[key];
            }
            
            // Base cases
            if(i >= n){
                cache[key] = -1;
                return -1;
            }
            if(i == -1){
                cache[key] = -1;
                return -1;
            }
            
            // Check if building i satisfies the meeting conditions
            bool condition = false;
            if(x != i && y != i && heights[i] > heights[x] && heights[i] > heights[y]){
                condition = true;
            }
            if(x == i && y != i && heights[i] > heights[y]){
                condition = true;
            }
            if(y == i && x != i && heights[i] > heights[x]){
                condition = true;
            }
            if(condition){
                cache[key] = i;
                return i;
            }
            int nextI = NGE[i];
            int ret = dfs(x, y, nextI);
            cache[key] = ret;
            return ret;
        };
        vector<int> res;
        for(auto &qry : queries){
            int ai = qry[0];
            int bi = qry[1];
            int i = min(ai, bi);
            int j = max(ai, bi);
            
            if(i == j){
                res.push_back(j);
            }
            else if(heights[i] < heights[j]){
                res.push_back(j);
            }
            else{
                int meeting_building = dfs(ai, bi, j);
                res.push_back(meeting_building);
            }
        }
        
        return res;
    }
};