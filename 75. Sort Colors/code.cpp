class Solution {
    public:
        vector<int> solve(int n, vector<int> &nums){
            int low = 0;
            int mid = 0;
            int high = n - 1;
    
            while( mid <= high ){
    
                if(nums[mid]==0){
                    swap(nums[low],nums[mid]);
                    low++;
                    mid++;
                }
    
                else if(nums[mid]==1){
                    mid++;
                }
    
                else{  //nums[mid]==2
                    swap(nums[mid],nums[high]);
                    high--;
                }
            }
            return nums;
        }
    
    
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            solve(n,nums);
        }
    };