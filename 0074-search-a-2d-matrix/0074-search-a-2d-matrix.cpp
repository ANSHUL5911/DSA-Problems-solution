class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = (m * n) - 1;

        while (low <= high) {
            int guess = (low + high) / 2;
            int element = matrix[guess / m][guess % m];

            if (element == target) {
                return true;
            }
            if (element < target) {
                low = guess + 1;
            } else {
                high = guess - 1;
            }
        }
        return false;
    }
};