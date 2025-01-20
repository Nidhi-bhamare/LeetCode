class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, pair<int, int>> cellPos; // Maps matrix value to its position
        vector<int> rowCount(m, 0); // Keeps track of painted cells in each row
        vector<int> colCount(n, 0); // Keeps track of painted cells in each column
        
        // Store the position of each value in the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cellPos[mat[i][j]] = {i, j};
            }
        }
        
        // Paint the cells as per arr and check rows/columns
        for (int i = 0; i < arr.size(); ++i) {
            int val = arr[i];
            auto [row, col] = cellPos[val];
            
            rowCount[row]++;
            colCount[col]++;
            
            // Check if the row or column is fully painted
            if (rowCount[row] == n || colCount[col] == m) {
                return i;
            }
        }
        
        return -1; // If no row or column is completely painted
    }
};
