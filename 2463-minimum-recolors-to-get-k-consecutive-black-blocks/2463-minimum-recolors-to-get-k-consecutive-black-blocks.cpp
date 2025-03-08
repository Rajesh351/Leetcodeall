class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        if (blocks.size() < k)
            return 0;
        int ans=INT_MAX;
        for (int i = 0; i <= blocks.size() - k; i++) {
             int b = 0, w = 0;
            for (int j = i; j < i + k; j++) {
                if (blocks[j] == 'B')
                    b++;
                else
                    w++;
            }
            ans = min(ans, w);
        }

        return ans;
    }
};