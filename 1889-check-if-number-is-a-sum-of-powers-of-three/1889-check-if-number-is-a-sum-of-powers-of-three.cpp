class Solution {
public:
  
    bool checkPowersOfThree(int n) {
    vector<int> v;
    int val = 1;
    
    // Generate powers of 3 up to 3^16 (since 3^16 > 10^7)
    for (int i = 0; i <= 16; i++) {
        v.push_back(val);
        if (val > INT_MAX / 3) break; // Prevent integer overflow
        val *= 3;
    }

    // Checking whether n can be represented as a sum of distinct powers of 3
    for (int i = v.size() - 1; i >= 0; i--) {
        if (n >= v[i]) {
            n -= v[i];  // Subtract the largest available power of 3
        }
        if (n == 0) return true;
    }
    
    return false;
    }
};