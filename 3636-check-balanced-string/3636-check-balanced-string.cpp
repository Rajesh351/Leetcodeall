class Solution {
public:
    bool isBalanced(string num) {
        int ev = 0, odd = 0;
        for (int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0'; // Convert character to integer
            if (i % 2 == 0)
                ev += digit;
            else
                odd += digit;
        }
        if (odd == ev)
            return true;
        return false;
    }
};