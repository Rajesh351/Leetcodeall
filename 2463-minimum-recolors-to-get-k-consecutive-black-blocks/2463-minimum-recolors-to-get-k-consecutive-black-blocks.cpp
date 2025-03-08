class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        if (blocks.size() < k)
            return 0;

        int b = 0, w = 0, i = 0;
        while (i < k) {
            if (blocks[i] == 'B')
                b++;
            else
                w++;
            i++;
        }

        int ans = w;
        int j = 0;
        while (i < blocks.size()) {
            if (blocks[i] == 'B')
                b++;
            else
                w++;
            

            if (blocks[j] == 'B')
                b--;
            else
                w--;
             ans = min(ans, w);

            i++;
            j++;
        }

        return ans;
    }
};