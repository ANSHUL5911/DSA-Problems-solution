class Solution {
    public:
        int maximumGap(vector<int>& nums) {
            int low = 0;
            int high = 1;
            vector<int> res;
            sort(nums.begin(),nums.end());
            int n = nums.size();
    
            if(nums.size()<2){
                return 0;
            }
    
            while(low<n && high<n){
                int diff = abs(nums[low]-nums[high]);
                res.push_back(diff);
    
                low++;
                high++;
            }
    
    
            int maxdiff = *max_element(res.begin(),res.end());
            return maxdiff;
        }
    };