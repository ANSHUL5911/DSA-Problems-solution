class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> frq(101, 0); // safe size
        int sum1 = 0;
        int sum2 = 0;

        // Count frequencies
        for (int i = 0; i < n; i++) {
            if (frq[nums[i]] == 0) {
                frq[nums[i]] = 1;
                sum1++;
            } else {
                frq[nums[i]]++;
                sum2 += frq[nums[i]];
            }
        }

        // find the max frequency
        int maxfrq = 0;

        for (int i = 0; i < frq.size(); i++) {
            if (frq[i] > maxfrq) {
                maxfrq = frq[i];
            }
        }

        // check if there is any number same as maxfrq if there is then add it
        // to the result

        int result = 0;

        for (int i = 0; i < frq.size(); i++) {
            if (maxfrq == frq[i]) {
                result = result + frq[i];
            }
        }

        return result;
    }
};