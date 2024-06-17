class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if((abs(i-j)+1)%2!=0)
                {
                for (int k = i; k <= j; k++) {
                    sum+=arr[k];
                }
                }
            }
        }
        return sum;
    }
};