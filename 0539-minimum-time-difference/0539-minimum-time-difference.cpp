class Solution {
public:
    int findMinDifference(vector<string>& nums) {
        vector<int> minutes;
        for (int i = 0; i < nums.size(); i++) {
            string str = nums[i];
            int hours = stoi(str.substr(0, 2));
            int mins = stoi(str.substr(3, 2));
            minutes.push_back(hours * 60 + mins);
        }
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }
        
        // Calculate the circular difference between the last and first time (crossing midnight)
        int circularDiff = (1440 - minutes.back()) + minutes[0];
        minDiff = min(minDiff, circularDiff);
        
        return minDiff;
    }
};
