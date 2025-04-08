class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        unordered_map<int, int> mp;
        for (int a : nums)
            mp[a]++;
        bool check = false;
        for (auto it : mp) {
            if (it.second>1)
                check = true;
        }
        if (check == false)
            return 0;

        int i = 0;
        int count=0;
        while (i < nums.size()) {

            int j=i;
            while(j< i+3 && j<nums.size())
            {
                 if (mp[nums[j]] == 1)
                    mp.erase(nums[j]);
                else {
                    int val = mp[nums[j]];
                    val = val - 1;
                    mp[nums[j]] = val;
                }
                j++;
            }
            count++;
            bool check = false;
            for (auto it : mp) {
                if (it.second >1)
                    check = true;
            }
            if (check == false)
                return count;
           i=i+3;
             if (i > nums.size()) return count;
                    
        }
        return count;
    }
};