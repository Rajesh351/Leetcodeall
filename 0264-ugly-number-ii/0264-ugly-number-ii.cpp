class Solution {
public:
int nthUglyNumber(int n) {
    std::vector<int> uglyNumbers(n);
    uglyNumbers[0] = 1;
    
    int i2 = 0, i3 = 0, i5 = 0; // Pointers for multiples of 2, 3, and 5
    int nextMultipleOf2 = 2;
    int nextMultipleOf3 = 3;
    int nextMultipleOf5 = 5;
    
    for (int i = 1; i < n; i++) {
        // Choose the smallest next ugly number
        int nextUgly = std::min({nextMultipleOf2, nextMultipleOf3, nextMultipleOf5});
        uglyNumbers[i] = nextUgly;
        
        // Increment the respective pointer
        if (nextUgly == nextMultipleOf2) {
            i2++;
            nextMultipleOf2 = uglyNumbers[i2] * 2;
        }
        if (nextUgly == nextMultipleOf3) {
            i3++;
            nextMultipleOf3 = uglyNumbers[i3] * 3;
        }
        if (nextUgly == nextMultipleOf5) {
            i5++;
            nextMultipleOf5 = uglyNumbers[i5] * 5;
        }
    }
    
    return uglyNumbers[n - 1];
}

};