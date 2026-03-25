class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int bestending = nums[0];   // Max subarray sum ending at current index
            int res = nums[0];          // Global maximum so far
    
            for (int i = 1; i < n; i++) {
                int v1 = nums[i];               // Option 1: Start fresh
                int v2 = nums[i] + bestending;  // Option 2: Extend previous subarray
                bestending = max(v1, v2);       // Take the better option
                res = max(res, bestending);     // Update global best
            }
    
            return res;
        }
    };