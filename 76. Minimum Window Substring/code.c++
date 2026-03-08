class Solution {
    public:
        bool sahi_hai_kya(vector<int>& needed, vector<int>& have) {
            for (int i = 0; i < 256; i++) {
                if (have[i] < needed[i]) {
                    return false;
                }
            }
            return true;
        }
    
        string minWindow(string s, string t) {
            vector<int> needed(256, 0);
            vector<int> have(256, 0);
    
            int low = 0;
            int res = INT_MAX;
            int start = 0;
    
            for (int i = 0; i < t.length(); i++) {
                needed[(unsigned char)t[i]]++;
            }
    
            for (int high = 0; high < s.length(); high++) {
                have[(unsigned char)s[high]]++;
    
                while (sahi_hai_kya(needed, have)) {
                    int len = high - low + 1;
                    if (res > len) {
                        res = len;
                        start = low;
                    }
                    have[(unsigned char)s[low]]--;
                    low++;
                }
            }
            if (res == INT_MAX) return "";
    
            return s.substr(start, res);
        }
    };