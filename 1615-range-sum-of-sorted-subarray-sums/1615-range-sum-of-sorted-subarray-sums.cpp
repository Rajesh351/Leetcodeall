class Solution {
public:
    int mod=1000000007;
    int rangeSum(vector<int>& arr, int n, int left, int right) {
    std::vector<int> subarraySums;
    for (int start = 0; start < n; ++start) {
        int sum = 0;
        for (int end = start; end < n; ++end) {
            sum=sum+arr[end];
            sum=sum%mod;
            subarraySums.push_back(sum);
        }
    }
    sort(subarraySums.begin(),subarraySums.end());
    int sum=0;
     for(int i=left-1;i<right;i++)
     {
        sum=sum+subarraySums[i];
        sum=sum%mod;
     }
     return sum;
    }
};