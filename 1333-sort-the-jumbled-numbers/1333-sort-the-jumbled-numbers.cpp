class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mapped;
        for (int num : nums){
            int copy_num = num;
            int mapped_num = num == 0 ? mapping[0] : 0;
            int place_value = 1;

            while (num > 0) {
                int digit = num % 10;
                mapped_num += place_value * mapping[digit];
                num /= 10;
                place_value *= 10;
            }
            mapped.push_back({mapped_num, copy_num});
        }
        sort(mapped.begin(),mapped.end(),[&](pair<int,int> a, pair<int,int> b){
            return a.first < b.first;
        });
        vector<int> result;
        for (auto n : mapped){
            result.push_back(n.second);
        }
        return result;
    }
};