class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;   // Simple case: no carry
                return digits; 
            }
            digits[i] = 0; // If 9, becomes 0 and carry continues
        }

        // If we reach here, all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
