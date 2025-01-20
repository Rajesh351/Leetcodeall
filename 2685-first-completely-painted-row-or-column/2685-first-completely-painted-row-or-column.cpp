class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        unordered_map<int, pair<int, int>> mp;

    // Mapping each element in the matrix to its row and column index
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            mp[mat[i][j]] = {i, j};
        }
    }

    unordered_map<int, int> rowCount, colCount;

    for (int i = 0; i < arr.size(); i++) {
        auto it = mp[arr[i]];
        int row = it.first;
        int col = it.second;

        rowCount[row]++;
        colCount[col]++;

        // Check if the entire row is filled
        if (rowCount[row] == mat[0].size())  
            return i;

        // Check if the entire column is filled
        if (colCount[col] == mat.size())  
            return i;
    }

    return -1; // If no row or column i
    }

};