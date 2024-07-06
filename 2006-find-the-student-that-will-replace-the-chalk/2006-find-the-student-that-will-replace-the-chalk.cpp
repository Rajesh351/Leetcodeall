class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {

        long long int tot = 0;

        for (int i = 0; i < chalk.size(); i++) {
            tot += chalk[i];
        }
        long long rem = k % tot;

        for (int i = 0; i < chalk.size(); i++) {
            if (rem < chalk[i])
                return i;
            rem -= chalk[i];
        }
        return 0;
    }
};