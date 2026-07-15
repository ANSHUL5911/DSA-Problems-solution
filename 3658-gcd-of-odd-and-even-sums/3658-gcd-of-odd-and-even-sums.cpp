class Solution {
public:
    // int GCD(int a,int b){
    //     // while(b != 0){
    //     //     a = b;
    //     //     b = a % b;
    //     // }
    //     // return a;
    // }

    int gcdOfOddEvenSums(int n) {
        int sumOdd = n * n;
        int sumEven = n * (n + 1);

        // return GCD(sumOdd,sumEven);
        int res = sumEven - sumOdd;
        return res;
    }
};