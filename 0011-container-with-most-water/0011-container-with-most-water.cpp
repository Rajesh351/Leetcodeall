class Solution {
public:
    int maxArea(vector<int>& arr) {
        
        
          
         int n = arr.size();
    int left = 0, right = n - 1; // Two pointers
    int maxArea = 0;

    while (left < right) {
        // Calculate the current area
        int height = min(arr[left], arr[right]);
        int width = right - left;
        int currArea = height * width;

        // Update maximum area
        maxArea = max(maxArea, currArea);

        // Move the pointer with the smaller height
        if (arr[left] < arr[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
    }
};