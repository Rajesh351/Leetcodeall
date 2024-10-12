class Solution {
public:
int minGroups(vector<vector<int>>& intervals) {
    vector<pair<int, int>> events;

    // Record start and end events
    for (const auto& interval : intervals) {
        events.push_back({interval[0], 1});   // Start of interval
        events.push_back({interval[1] + 1, -1}); // End of interval (end + 1)
    }

    // Sort events, with tie-breaking to handle end (-1) before start (1)
    sort(events.begin(), events.end());

    int maxGroups = 0;
    int currentGroups = 0;

    // Sweep line to count overlapping intervals
    for (const auto& event : events) {
        currentGroups += event.second;
        maxGroups = max(maxGroups, currentGroups);
    }

    return maxGroups;
}

};