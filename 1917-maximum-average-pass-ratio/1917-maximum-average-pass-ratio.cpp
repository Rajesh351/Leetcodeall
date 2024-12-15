class Solution {
public:
    struct MaxHeapComparator {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            // Calculate marginal gain for both pairs
            double gainA = static_cast<double>(a.first + 1) / (a.second + 1) - static_cast<double>(a.first) / a.second;
            double gainB = static_cast<double>(b.first + 1) / (b.second + 1) - static_cast<double>(b.first) / b.second;
            return gainA < gainB; // Max-heap: larger gain gets higher priority
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, MaxHeapComparator> maxh;

        // Push all classes into the heap
        for (int i = 0; i < classes.size(); i++) {
            maxh.push({classes[i][0], classes[i][1]});
        }

        // Distribute extra students to maximize average ratio
        while (extraStudents > 0) {
            auto it = maxh.top();
            maxh.pop();
            maxh.push({it.first + 1, it.second + 1}); // Add an extra student
            extraStudents--;
        }

        int n = classes.size();
        double ans = 0;

        // Calculate final average ratio
        while (!maxh.empty()) {
            auto it = maxh.top();
            maxh.pop();

            // Ensure floating-point division
            double temp = static_cast<double>(it.first) / it.second;
            ans += temp;
        }
        return ans / n; // Return the average
    }
};
