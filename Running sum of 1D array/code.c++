class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        int sum =0 ;
        for(int i = 0; i<n;i++){
            
            sum =sum+nums[i];
            temp.push_back(sum);
        }

        nums=temp;

        return nums;
    }
};