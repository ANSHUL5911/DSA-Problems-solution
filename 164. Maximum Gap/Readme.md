# 🚀 Maximum Gap — LeetCode Problem

<div align="center">

![LeetCode](https://img.shields.io/badge/LeetCode-Hard-red?style=for-the-badge&logo=leetcode&logoColor=white)
![Language](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Approach](https://img.shields.io/badge/Approach-Sorting-blueviolet?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Accepted-brightgreen?style=for-the-badge)

> *"Given an unsorted array, find the maximum difference between the successive elements in its sorted form."*

</div>

---

## 📌 Problem Statement

Given an integer array `nums`, return the **maximum difference** between two successive elements in the **sorted** version of the array.

If the array contains less than two elements, return `0`.

You must write an algorithm that runs in **linear time** and uses **linear extra space**.

### 🔢 Examples

```
Input:  nums = [3, 6, 9, 1]
Output: 3
Explanation: sorted → [1, 3, 6, 9] → gaps: 2, 3, 3 → max = 3

Input:  nums = [10]
Output: 0
Explanation: fewer than 2 elements → return 0
```

---

## 🧠 Intuition

> 💡 *Think of it like runners on a number line — we sort them first, then walk through consecutive pairs to find the biggest jump.*

The core insight is simple:

- **The "maximum gap" only exists between adjacent elements** once the array is sorted.
- There's no need to compare every pair — just sort it and walk through with a sliding window of size 2.
- A two-pointer approach (`low` and `high`) lets us cleanly scan each consecutive pair.

```
Unsorted:  [3, 6, 9, 1]
                  ↓  sort
Sorted:    [1, 3, 6, 9]
            ↑  ↑
           low high  → gap = 3-1 = 2

               ↑  ↑
              low high → gap = 6-3 = 3

                  ↑  ↑
                 low high → gap = 9-6 = 3

Max of [2, 3, 3] = 3 ✅
```

---

## 🏗️ Approach — Step by Step

```
┌─────────────────────────────────────────────────────────┐
│                 MAXIMUM GAP ALGORITHM                   │
│                                                         │
│  STEP 1 ── Edge Case Check                             │
│            if size < 2 → return 0                      │
│                   ↓                                     │
│  STEP 2 ── Sort the array                              │
│            [3,6,9,1] → [1,3,6,9]                       │
│                   ↓                                     │
│  STEP 3 ── Two-pointer sliding window                  │
│            low=0, high=1 → compute diff                │
│            store all diffs in result vector            │
│                   ↓                                     │
│  STEP 4 ── Return max element from result              │
└─────────────────────────────────────────────────────────┘
```

### 🔍 Code Walkthrough

```cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {

        // ✅ STEP 1: Edge case — need at least 2 elements
        if (nums.size() < 2) {
            return 0;
        }

        // ✅ STEP 2: Sort so consecutive elements are adjacent
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // ✅ STEP 3: Two pointers — walk through adjacent pairs
        int low = 0, high = 1;
        vector<int> res;

        while (low < n && high < n) {
            int diff = abs(nums[low] - nums[high]);  // gap between neighbors
            res.push_back(diff);
            low++;
            high++;
        }

        // ✅ STEP 4: Find and return the maximum gap
        return *max_element(res.begin(), res.end());
    }
};
```

---

## 📊 Dry Run — Visualized

Let's trace through `nums = [3, 6, 9, 1]`:

| Step | `low` | `high` | `nums[low]` | `nums[high]` | `diff` | `res` |
|------|-------|--------|-------------|--------------|--------|-------|
| Sort | —     | —      | —           | —            | —      | `[1,3,6,9]` |
| 1    | 0     | 1      | 1           | 3            | 2      | `[2]` |
| 2    | 1     | 2      | 3           | 6            | 3      | `[2,3]` |
| 3    | 2     | 3      | 6           | 9            | 3      | `[2,3,3]` |
| End  | —     | —      | —           | —            | **max = 3** | ✅ |

---

## ⏱️ Complexity Analysis

### 🔴 Time Complexity

| Operation           | Cost        |
|---------------------|-------------|
| Sorting the array   | `O(N log N)` |
| Two-pointer scan    | `O(N)`       |
| Finding max element | `O(N)`       |
| **Total**           | **`O(N log N)`** |

> ⚠️ *Note: The problem statement asks for O(N) time. That requires a Bucket Sort / Radix Sort approach. This solution uses O(N log N) via `std::sort`, which is accepted but not strictly optimal.*

### 🟢 Space Complexity

| Storage         | Cost   |
|-----------------|--------|
| `res` vector    | `O(N)` |
| Sorting (in-place) | `O(log N)` auxiliary |
| **Total**       | **`O(N)`** |

---

## ⚠️ Edge Cases Handled

```
✅  nums = [1]         → size < 2 → return 0
✅  nums = [1, 1]      → diff = 0 → return 0
✅  nums = [1, 1000000]→ large gap → handled correctly
✅  Negative numbers   → abs() handles sign
```

---

## 🆚 Comparison with Optimal (Bucket Sort)

| Feature            | This Solution 🟡 | Bucket Sort 🟢 |
|--------------------|-----------------|----------------|
| Time Complexity    | O(N log N)      | O(N)           |
| Space Complexity   | O(N)            | O(N)           |
| Code Simplicity    | ⭐⭐⭐⭐⭐        | ⭐⭐⭐          |
| Interview Clarity  | ✅ Very clear   | ⚠️ Tricky to explain |
| Handles all cases  | ✅              | ✅             |

> 💼 **Senior Dev Tip:** In an interview, start with this sorting-based approach to show clarity of thought. Then discuss the Bucket Sort optimization to show depth. Both strategies together will impress your interviewer.

---

## 🧩 Key Concepts Used

- 🔀 **Sorting** — `std::sort` with O(N log N)
- 👆 **Two Pointers** — classic sliding window of size 2
- 📦 **`max_element` STL** — clean way to find max in a vector
- 🛡️ **Edge case handling** — always check for small inputs first

---

## 💡 Learnings & Takeaways

```
🔑  Always sort first when comparing adjacent elements
🔑  Two pointers are powerful for scanning windows
🔑  abs() is essential when working with gaps/diffs
🔑  Edge cases (size < 2) should be the first check
🔑  Clean, readable code > clever one-liners in interviews
```

---

## 🔗 Related Problems

| Problem | Difficulty | Concept |
|---------|------------|---------|
| [Sort Colors](https://leetcode.com/problems/sort-colors/) | 🟡 Medium | Sorting |
| [Minimum Difference Between Largest and Smallest](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/) | 🟡 Medium | Sorting |
| [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) | 🟡 Medium | Array tricks |

---

<div align="center">

### ⭐ If this helped you, drop a star on this repo!

*Made with ❤️ | Happy Coding!* 🚀

</div>