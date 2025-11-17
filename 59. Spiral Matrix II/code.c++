class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n, vector<int>(n));  // FIX: 2D matrix to fill
        
        int row = n;
        int col = n;

        // index initialisation
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;

        int count = 1;        // start filling from 1
        int total = row * col;

        while (count <= total) {

            // LEFT → RIGHT
            for (int index = startingCol; count <= total && index <= endingCol; index++) {
                ans[startingRow][index] = count++;
            }
            startingRow++;

            // TOP → BOTTOM
            for (int index = startingRow; count <= total && index <= endingRow; index++) {
                ans[index][endingCol] = count++;
            }
            endingCol--;

            // RIGHT → LEFT
            for (int index = endingCol; count <= total && index >= startingCol; index--) {
                ans[endingRow][index] = count++;
            }
            endingRow--;

            // BOTTOM → TOP
            for (int index = endingRow; count <= total && index >= startingRow; index--) {
                ans[index][startingCol] = count++;
            }
            startingCol++;
        }

        return ans;
    }
};