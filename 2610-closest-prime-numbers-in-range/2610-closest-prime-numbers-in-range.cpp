class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

     if(left==right) return {-1,-1};
       vector<int> v;
        for (int i = left; i <= right; i++) {
            bool check=true;
            if (i < 2) continue;
            for (int j = 2; j*j <=i; j++)

            {
                if (i % j == 0) {
                    check = false;
                    break;
                }
            }
            if (check == true) {
                v.push_back(i);
            }
        }
        if(v.size()==1 || v.size()==0) return {-1,-1};
        int a = -1, b = -1;
        int minval = INT_MAX;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1] - v[i] < minval) {
                minval = v[i + 1] - v[i];
                a = v[i];
                b = v[i + 1];
            }
        }
        return {a, b};
    }
};