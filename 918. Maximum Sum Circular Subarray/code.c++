class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& nums) {
            int bestending = nums[0];
            int res = 0;
            int sum = 0;
            int ans1 = nums[0];
            int ans2 = nums[0];
            int n = nums.size();
    
            for (int i = 0; i < n; i++) {
                sum = sum + nums[i];
            }
    
            for (int i = 1; i < n; i++) {
                int v1 = bestending + nums[i];
                int v2 = nums[i];
    
                bestending = min(v1, v2);
                ans1 = min(ans1, bestending);
            }
            res = sum - ans1;
            bestending = nums[0];
    
            for (int i = 1; i < n; i++) {
                int v1 = bestending + nums[i];
                int v2 = nums[i];
    
                bestending = max(v1, v2);
                ans2 = max(ans2, bestending);
            }
            if (ans1 == sum) // min subarray is the whole array, circular case invalid
                return ans2;
            return max(res, ans2);
        }
    };