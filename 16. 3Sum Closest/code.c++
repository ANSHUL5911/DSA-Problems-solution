class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int n = nums.size();
            if (n < 3) return 0;
    
            sort(nums.begin(), nums.end());
    
            int res_sum = nums[0] + nums[1] + nums[2]; 
    
            for (int i = 0; i < n - 2; i++) {
                int left = i + 1;
                int right = n - 1;
    
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
    
                    if (abs(sum - target) < abs(res_sum - target)) {
                        res_sum = sum;
                    }
    
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        return sum; 
                    }
                }
            }
            return res_sum;
        }
    };