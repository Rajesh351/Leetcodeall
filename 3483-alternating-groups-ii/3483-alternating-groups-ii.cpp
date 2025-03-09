class Solution {
public:
    int numberOfAlternatingGroups(vector<int> arr, int k) {
    for(int i=0;i<k-1;i++) arr.push_back(arr[i]);
    int n=arr.size();
     int i = 0, j = 0, count = 0;

    while (j < n) {
        if (j > 0 && arr[j] == arr[j - 1]) {
            i = j; // डुप्लिकेट मिलने पर i को अपडेट करें
        }

        if (j - i + 1 == k) { 
            count++;
            i++; // सही तरीके से i को बढ़ाएँ
        }
        j++;
    }

    return count;
    }
};