class Solution {
    public:
        int Maxsum(int n, vector<int>& nums, int res, int bestending) {
    
            for (int i = 1; i < n; i++) {
                int v1 = bestending + nums[i];
                int v2 = nums[i];
    
                bestending = max(v1, v2);
                res = max(res,bestending);
            }
            return res;
        }
        int Minsum(int n, vector<int>& nums, int res, int bestending) {
    
            for (int i = 1; i < n; i++) {
                int v1 = bestending + nums[i];
                int v2 = nums[i];
    
                bestending = min(v1, v2);
                res = min(res,bestending);
            }
            return res;
        }
        int maxAbsoluteSum(vector<int>& nums) {
            int n = nums.size();
            int res = nums[0];
            int bestending = nums[0];
            int pos = Maxsum(n, nums, res, bestending);
            int neg = Minsum(n, nums, res, bestending);
    
            int ans = max(abs(pos), abs(neg));
    
            return ans;
        }
    };