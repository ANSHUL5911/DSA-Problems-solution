<div align="center">

# 525 · Contiguous Array

![LeetCode](https://img.shields.io/badge/LeetCode-525-orange?style=for-the-badge&logo=leetcode&logoColor=white)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge&logo=cplusplus&logoColor=white)
![Pattern](https://img.shields.io/badge/Pattern-Prefix_Sum-purple?style=for-the-badge)

<br/>

> *Given a binary array `nums`, return the **maximum length** of a contiguous subarray with an equal number of `0`s and `1`s.*

<br/>

[Problem](#-problem) · [Intuition](#-intuition) · [Approach](#-approach) · [Walkthrough](#-walkthrough) · [Solution](#-solution) · [Complexity](#-complexity) · [Pitfalls](#-common-pitfalls) · [Pattern](#-key-pattern)

</div>

---

## 📋 Problem

| | |
|---|---|
| **Input** | Binary array `nums` |
| **Output** | Length of longest balanced subarray |
| **Constraint** | Balanced = equal count of `0`s and `1`s |

### Examples

```
Input : [0, 1]           →  Output : 2   ([0,1])
Input : [0, 1, 0]        →  Output : 2   ([0,1] or [1,0])
Input : [0, 1, 0, 1, 1]  →  Output : 4   ([0,1,0,1])
```

---

## 💡 Intuition

The key insight is a **mental substitution** — treat every `0` as `−1`.

The problem now becomes:

> **"Find the longest subarray whose elements sum to zero."**

This is a classic **prefix sum** problem. Define the running balance:

```
diff = count(zeros) − count(ones)
```

If `diff` is the same at two indices `j` and `i` (where `i > j`), then **exactly equal 0s and 1s** were encountered between them — so `nums[j+1 .. i]` is a valid balanced subarray.

A hash map stores the **first time** each `diff` value appears, giving us the **widest possible window** for that balance score.

---

## 🧭 Approach

```
1.  Scan left → right, tracking zero and one counters
2.  Compute diff = zero − one at each index
3.  diff == 0   →  entire prefix is balanced, length = i + 1
4.  diff seen   →  balanced window found, length = i − firstSeen[diff]
5.  diff new    →  record firstSeen[diff] = i  (never overwrite)
6.  Return the maximum length seen
```

The hash map is never overwritten because we always want the **earliest** occurrence of each `diff` — that maximises the window length.

---

## 🔍 Walkthrough

**Input:** `nums = [0, 1, 0, 1, 1]`

```
 i  │ nums[i] │ zero │ one │  diff  │ action                   │  res
────┼─────────┼──────┼─────┼────────┼──────────────────────────┼──────
 0  │    0    │  1   │  0  │   +1   │ store  f[+1] = 0         │   0
 1  │    1    │  1   │  1  │    0   │ diff=0 → len = 1+1 = 2   │   2  ✓
 2  │    0    │  2   │  1  │   +1   │ f[+1]=0 → len = 2−0 = 2  │   2
 3  │    1    │  2   │  2  │    0   │ diff=0 → len = 3+1 = 4   │   4  ✓
 4  │    1    │  2   │  3  │   −1   │ store  f[−1] = 4         │   4
```

**Answer: `4`** — the subarray `[0, 1, 0, 1]` at indices `0..3`.

**Why does `diff=0` at `i=1` and `i=3` mean the whole prefix is balanced?**
Because `zero == one` at both points — the counts cancelled out perfectly from the very start.

---

## ✅ Solution

```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n    = nums.size();
        int zero = 0, one = 0;
        unordered_map<int, int> f;   // diff → first index seen
        int res  = 0;

        for (int i = 0; i < n; i++) {
            // Step 1: update counters
            if (nums[i] == 0) zero++;
            else              one++;

            int diff = zero - one;

            // Step 2: entire prefix is balanced
            if (diff == 0) {
                res = max(res, i + 1);
                continue;
            }

            // Step 3: same diff seen before → balanced window
            if (f.find(diff) == f.end()) {
                f[diff] = i;               // first occurrence — never overwrite
            } else {
                res = max(res, i - f[diff]);
            }
        }

        return res;
    }
};
```

---

## 📊 Complexity

| | Complexity | Reason |
|---|---|---|
| ⏱ **Time** | `O(n)` | Single pass; hash map ops are `O(1)` average |
| 🧠 **Space** | `O(n)` | Hash map stores at most `n` distinct diff values |

---

## ⚠️ Common Pitfalls

### Bug 1 — `i++` instead of `i + 1`

```cpp
// ❌ WRONG — post-increment mutates i, then the for-loop increments it again
//            → skips the next element entirely
res = max(res, i++);

// ✅ CORRECT — pure expression, no side effects
res = max(res, i + 1);
```

> `i++` returns the current value of `i` **and** increments it. The `for` loop then increments `i` again — you skip an index on every `diff == 0` hit.

---

### Bug 2 — Overwriting the first occurrence

```cpp
// ❌ WRONG — always updating shrinks the window
f[diff] = i;

// ✅ CORRECT — store only the first time this diff appears
if (f.find(diff) == f.end()) {
    f[diff] = i;
}
```

> The **earliest** occurrence of a diff value gives the **longest** window. Overwriting it with a later index discards valid (wider) solutions.

---

### Bug 3 — Skipping the `diff == 0` case

If you only handle the map lookup and never check `diff == 0`, you miss every balanced **prefix** (subarrays starting at index `0`). These are often the longest ones.

---

## 🧩 Key Pattern

This problem is a direct application of the **Prefix Sum + Hash Map** pattern:

```
Problem shape:   find longest subarray where running_sum[i] == running_sum[j]

Recipe:
  → Compute prefix sum as you scan
  → Store first occurrence of each sum value in a hash map
  → On revisit: candidate length = i − firstSeen[sum]
  → Track and return the maximum
```

### Same pattern, different problems

| # | Problem | Twist |
|---|---|---|
| **560** | Subarray Sum Equals K | Target sum `K` instead of `0` |
| **974** | Subarray Sums Divisible by K | Modular arithmetic — store `sum % K` |
| **1124** | Longest Well-Performing Interval | Same diff trick; `>8h` day = `+1`, else `−1` |

---

## 🗺️ Visual Mental Model

```
nums :  [  0,   1,   0,   1,   1  ]
             ↓    ↓    ↓    ↓    ↓
diff :  [ +1,   0,  +1,   0,  -1  ]
                                     (diff = cumulative zero − one)

  diff = 0  at i=1  →  prefix [0..1]  balanced, length 2
  diff = 0  at i=3  →  prefix [0..3]  balanced, length 4  ◄ answer
  diff = +1 at i=0 and i=2  →  window [1..2]  length 2
```

The hash map is your *"have I seen this balance before?"* memory.
Every time you revisit a balance score, you've enclosed a perfectly balanced window.

---

<div align="center">

**If this helped, consider giving it a ⭐**

![Visitor Badge](https://img.shields.io/badge/Happy_Coding!-🚀-brightgreen?style=for-the-badge)

</div>