class Solution {
public:
    void merge(vector<int>&arr, int s, int mid, int e) {
        int n1 = mid - s + 1;
        int n2 = e - mid;
        int a[n1];
        int b[n2];
        for (int i = 0; i < n1; i++) {
            a[i] = arr[s + i];
        }
        for (int i = 0; i < n2; i++) {
            b[i] = arr[mid + 1 + i];
        }
        int i = 0;
        int j = 0;
        int k = s;
        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                arr[k] = a[i];
                k++;
                i++;
            } else {
                arr[k] = b[j];
                k++;
                j++;
            }
        }
        while (i < n1) {
            arr[k] = a[i];
            k++;
            i++;
        }
        while (j < n2) {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    int mergesort(vector<int>&arr, int s, int e) {
        if (s < e) {
            int mid = (s + e) / 2;
            mergesort(arr, s, mid);
            mergesort(arr, mid + 1, e);
            merge(arr, s, mid, e);
        }
        return 0;
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};