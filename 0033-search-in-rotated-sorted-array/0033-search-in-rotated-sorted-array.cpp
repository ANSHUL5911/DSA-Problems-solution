class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int res = -1;

        while (low <= high) {
            int guess = (low + high) / 2;
            if (nums[guess] == target) {
                return guess;
            }
            if (nums[guess] > nums[n - 1]) { // part 1
                if (target < nums[guess]) {
                    if (target < nums[0]) {
                        // move right
                        low = guess + 1;
                    } else { // move left
                        high = guess - 1;
                    }
                }

                else if (target > nums[guess])
                    low = guess + 1;
            }
            // part 2

            else {
                if (target < nums[guess]) {
                    high = guess - 1;
                }

                else if (target > nums[guess]) {
                    if (target > nums[n - 1]) {
                        //move left
                        high = guess - 1;
                    } else {
                        //move right
                        low = guess + 1;
                    }
                }
            }
        }

        return res;
    }
};