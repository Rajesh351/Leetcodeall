class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_map<int,int>mp;
        for(int a:arr1) mp[a]++;
        vector<int>ans;
        int k=0;
        for(int i=0;i<arr2.size();i++)
        {
            if(mp.find(arr2[i])!=mp.end())
            {
                int a=mp.at(arr2[i]);
                for(int j=0;j<a;j++) ans.push_back(arr2[i]);
            }
        }
        unordered_map<int,int>mp1;
            for(int a:arr2) mp1[a]++;

        sort(arr1.begin(),arr1.end());

        for(int i=0;i<arr1.size();i++)
        {
            if(mp1.find(arr1[i])==mp1.end()) ans.push_back(arr1[i]);
        }
        return ans;
    }
};