class Solution {
public:
    int mod = 1000000007;

    long long mod_pow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;

            base = (base * base) % mod;
            exp /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2;  // digits at even indices (0-based)
        long long odd_positions = n / 2;         // digits at odd indices

        long long curr = mod_pow(5, even_positions, mod);  // 5 choices at even positions
        long long temp = mod_pow(4, odd_positions, mod);   // 4 choices at odd positions

        return (curr * temp) % mod;
    }
};
