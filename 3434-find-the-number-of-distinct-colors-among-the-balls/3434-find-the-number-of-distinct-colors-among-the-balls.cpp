class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, int> ballColor; // Maps each ball to its current color
        unordered_map<int, int> colorCount; // Counts occurrences of each color

        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            // If the ball already has a color, decrement the count of that color
            if (ballColor.find(ball) != ballColor.end()) {
                int prevColor = ballColor[ball];
                colorCount[prevColor]--;
                if (colorCount[prevColor] == 0) {
                    colorCount.erase(prevColor);
                }
            }

            // Assign the new color to the ball
            ballColor[ball] = color;
            colorCount[color]++;

            // The number of distinct colors is the size of the colorCount map
            ans.push_back(colorCount.size());
        }

        return ans;
    }
};
