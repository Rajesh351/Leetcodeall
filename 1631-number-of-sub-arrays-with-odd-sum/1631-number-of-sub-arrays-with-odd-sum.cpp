class Solution {
public:
int mod = 1000000007;
   int numOfSubarrays(vector<int>& arr) {
    int oddCount = 0, evenCount = 1; // evenCount = 1 to count empty subarray case
    int count = 0, prefixSum = 0;

    for (int num : arr) {
        prefixSum += num;
        
        if (prefixSum % 2 == 0) { 
            count = (count + oddCount) % mod; // Add previous odd prefix sums
            evenCount++; 
        } else { 
            count = (count + evenCount) % mod; // Add previous even prefix sums
            oddCount++; 
        }
    }
    
    return count;
    }
};