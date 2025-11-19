class Solution {
public:

    int Search_nums(vector<int>& nums,int s,int e,int original){
        //base case
        
        if(s>e){
            return original;
        }

        int mid = s+(e-s)/2;

        if(nums[mid]==original){
            return Search_nums(nums, 0, nums.size() - 1, 2 * original);
        }

        if(nums[mid]<original){
            return Search_nums(nums,mid+1,e,original);
        }
        else{
            return Search_nums(nums,s,mid-1,original);
        }
        
    }
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = nums.size()-1;

        return Search_nums(nums,s,e,original);
    }
};