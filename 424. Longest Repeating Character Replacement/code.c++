class Solution {
    public:
        int characterReplacement(string s, int k) {
            int low = 0;
            vector<int> f(256, 0);
            int res = 0;
            int n = s.length();
    
            for (int high = 0; high < n; high++) {
    
                f[(unsigned char)s[high]]++;
    
                int len = high - low + 1;
                int maxcnt = *max_element(f.begin(), f.end());
                int diff = len - maxcnt;
    
                while (diff > k) {
    
                    f[(unsigned char)s[low]]--;
    
                    low++;
                    len = high - low + 1;
                    maxcnt = *max_element(f.begin(), f.end());
                    diff = len - maxcnt;
                }
    
                len = high - low + 1;
                res = max(res, len);
            }
            
            return res;
        }
    };