class Solution {
public:
    struct cmp {
        bool operator()(pair<int,char> &a, pair<int,char> &b) {
            return a.first < b.first; // max heap by frequency
        }
    };

    string reorganizeString(string s) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int n = s.size();
        int maxFreq = *max_element(count.begin(), count.end());
        if (maxFreq > (n + 1) / 2) return ""; // impossible to rearrange

        priority_queue<pair<int,char>, vector<pair<int,char>>, cmp> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) pq.push({count[i], (char)('a' + i)});
        }

        string res = "";
        while (!pq.empty()) {
            pair<int,char> p1 = pq.top(); pq.pop();

            if (res.empty() || res.back() != p1.second) {
                res.push_back(p1.second);
                p1.first--;
                if (p1.first > 0) pq.push(p1);
            } else {
                // top char would repeat — borrow the next most frequent char
                if (pq.empty()) return ""; // shouldn't happen given the maxFreq check
                pair<int,char> p2 = pq.top(); pq.pop();
                res.push_back(p2.second);
                p2.first--;
                if (p2.first > 0) pq.push(p2);
                pq.push(p1); // put p1 back for later
            }
        }
        return res;
    }
};