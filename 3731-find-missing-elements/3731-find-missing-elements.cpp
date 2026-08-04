class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        if (n == 0) return {};

        int mn = nums[0];
        int mx = nums[n - 1];

        vector<int> res;
        int j = 0;

        for (int i = mn; i <= mx; i++) {

            while (j < n && nums[j] < i) {
                j++;
            }

            if (j == n || nums[j] != i) {
                res.push_back(i);
            }
        }

        return res;
    }
};