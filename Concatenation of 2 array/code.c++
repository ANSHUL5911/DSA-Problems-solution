## ✅ **Final Optimized Code**

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
};
```

--- ## 📝 **My Attempt of the Code** //This is wrong attempt done by me

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans={0};

        int n = nums.size();

        for(int i = 0; i<n;i++){
            int count=0;
            ans.push_back(nums[i]);
            if(i==(n-1)&& count<=1){
                i=0;
                count++;
            }
        }
        return ans;
    }
};
