class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minVal = INT_MAX, maxVal = INT_MIN;
        int minValIn = 0, maxValIn = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < minVal) {
                minVal = nums[i];
                minValIn = i;
            }
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxValIn = i;
            }
        }

        if (n == 1) return 1;

        vector<int> arr;

        // Ensure minValIn <= maxValIn for consistent logic
        if (minValIn > maxValIn) swap(minValIn, maxValIn);

        // Case 1: Remove both from front
        arr.push_back(maxValIn + 1);
        // Case 2: Remove both from back
        arr.push_back(n - minValIn);
        // Case 3: Remove min from front and max from back
        arr.push_back((minValIn + 1) + (n - maxValIn));

        return *min_element(arr.begin(), arr.end());
    }
};