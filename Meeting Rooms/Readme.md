<!-- HEADER BADGES -->
<div align="center">

![Interval Scheduling](https://img.shields.io/badge/INTERVAL_SCHEDULING-C%2B%2B-00C896?style=for-the-badge&labelColor=0f172a&color=00C896)
![Algorithm](https://img.shields.io/badge/GREEDY_ALGORITHM-0f172a?style=for-the-badge&labelColor=0f172a&color=818cf8)
![Time](https://img.shields.io/badge/O(n_log_n)-TIME-0f172a?style=for-the-badge&labelColor=0f172a&color=f7b731)
![Space](https://img.shields.io/badge/O(1)-SPACE-0f172a?style=for-the-badge&labelColor=0f172a&color=00C896)
![Sort](https://img.shields.io/badge/SORT_+_SCAN-0f172a?style=for-the-badge&labelColor=0f172a&color=818cf8)
![Greedy](https://img.shields.io/badge/GREEDY-0f172a?style=for-the-badge&labelColor=0f172a&color=f7b731)

# Can One Person Attend *All* Meetings?

**A beautifully simple problem hiding a powerful pattern — sort, scan, and decide. Master this, and an entire family of interval problems opens up.**

</div>

---

## 🔴 THE PROBLEM

Given a list of meeting intervals `[start, end]`, determine if a single person can attend every meeting — meaning **no two meetings overlap**.

| ❌ CONFLICT FOUND | ✅ ALL CLEAR |
|---|---|
| `Input: [[1,5], [3,7], [8,10]]` | `Input: [[1,3], [4,6], [7,9]]` |
| ❌ `False` — `[1,5]` and `[3,7]` clash | ✅ `True` — no overlap at all |

---

## 🟢 THE INTUITION

**1.** If you had a physical planner, you'd read meetings in chronological order — not randomly. Sorting enables a single clean pass instead of comparing every pair.

**2.** Track where the current meeting ends. Ask one question for each next meeting: does it start after the previous one ends?

**3.** Don't stop early — merge the conflicting meetings into a combined window so you can correctly detect cascading overlaps further down the list.

---

## 🟣 THE SOLUTION

```cpp
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {

        // Step 1 — sort chronologically (by start time)
        sort(arr.begin(), arr.end());

        int start1 = arr[0][0];
        int end1   = arr[0][1];
        int meet   = 1;       // optimistic: assume no conflict
        int n      = arr.size();

        for (int i = 1; i < n; i++) {
            int start2 = arr[i][0];
            int end2   = arr[i][1];

            if (end1 <= start2) {
                // safe — back-to-back or gapped, slide window forward
                start1 = start2;
                end1   = end2;
            } else {
                // overlap! merge to catch cascading conflicts
                meet   = 0;
                start1 = min(start1, start2);
                end1   = max(end1,   end2);
            }
        }
        return meet;
    }
};
```

> The key insight: `end1 <= start2` allows back-to-back meetings (ending at 5, starting at 5 is fine). Only *interior* overlap counts as a conflict.

---

## 🟡 DRY RUN

**Input:** `[[6,10],[1,5],[3,8]]`

**After sorting:**
```
arr = [[1,5], [3,8], [6,10]]
window = [1, 5]
```

**Compare [1,5] vs [3,8]:**
```
end1=5, start2=3 → 5 > 3 → OVERLAP
merge → window = [1, 8],  meet = 0
```
> ❌ Conflict detected

**Compare [1,8] vs [6,10]:**
```
end1=8, start2=6 → 8 > 6 → OVERLAP
merge → window = [1, 10], meet = 0
```
> ❌ Cascading conflict caught

**Final answer:**
```
return 0 → False
```
> ✅ Correct — 3 meetings, 2 overlaps

---

## 🟢 COMPLEXITY

| | Complexity | Why |
|---|---|---|
| ⏱️ **Time** | `O(n log n)` | Dominated by the sort step. The scan after is just O(n). Sorting is the hero. |
| 🧮 **Space** | `O(1)` | Only a handful of integer variables — no extra arrays or auxiliary data structures. |

---

## 🔴 EDGE CASES

| Result | Case | Example |
|---|---|---|
| ✅ | Single meeting — always true | `[[2, 4]] → true` |
| ✅ | Back-to-back — allowed (`end == start` is fine) | `[[1,3],[3,5]] → true` (end1 ≤ start2 passes) |
| ❌ | Identical meetings — conflict | `[[2,4],[2,4]] → false` |
| ❌ | Nested meeting — one swallowed by another | `[[1,10],[3,5]] → false` (inner contained in outer) |

---

## 🟣 LEVEL UP

Once this clicks, these are your natural next steps — they all share the same **sort-then-scan** DNA:

| Problem | Description | Key Difference |
|---|---|---|
| **Merge Intervals** | Merge all overlapping intervals into the minimum set of non-overlapping ranges. | Same DNA, different output |
| **Meeting Rooms II** | Find the minimum number of conference rooms needed to host all meetings simultaneously. | Min-heap extension |
| **Insert Interval** | Add a new meeting to an already sorted list and re-merge any new overlaps that form. | Binary search + merge |
| **Non-Overlapping Intervals** | Remove the fewest meetings to make the remaining list completely overlap-free. | Greedy with removal count |

---

## 🟡 KEY TAKEAWAYS

> 🟢 **Sort first — always**
> Transforms an O(n²) brute force into an elegant O(n log n) scan. One of the most powerful tricks in interview prep.

> 🟡 **Rolling window — one variable does it all**
> Tracking just `end1` is sufficient. You never need the full previous interval.

> 🔵 **`end ≤ start`, not `end < start`**
> Back-to-back is allowed. The boundary condition is strict — get this wrong and you'll fail edge cases.

> 🔴 **Merge on conflict — don't stop early**
> Merging the overlapping pair lets you correctly detect nested and cascading conflicts further along the list.

---

<div align="center">

You didn't just read about an algorithm — you understood **why it works**.
That's the difference between grinding and actually learning.

🗓️ *May your intervals never overlap* ✨

</div>