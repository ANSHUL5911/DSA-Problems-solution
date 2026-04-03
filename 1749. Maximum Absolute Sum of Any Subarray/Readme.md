# 🔢 Max Absolute Subarray Sum

> **Dual Kadane's Algorithm** — Find the subarray whose absolute sum is the greatest, in **O(n) time** and **O(1) space**.

<br>

## 📌 Problem Statement

Given an integer array `nums`, return the **maximum absolute sum** of any (possibly empty) subarray.

```
Input:  nums = [-3, 1, -5, 4, 6, -2, 1]
Output: 10
Reason: Subarray [4, 6] has sum 10 → |10| = 10 ✅
```

> 🔗 [LeetCode 1749 — Maximum Absolute Sum of Any Subarray](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/)

<br>

---

## 💡 Intuition

Think of the array as a **stock price chart**.

- 📈 You want the **biggest rally** → maximum subarray sum
- 📉 You want the **biggest crash** → minimum subarray sum
- 🏆 Whoever has the larger **absolute magnitude** is the answer

```
max(|maxSubarraySum|, |minSubarraySum|)
```

A very negative subarray like `[-10, -10, -10]` has sum `-30`, 
but `|-30| = 30` which could easily beat any positive subarray — 
so we **must** track both extremes simultaneously.

<br>

---

## 🧠 Approach — Dual Kadane's Algorithm

This is a clean extension of the classic **Kadane's Algorithm**.

At every index `i`, you face exactly **one binary decision**:

| Option | Description |
|--------|-------------|
| ✅ Extend | Add `nums[i]` to the current subarray |
| 🔄 Reset  | Start a brand new subarray from `nums[i]` |

`max(ending + nums[i], nums[i])` encodes this decision in a single line.

We run **two Kadane trackers in parallel** — one for max, one for min — in a single pass.

<br>

---

## ✅ Optimized Code (C++)

```cpp
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxRes = nums[0], minRes = nums[0];
        int maxEnding = nums[0], minEnding = nums[0];

        for (int i = 1; i < n; i++) {
            maxEnding = max(maxEnding + nums[i], nums[i]);
            minEnding = min(minEnding + nums[i], nums[i]);

            maxRes = max(maxRes, maxEnding);
            minRes = min(minRes, minEnding);
        }

        return max(abs(maxRes), abs(minRes));
    }
};
```

<br>

---

## 🔍 Step-by-Step Walkthrough

**Array:** `[-3, 1, -5, 4, 6, -2, 1]`

| i | nums[i] | maxEnding | maxRes | minEnding | minRes |
|---|---------|-----------|--------|-----------|--------|
| init | -3 | **-3** | -3 | **-3** | -3 |
| 1 | 1 | **1** | 1 | **-2** | -3 |
| 2 | -5 | **-4** | 1 | **-7** | -7 |
| 3 | 4 | **4** | 4 | **-3** | -7 |
| 4 | 6 | **10** | 10 | **3** | -7 |
| 5 | -2 | **8** | 10 | **1** | -7 |
| 6 | 1 | **9** | 10 | **2** | -7 |

```
Answer = max(|10|, |-7|) = max(10, 7) = 10 ✅
```

<br>

---

## ⚙️ Complexity Analysis

| Metric | Optimized (this) | Original (two passes) | Brute Force |
|--------|------------------|-----------------------|-------------|
| ⏱️ Time  | **O(n)**         | O(2n)                 | O(n²)       |
| 🗂️ Space | **O(1)**         | O(1)                  | O(1)        |

> 💬 **Why does the merge matter?**  
> O(2n) and O(n) are the same Big-O class, but combining the loops **eliminates function call overhead**, halves cache pressure, and makes intent crystal clear — all points worth mentioning in a FAANG interview.

<br>

---

## ⚠️ Edge Cases

| Case | Input | Expected Output | Notes |
|------|-------|-----------------|-------|
| All negative | `[-3, -5, -2]` | `10` | `minRes = -10`, `\|-10\|` wins |
| All positive | `[1, 2, 3]` | `6` | `maxRes = 6` wins |
| Single element | `[7]` | `7` | Loop never runs; init handles it |
| All zeros | `[0, 0, 0]` | `0` | Both trackers stay 0 |
| Mixed large values | `[-100, 200, -100]` | `200` | `maxRes = 200` wins |

> ⚠️ For very large inputs in C++, use `long long` to avoid integer overflow.

<br>

---

## 🔑 Key Takeaways

```
✅  Dual Kadane's = run max and min trackers in one pass
✅  At each index: extend or reset — that's the only choice
✅  Final answer = max(|maxRes|, |minRes|)
✅  O(n) time, O(1) space — optimal
```

<br>

---

## 🏷️ Tags

`Dynamic Programming` · `Kadane's Algorithm` · `Array` · `Greedy` · `LeetCode Medium`

<br>

---

## 📚 Related Problems

| Problem | Difficulty | Connection |
|---------|------------|------------|
| [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | 🟡 Medium | Classic Kadane's — foundation of this problem |
| [918. Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/) | 🟡 Medium | Kadane's on a circular array |
| [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | 🟡 Medium | Same "track two extremes" pattern |

<br>

---

<div align="center">

Made with 🧠 and Kadane's Algorithm

</div>

# Code
```cpp []
class Solution {
public:
    int Maxsum(int n, vector<int>& nums, int res, int bestending) {

        for (int i = 1; i < n; i++) {
            int v1 = bestending + nums[i];
            int v2 = nums[i];

            bestending = max(v1, v2);
            res = max(res,bestending);
        }
        return res;
    }
    int Minsum(int n, vector<int>& nums, int res, int bestending) {

        for (int i = 1; i < n; i++) {
            int v1 = bestending + nums[i];
            int v2 = nums[i];

            bestending = min(v1, v2);
            res = min(res,bestending);
        }
        return res;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int bestending = nums[0];
        int pos = Maxsum(n, nums, res, bestending);
        int neg = Minsum(n, nums, res, bestending);

        int ans = max(abs(pos), abs(neg));

        return ans;
    }
};
```