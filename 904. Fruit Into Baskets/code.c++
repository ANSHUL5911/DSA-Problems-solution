class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int low = 0;
            int high = 0;
            unordered_map<int, int> f;
            int res = INT_MIN;
            int n = fruits.size();
    
            for (high = 0; high < n; high++) {
    
                f[fruits[high]]++;
    
                while (f.size() > 2) {
    
                    f[fruits[low]]--;
                    if (f[fruits[low]] == 0) {
                        f.erase(fruits[low]);
                    }
    
                    low++;
                }
    
                int len = high - low + 1;
                res = max(res, len);
            }
            if (res == INT_MIN) {
                return 0;
            }
            return res;
        }
    };