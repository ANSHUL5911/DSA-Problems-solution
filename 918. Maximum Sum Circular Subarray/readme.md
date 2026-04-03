<div align="center">

# 🔄 Maximum Sum Circular Subarray

### LeetCode 918 · Medium · Kadane's Algorithm

[![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://cplusplus.com/)
[![LeetCode](https://img.shields.io/badge/LeetCode-918-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/problems/maximum-sum-circular-subarray/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Medium-FFAA00?style=for-the-badge)]()
[![Complexity](https://img.shields.io/badge/Time-O(n)-brightgreen?style=for-the-badge)]()
[![Space](https://img.shields.io/badge/Space-O(1)-blue?style=for-the-badge)]()

<br/>

> *"A circular array lets the subarray wrap around — but that one edge case will silently return the wrong answer if you miss it."*
> — Senior Dev wisdom 🧠

</div>

---

## 📋 Table of Contents

- [Problem Statement](#-problem-statement)
- [Intuition](#-intuition)
- [The Two Cases Explained](#-the-two-cases-explained)
- [The Bug & The Fix](#️-the-bug--the-fix)
- [Full Corrected Solution](#-full-corrected-solution)
- [Step-by-Step Dry Run](#-step-by-step-dry-run)
- [Complexity Analysis](#-complexity-analysis)
- [Key Takeaways](#-key-takeaways)
- [Related Problems](#-related-problems)

---

## 📝 Problem Statement

Given a **circular integer array** `nums` of length `n`, return the **maximum possible sum** of a non-empty subarray.

A **circular array** means the end of the array connects to the beginning. A subarray may span the wrap-around point.

```
Input:  nums = [1, -2, 3, -2]
Output: 3        ← subarray [3]

Input:  nums = [5, -3, 5]
Output: 10       ← subarray [5, 5] wrapping around

Input:  nums = [-3, -2, -3]
Output: -2       ← subarray [-2] (only element to pick)
```

---

## 🧠 Intuition

Think about it this way: in a circular array, the maximum-sum subarray can either:

```
Normal Array:   [ _ _ _ ■ ■ ■ ■ _ _ _ ]
                          ↑ Case 1: stays inside
                          
Circular Array: [ ■ ■ _ _ _ _ _ _ ■ ■ ]
                 ↑ wraps ↑        ↑ Case 2: wraps around
```

This means we need to handle **exactly two cases** — and the answer is the maximum of both.

---

## 🔀 The Two Cases Explained

### Case 1 — No Wrap (Classic Kadane's)

The maximum subarray lies entirely within the array. This is the classic **Kadane's algorithm**.

```
nums = [5, -3, 5, -2, 9]
             ↑_____________↑
        best subarray = [5, -2, 9] = 12
```

```
ans_linear = max_subarray_sum(nums)
```

---

### Case 2 — Wraps Around (Inverted Kadane's)

The maximum subarray wraps from the end back to the beginning.

**Key insight 💡:** If we remove the *minimum* sum subarray from the middle, what remains on both ends forms our maximum circular sum.

```
nums = [5, -3, -4, 5, 9]
            ↑_____↑
       min subarray = [-3, -4] = -7

   wrap_max = total_sum - min_subarray
            = 12 - (-7) = 19
```

```
ans_circular = total_sum - min_subarray_sum(nums)
```

### 🏆 Final Answer

```
answer = max(ans_linear, ans_circular)
```

---

## 🐛 The Bug & The Fix

### ❌ What Goes Wrong

When **all numbers are negative** (e.g., `[-3, -2, -3]`):

| Step | Value |
|------|-------|
| `total_sum` | `-8` |
| `min_subarray` | `-8` (entire array!) |
| `res = total - min` | `-8 - (-8) = 0` |
| Expected answer | `-2` |

**`0` is returned, but `0` is WRONG.** 🚨

The wrap-around case is **invalid** when the minimum subarray spans the entire array — because wrapping requires at least one element on each side to remain.

---

### ✅ The One-Line Fix

```cpp
// ❌ BEFORE (buggy)
return max(res, ans2);

// ✅ AFTER (correct)
return (res == 0) ? ans2 : max(res, ans2);

// OR equivalently:
if (ans1 == sum) return ans2;   // min subarray = full array → wrap invalid
return max(res, ans2);
```

**Why does `res == 0` catch this?**

When all elements are negative, removing the entire array as the "min subarray" gives `sum - sum = 0`. Since the problem guarantees at least one element (so the real answer is always < 0 when all-negative), `res == 0` perfectly identifies this invalid state.

---

## 💻 Full Corrected Solution

```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int bestending = nums[0];
        int res = 0, sum = 0;
        int ans1 = nums[0];   // minimum subarray sum
        int ans2 = nums[0];   // maximum subarray sum
        int n = nums.size();

        // Step 1: Compute total sum
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Step 2: Find MINIMUM subarray sum (for wrap-around case)
        for (int i = 1; i < n; i++) {
            bestending = min(bestending + nums[i], nums[i]);
            ans1 = min(ans1, bestending);
        }
        res = sum - ans1;       // candidate circular answer
        bestending = nums[0];

        // Step 3: Find MAXIMUM subarray sum (classic Kadane's)
        for (int i = 1; i < n; i++) {
            bestending = max(bestending + nums[i], nums[i]);
            ans2 = max(ans2, bestending);
        }

        // Step 4: Handle all-negative edge case, then return best
        return (res == 0) ? ans2 : max(res, ans2);
    }
};
```

---

## 🧪 Step-by-Step Dry Run

### Test: `nums = [5, -3, 5, 9]`

**Total Sum = 16**

#### Min Subarray Pass:

| i | nums[i] | bestending | ans1 |
|---|---------|------------|------|
| 0 | 5       | 5          | 5    |
| 1 | -3      | min(2, -3) = **-3** | **-3** |
| 2 | 5       | min(2, 5) = 2  | -3   |
| 3 | 9       | min(11, 9) = 9 | -3   |

`res = 16 - (-3) = 19` ✅

#### Max Subarray Pass (Kadane's):

| i | nums[i] | bestending | ans2 |
|---|---------|------------|------|
| 0 | 5       | 5          | 5    |
| 1 | -3      | max(2, -3) = **2** | 5  |
| 2 | 5       | max(7, 5) = **7**  | 7  |
| 3 | 9       | max(16, 9) = **16**| 16 |

`ans2 = 16`

**Final: `max(19, 16) = 19`** ✅

---

### Test: `nums = [-3, -2, -3]` (All-negative edge case)

| Step | Value |
|------|-------|
| `sum` | `-8` |
| `ans1` (min sub) | `-8` |
| `res = sum - ans1` | `0` ← invalid! |
| `ans2` (max sub) | `-2` |
| **Guard kicks in** | `res == 0` → **return `ans2 = -2`** ✅ |

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|-----------|-------------|
| ⏱️ **Time** | `O(n)` | 3 single-pass loops — all linear |
| 🧠 **Space** | `O(1)` | Only a fixed number of integer variables |

### Why O(n) is Optimal

You must read every element at least once to determine the maximum subarray sum — making `O(n)` a theoretical lower bound. This solution achieves it! 🏆

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n²) | O(1) | Try every subarray |
| Segment Tree | O(n log n) | O(n) | Overkill for this |
| **This Solution** | **O(n)** | **O(1)** | **Optimal ✅** |

---

## 🎯 Key Takeaways

```
1. 🔀  CIRCULAR = TWO CASES
       max(linear_max, total - linear_min)

2. ⚡  DUALITY OF KADANE'S
       Same structure, swap max ↔ min

3. 🪲  THE ALL-NEGATIVE TRAP
       Guard: if (res == 0) return ans2;

4. 🏆  OPTIMAL
       O(n) time · O(1) space — can't do better
```

---

## 🔗 Related Problems

| Problem | Difficulty | Connection |
|---------|------------|------------|
| [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | 🟢 Easy | Classic Kadane's — prerequisite |
| [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | 🟡 Medium | Same DP pattern, different operator |
| [1186. Maximum Subarray Sum with One Deletion](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/) | 🟡 Medium | Extended Kadane's variant |
| [2321. Maximum Score of Spliced Array](https://leetcode.com/problems/maximum-score-of-spliced-array/) | 🔴 Hard | Uses the same inversion trick |

---

## 👨‍💻 Author Notes

> **From a Senior Dev perspective:** This problem is a beautiful example of *problem transformation* — converting an unfamiliar problem (circular max subarray) into two instances of a well-known one (linear max/min subarray). The real skill isn't in the coding; it's in **seeing the equivalence**. The bug is equally instructive: edge cases with all-negative arrays are a class of "degenerate input" bugs that appear repeatedly in sliding window and DP problems. Always ask yourself: *"what happens when my formula reduces to a trivial value?"*

---

<div align="center">

**Made with 🧠 and ☕ | Happy coding!**

[![Star this repo](https://img.shields.io/github/stars/ASJ5911/dsa-solutions?style=social)](.)

</div>

# Code
```cpp []
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int bestending = nums[0];
        int res = 0;
        int sum = 0;
        int ans1 = nums[0];
        int ans2 = nums[0];
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
        }

        for (int i = 1; i < n; i++) {
            int v1 = bestending + nums[i];
            int v2 = nums[i];

            bestending = min(v1, v2);
            ans1 = min(ans1, bestending);
        }
        res = sum - ans1;
        bestending = nums[0];

        for (int i = 1; i < n; i++) {
            int v1 = bestending + nums[i];
            int v2 = nums[i];

            bestending = max(v1, v2);
            ans2 = max(ans2, bestending);
        }
        if (ans1 == sum) // min subarray is the whole array, circular case invalid
            return ans2;
        return max(res, ans2);
    }
};
```