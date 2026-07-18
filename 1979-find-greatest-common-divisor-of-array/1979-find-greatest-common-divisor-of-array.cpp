class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s=INT_MAX;
        int l=INT_MIN;

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<s){
                s = nums[i];
            }
            if(nums[i]>l){
                l = nums[i];
            }
        }

        while(l !=0){
            int temp = l;
            l = s % l;
            s = temp;
        }

        return s;
    }
};