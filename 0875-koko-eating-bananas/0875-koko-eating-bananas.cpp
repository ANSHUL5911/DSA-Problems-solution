class Solution {
public:
    long long findHours(vector<int>& piles, int n, int speed) {
        long long hr = 0;
        for (int i = 0; i < n; i++) {
            hr = hr + piles[i] / speed;
            if (piles[i] % speed != 0) {
                hr++;
            }
        }
        return hr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        // sort(piles.begin(), piles.end());

        int low = 1, high = *max_element(piles.begin(),piles.end());
        int res = -1;

        while (low <= high) {
            int guess = (low + high) / 2;
            long long hour = findHours(piles, n, guess);

            if (hour > h) {
                low = guess + 1;
            } else {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};