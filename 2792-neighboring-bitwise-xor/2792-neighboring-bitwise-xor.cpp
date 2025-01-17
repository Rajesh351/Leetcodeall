class Solution {
public:
    bool doesValidArrayExist(vector<int>& arr) {
        int xor_sum=0;
    for (int num : arr) {
        xor_sum ^= num;  // Perform XOR operation
    }
      return xor_sum==0;
    }
};