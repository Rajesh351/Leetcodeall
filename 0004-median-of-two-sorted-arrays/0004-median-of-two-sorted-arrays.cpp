class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int n1 = arr2.size();
        int i = 0;
        int j = 0;
        if ((n + n1) % 2 == 0) {
            int end = (n + n1) / 2;
            int start = end - 1;
            double curr = 0, prev = 0;
            while (i < n && j < n1) {
                if (arr1[i] < arr2[j]) {
                    prev = curr;
                    curr = arr1[i];
                    i++;
                } else {
                    prev = curr;
                    curr = arr2[j];
                    j++;
                }
                if (end == 0) {
                    return double((prev + curr) / 2);
                }
                end--;
            }
            while (i < n) {
                prev = curr;
                curr = arr1[i];
                i++;
                if (end == 0) {
                    return double((prev + curr) / 2);
                }
                end--;
            }
            while (j < n1) {
                prev = curr;
                curr = arr2[j];
                j++;
                if (end == 0) {
                    return double((prev + curr) / 2);
                }
                end--;
            }
        }
        else
        {
             int end = (n + n1) / 2;
            double curr = 0;
            while (i < n && j < n1) {
                if (arr1[i] < arr2[j]) {
                    curr = arr1[i];
                    i++;
                } else {
                    curr = arr2[j];
                    j++;
                }
                if (end == 0) {
                    return double(curr);
                }
                end--;
            }
            while (i < n) {
                curr = arr1[i];
                i++;
                if (end == 0) {
                  return double(curr);
                }
                end--;
            }
            while (j < n1) {
                curr = arr2[j];
                j++;
                if (end == 0) {
                   return double(curr);
                }
                end--;
            }

        }
        return 0;
    }
};