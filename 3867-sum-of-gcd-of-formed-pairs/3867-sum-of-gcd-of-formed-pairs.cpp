class Solution {
public:
    int gcd(int a, int b) {

        if (a == 0 && b == 0) {
            return 0;
        }

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = 0;

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i]=gcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int low = 0, high = n - 1;
        long long sum = 0;

        while (low < high) {
            sum = sum + gcd(prefixGcd[low], prefixGcd[high]);
            low++;
            high--;
        }
        return sum;
    }
};