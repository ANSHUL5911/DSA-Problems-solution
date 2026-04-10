class Solution {
    public:
        int findMaxLength(vector<int>& nums) {
            int n    = nums.size();
            int zero = 0, one = 0;
            unordered_map<int, int> f;   // diff → first index seen
            int res  = 0;
    
            for (int i = 0; i < n; i++) {
                // Step 1: update counters
                if (nums[i] == 0) zero++;
                else              one++;
    
                int diff = zero - one;
    
                // Step 2: entire prefix is balanced
                if (diff == 0) {
                    res = max(res, i + 1);
                    continue;
                }
    
                // Step 3: same diff seen before → balanced window
                if (f.find(diff) == f.end()) {
                    f[diff] = i;               // first occurrence — never overwrite
                } else {
                    res = max(res, i - f[diff]);
                }
            }
    
            return res;
        }
    };