class Solution {
public:
    // \U0001f50e Find the first positive index
    int findFirstPositiveIndex(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] > 0) {
                result = mid;
                right = mid - 1;  // Positive elements might be on the left side
            } else {
                left = mid + 1;  // Search on the right side
            }
        }

        return result;
    }

    // \U0001f50e Find the last negative index
    int findLastNegativeIndex(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < 0) {
                result = mid;
                left = mid + 1;  // Negative elements might be on the right side
            } else {
                right = mid - 1;  // Search on the left side
            }
        }

        return result;
    }

    // \U0001f9ee Maximum count calculation
    int maximumCount(vector<int>& nums) {
        if(nums[0]==0 && nums[nums.size()-1]==0) return 0;
        if (nums[nums.size() - 1] < 0) return nums.size();  // All negative
        if (nums[0] > 0) return nums.size();  // All positive

        int pos = findFirstPositiveIndex(nums);
        if(nums[0]==0) return nums.size()-pos;
        int neg = findLastNegativeIndex(nums);
        if(nums[nums.size()-1]==0) return neg+1;

        pos = nums.size() - pos;  
        return max(neg + 1, pos);  
    }
};
