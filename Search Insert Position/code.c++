class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;

        while(s<=e){
            if(target==nums[mid]){
                return mid;
            }
            if(target<nums[mid]){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }
};