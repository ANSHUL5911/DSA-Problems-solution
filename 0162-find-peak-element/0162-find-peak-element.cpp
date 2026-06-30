class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 2;
        if (n == 1) {
            return 0;
        }

        while (low <= high) {
            int guess = (low + high) / 2;

            if (nums[guess] < nums[guess + 1]) {
                low = guess + 1;
            } else {
                high = guess - 1;
            }
        }
        return low;
    }
};