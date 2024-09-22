class Solution {
public:
    int countSteps(int prefix, int n) {
        long long curr = prefix;
        long long next = prefix + 1;
        int steps = 0;
        while (curr <= n) {
            steps += min((long long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }

        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            int steps = countSteps(curr, n);

            if (steps <= k) {
                curr++;
                k -= steps;
            } else {

                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};