class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(),meetings.end());
    int count = 0;
    int prev = -1;  

    for (const auto& meeting : meetings) {
        int start = meeting[0], end = meeting[1];

        if (start > prev) {
            count += end - start + 1;  // Count non-overlapping meeting days
        } else if (end > prev) {
            count += end - prev;  // Count extra days in overlapping case
        }

        prev = std::max(prev, end);  // Update last occupied day
    }

    return days - count;  
    }
};