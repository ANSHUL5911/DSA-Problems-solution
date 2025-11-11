class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int count = 1; // first element is always unique

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[count] = nums[i]; // move unique element forward
                count++;
            }
        }

        // optional: replace remaining with placeholder (keeping your idea)
        for (int i = count; i < n; i++) {
            nums[i] = INT_MIN; // or any marker like '_'
        }

        return count; // number of unique elements
    }
};
