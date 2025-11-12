#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum_r = 0, sum_l = 0;

        // if array is empty or has 1 element, no valid pivot
        if (n == 0) {
            return -1;
        }

        if(n==1){
            return 0;
        }

        // calculate total sum (right sum initially)
        for (int i = 0; i < n; i++) {
            sum_r += nums[i];
        }

        // iterate through each index
        for (int i = 0; i < n; i++) {
            // subtract current element from right sum (as we move pivot)
            sum_r -= nums[i];

            // check if left sum equals right sum
            if (sum_l == sum_r) {
                return i;
            }

            // add current element to left sum for next iteration
            sum_l += nums[i];
        }

        return -1; // no pivot found
    }
};

