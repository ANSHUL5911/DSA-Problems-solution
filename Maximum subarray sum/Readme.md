# 🚀 Maximum Subarray — Kadane's Algorithm

> **LeetCode #53** | Difficulty: 🟡 Medium | Topic: Dynamic Programming / Greedy

---
## Interactive explanation - https://kadanealgo.netlify.app/
---

## 📌 Problem Statement

Given an integer array `nums`, find the **subarray with the largest sum** and return its sum.

```
Input:  nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6
Explanation: [4, -1, 2, 1] has the largest sum = 6
```

---

## 💡 Intuition

Imagine you're walking through the array and collecting numbers into a "bag".

At every step you ask yourself one question:

> **"Is it better to take this element alone, or to extend my current collection?"**

- If your current running sum is **dragging you down** (negative), it's better to **start fresh** from the current element.
- If your current running sum is **adding value** (positive), it's better to **extend** it with the current element.

This single greedy decision at every step is the entire magic of Kadane's Algorithm. We never need to look back.

---

## 🛠️ Approach — Kadane's Algorithm

### Core Idea: Local Optimum → Global Optimum

At each index `i`, we maintain:

| Variable | Meaning |
|---|---|
| `bestending` | Maximum subarray sum **ending exactly at index i** |
| `res` | Best answer seen **anywhere** so far (global maximum) |

### The Decision at Each Step

```
bestending = max(nums[i],  nums[i] + bestending)
                  ↑                ↑
            Start fresh       Extend previous
            (throw away       subarray
            old subarray)
```

We pick whichever option is larger. Then we update our global best:

```
res = max(res, bestending)
```

### Step-by-Step Trace

For `nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`:

| i | nums[i] | Start fresh | Extend | bestending | res |
|---|---------|------------|--------|------------|-----|
| 0 | -2      | —           | —      | **-2**     | -2  |
| 1 | 1       | 1           | -1     | **1**      | 1   |
| 2 | -3      | -3          | -2     | **-2**     | 1   |
| 3 | 4       | **4**       | 2      | **4**      | 4   |
| 4 | -1      | -1          | 3      | **3**      | 4   |
| 5 | 2       | 2           | **5**  | **5**      | 5   |
| 6 | 1       | 1           | **6**  | **6**      | ✅ 6 |
| 7 | -5      | -5          | 1      | **1**      | 6   |
| 8 | 4       | 4           | **5**  | **5**      | 6   |

**Answer: 6** (subarray `[4, -1, 2, 1]`)

---

## 📝 Solution Code (C++)

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int bestending = nums[0];   // Max subarray sum ending at current index
        int res = nums[0];          // Global maximum so far

        for (int i = 1; i < n; i++) {
            int v1 = nums[i];               // Option 1: Start fresh
            int v2 = nums[i] + bestending;  // Option 2: Extend previous subarray
            bestending = max(v1, v2);       // Take the better option
            res = max(res, bestending);     // Update global best
        }

        return res;
    }
};
```

---

## ⏱️ Complexity Analysis

### Time Complexity: `O(n)`

- We iterate through the array **exactly once** — a single linear pass.
- No nested loops, no recursion.
- Each element is visited and processed in `O(1)` constant time.

### Space Complexity: `O(1)`

- We use only **two variables** (`bestending` and `res`) regardless of input size.
- No auxiliary arrays, stacks, or hash maps.
- In-place processing — optimal memory usage.

```
n = 10         →  10 operations
n = 1,000      →  1,000 operations
n = 1,000,000  →  1,000,000 operations   ← scales linearly!
```

---

## 🔄 Why Not Other Approaches?

| Approach | Time | Space | Notes |
|---|---|---|---|
| Brute Force (all subarrays) | O(n²) | O(1) | TLE on large inputs |
| Divide & Conquer | O(n log n) | O(log n) | Elegant but overkill |
| DP with full table | O(n) | O(n) | Correct but wastes space |
| **Kadane's (this solution)** | **O(n)** | **O(1)** | ✅ Optimal in both dimensions |

Kadane's insight is that you only ever need the **previous** `bestending` value — not the entire DP table. That's the O(n) → O(1) space optimization.

---

## 🧠 Key Takeaways

1. **Greedy + DP hybrid**: Kadane's is technically a 1D DP where the recurrence is so simple it reduces to a greedy decision.
2. **The "fresh start" principle**: A negative running sum is always worse than restarting. This is the core insight.
3. **Works for all-negative arrays**: We initialize `bestending = nums[0]` and start the loop at index 1, ensuring we handle cases like `[-5, -3, -1]` correctly (answer: `-1`).
4. **Extends naturally**: This pattern generalizes to Maximum Product Subarray, Circular Subarray problems, and 2D maximum subarray.

---

## 🧩 Related Problems

- [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) — same idea, but track both min and max
- [918. Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/) — Kadane's + total sum trick
- [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) — secretly the same problem on differences

---

## ✅ Edge Cases Handled

```cpp
// All negative numbers
nums = [-3, -1, -2]  →  Output: -1  ✓

// Single element
nums = [5]  →  Output: 5  ✓

// All positive
nums = [1, 2, 3]  →  Output: 6  ✓

// Large mixed array
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]  →  Output: 6  ✓
```

---

*If this helped, drop a ⭐ on the repo or an upvote on LeetCode!*