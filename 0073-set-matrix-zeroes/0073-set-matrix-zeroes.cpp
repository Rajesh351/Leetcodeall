class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector<pair<int, int>> row;
        vector<pair<int, int>> col;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row.push_back({i, j});
                    col.push_back({j, i});
                }
            }
        }

        for (int i = 0; i < row.size(); i++) {
            int a = row[i].first;
            for (int j = 0; j < matrix[0].size();
                 j++) {           // Fix: loop over columns
                matrix[a][j] = 0; // Fix: set entire row to 0
            }
        }

        for (int i = 0; i < col.size(); i++) {
            int a = col[i].first;
            for (int j = 0; j < matrix.size(); j++) { // Fix: loop over rows
                matrix[j][a] = 0; // Fix: set entire column to 0
            }
        }
    }
};