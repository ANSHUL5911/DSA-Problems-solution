class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxDiagSq = -1;   
        int maxArea = -1;     

        for (int i = 0; i < n; i++) {
            int a = dimensions[i][0];
            int b = dimensions[i][1];
            int diagSq = a * a + b * b;  
            int area = a * b;

            
            if (diagSq > maxDiagSq || (diagSq == maxDiagSq && area > maxArea)) {
                maxDiagSq = diagSq;
                maxArea = area;
            }
        }

        return maxArea;
    }
};
