class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

      int n = mat.size(), m = mat[0].size();
    vector<int> row(n, 0), col(m, 0);

    // Counting 0s in rows and columns in one pass
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row[i] += mat[i][j];
            col[j] += mat[i][j];
        }
    }

    // Finding special 1s
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
                count++;
            }
        }
    }
    return count;
    }
};