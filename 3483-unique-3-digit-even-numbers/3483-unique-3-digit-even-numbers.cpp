class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] = {};

        // Count frequency of each digit
        for (int d : digits) {
            count[d]++;
        }

        int ans = 0;

        // Choose the hundreds digit
        for (int i = 1; i <= 9; i++) {
            if (count[i] == 0) continue;

            count[i]--;

            // Choose the tens digit
            for (int j = 0; j <= 9; j++) {
                if (count[j] == 0) continue;

                count[j]--;

                // Last digit must be even
                for (int k = 0; k <= 8; k += 2) {
                    if (count[k] > 0) {
                        ans++;
                    }
                }

                count[j]++;
            }

            count[i]++;
        }

        return ans;
    }
};