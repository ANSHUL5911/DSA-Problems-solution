class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {
        // Step1: Sort interval
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        // Step2: merge the interval
        vector<vector<int>> merged;

        for (auto& interval : occupiedIntervals) {
            if (merged.empty() || merged.back()[1] + 1 < interval[0]) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        // Step3: Subtract the free interval
        vector<vector<int>> result;
        for (auto& b : merged) {
            if (b[0] > freeEnd || b[1] < freeStart) {
                result.push_back(b);
            } else {
                // overlapping
                if (b[0] < freeStart) {
                    result.push_back({b[0], freeStart - 1});
                }
                if (b[1] > freeEnd) {
                    result.push_back({freeEnd + 1, b[1]});
                }
            }
        }
        return result;
    }
};