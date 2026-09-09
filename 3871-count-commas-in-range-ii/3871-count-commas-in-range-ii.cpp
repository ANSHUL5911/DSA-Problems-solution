class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        long long power = 1000;

        while (n >= power) {
            count += n - power + 1;
            power *= 1000;
        }

        return count;
    }
};