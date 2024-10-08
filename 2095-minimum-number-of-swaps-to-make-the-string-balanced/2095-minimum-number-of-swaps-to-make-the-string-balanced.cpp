class Solution {
public:
   int minSwaps(string s) {
    int imbalance = 0;
    int swaps = 0;
    
    for (char c : s) {
        if (c == '[') {
            imbalance++;  
        } else {
            imbalance--; 
        }
        
        if (imbalance < 0) { 
            swaps++;  
            imbalance = 1; 
        }
    }
    
    return swaps;
}

};