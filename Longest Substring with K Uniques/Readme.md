# 🪟 Longest Substring with K Distinct Characters
### Sliding Window | HashMap | O(n) Time | O(k) Space

---

> **Problem:** Given a string `s` and an integer `k`, find the length of the **longest substring** containing **exactly `k` distinct characters**. Return `-1` if no such substring exists.

---

## 📌 Table of Contents
- [Problem Statement](#-problem-statement)
- [Intuition](#-intuition--the-rubber-band-mental-model)
- [Approach](#-approach--step-by-step)
- [Dry Run](#-dry-run--visual-walkthrough)
- [Code](#-final-code-with-comments)
- [Complexity Analysis](#-complexity-analysis)
- [Edge Cases](#-edge-cases)
- [Key Takeaways](#-key-takeaways)

---
# 😎 Interactive Explanation is here - 
---

## 🎯 Problem Statement

```
Input:  s = "aabacbebebe", k = 3
Output: 7
Reason: "cbebebe" has exactly 3 distinct chars {c, b, e} and length 7
```

| | |
|---|---|
| **Input** | String `s`, integer `k` |
| **Output** | Length of longest substring with **exactly** k distinct chars |
| **Edge** | Return `-1` if string never has k distinct chars |

---

## 🧠 Intuition — The "Rubber Band" Mental Model

Imagine a **rubber band** stretched over the string with two endpoints:
- 🔴 **`low`** — left end of the band
- 🟢 **`high`** — right end of the band

```
s = a a b a c b e b e b e
    ↑               ↑
   low             high
   └───── window ──┘
```

**The idea:**
1. **Stretch right** (`high++`) — add new characters greedily
2. **Shrink left** (`low++`) — if distinct chars **exceed k**, pull the left end in
3. At every valid state (exactly k distinct), **measure the band's length**
4. Track the **maximum** length seen

> 💡 **Why not brute force?**
> Brute force checks all O(n²) substrings → O(n³) total.
> Sliding window: each character is visited **at most twice** (once by `high`, once by `low`) → **O(n)** ✅

---

## 🔍 Approach — Step by Step

```
Step 1 ── Initialize
         low = 0, res = 0, f = {} (frequency map)

Step 2 ── Expand right (high pointer moves →)
         f[s[high]]++  →  adds character to window

Step 3 ── Shrink left (if f.size() > k)
         f[s[low]]--
         if f[s[low]] == 0 → erase from map (distinct count drops)
         low++

Step 4 ── Update result (only when EXACTLY k distinct)
         if f.size() == k:
             res = max(res, high - low + 1)

Step 5 ── Final check
         if f.size() < k → return -1 (never reached k distinct)
         else            → return res
```

---

## 🎬 Dry Run — Visual Walkthrough

**Input:** `s = "aabacbebebe"`, `k = 3`

```
Index:   0  1  2  3  4  5  6  7  8  9  10
Chars:   a  a  b  a  c  b  e  b  e  b  e
```

| high | low | Window | f{ } | size | res |
|------|-----|--------|------|------|-----|
| 0 | 0 | `"a"` | {a:1} | 1 | 0 |
| 1 | 0 | `"aa"` | {a:2} | 1 | 0 |
| 2 | 0 | `"aab"` | {a:2, b:1} | 2 | 0 |
| 3 | 0 | `"aaba"` | {a:3, b:1} | 2 | 0 |
| 4 | 0 | `"aabac"` | {a:3, b:1, c:1} | **3** ✅ | **5** |
| 5 | 0 | `"aababc"` → shrink... | ... | ... | ... |
| 5 | 2 | `"babc"` → shrink... | ... | ... | ... |
| 5 | 3 | `"abc"` | {a:1, b:1, c:1} | **3** ✅ | 5 |
| 6 | 3 | `"abce"` → shrink | {a:1,b:1,c:1,e:1} | 4 ❌ | — |
| 6 | 4 | `"bce"` | {b:1, c:1, e:1} | **3** ✅ | 5 |
| 7 | 4 | `"bceb"` | {b:2, c:1, e:1} | **3** ✅ | 5 |
| 8 | 4 | `"bcebe"` | {b:2, c:1, e:2} | **3** ✅ | 5 |
| 9 | 4 | `"bcebeb"` | {b:3, c:1, e:2} | **3** ✅ | 6 |
| 9 | 5 | shrink 'c' out → `"bebeb"` | {b:3, e:2} | 2 — not yet | — |
| 10 | 5 | `"bebebe"` | {b:3, e:3} | 2 — not k | — |
| 10 | 5 | after adding 'e'... `"cbebebe"` | {c:1,b:3,e:3} | **3** ✅ | **7** 🎉 |

**Answer: `7`** → substring `"cbebebe"`

---

## 💻 Final Code with Comments

```cpp
class Solution {
  public:
    int longestKSubstr(string &s, int k) {

        int low = 0;                        // 🔴 left boundary of sliding window
        int res = 0;                        // 🏆 best answer so far
        unordered_map<char, int> f;         // 📊 frequency map: char → count in window
        int n = s.length();

        for (int high = 0; high < n; high++) {   // 🟢 expand window rightward

            f[s[high]]++;                   // add s[high] into current window

            // 🔴 shrink from left until we have ≤ k distinct characters
            while (f.size() > k) {
                f[s[low]]--;
                if (f[s[low]] == 0) {
                    f.erase(s[low]);        // remove char completely → distinct count drops
                }
                low++;
            }

            // ✅ valid window: update res ONLY when EXACTLY k distinct chars
            if ((int)f.size() == k) {
                res = max(res, high - low + 1);
            }
        }

        // ❌ string never had k distinct chars at any point
        if ((int)f.size() < k) return -1;

        return res;
    }
};
```

### ⚠️ The Critical Bug (Original Code)

The original code updated `res` **unconditionally** after the while loop:

```cpp
// ❌ WRONG — counts windows with < k distinct chars too!
int ans = high - low + 1;
res = max(res, ans);

// ✅ CORRECT — only count EXACTLY k distinct windows
if ((int)f.size() == k) {
    res = max(res, high - low + 1);
}
```

> **"At most k"** → update every iteration
> **"Exactly k"** → update only when `f.size() == k`

This is a **subtle but critical distinction** that changes the entire answer.

---

## ⚡ Complexity Analysis

### Time Complexity — `O(n)`

```
Common misconception:
  outer loop = O(n)
  inner while = O(n) in worst case
  → O(n²) ??  ❌ WRONG

Amortized argument:
  'low' starts at 0, only moves FORWARD, max n steps TOTAL
  across ALL while loop iterations combined.

  Total work = outer O(n) + inner O(n) total = O(n) ✅
```

### Space Complexity — `O(k)`

```
HashMap holds at most k+1 entries at any point
(before the while loop triggers shrinking)

For lowercase English only → O(26) = O(1) constant
General case              → O(k)
```

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n³) | O(n) |
| Optimized BF | O(n²) | O(k) |
| **Sliding Window** ✅ | **O(n)** | **O(k)** |

---

## 🚨 Edge Cases

| Case | Input | Output | Why |
|------|-------|--------|-----|
| k = 0 | `"abc"`, k=0 | `-1` | Window always empty, never valid |
| k > distinct chars | `"ab"`, k=3 | `-1` | String only has 2 distinct, never reaches 3 |
| k = 1 | `"aabba"`, k=1 | `2` | Longest run of one char = "aa" |
| All same char | `"aaaa"`, k=1 | `4` | Entire string is valid |
| All distinct | `"abcde"`, k=2 | `2` | Any 2 adjacent chars |
| Empty string | `""`, k=2 | `-1` | Loop doesn't run, f.size()=0 < k |
| k = n (all chars) | `"abc"`, k=3 | `3` | Entire string is valid |

---

## 🧠 Key Takeaways

**1. 🪟 Sliding Window = Expand + Shrink**
> Always expand with the right pointer, shrink with the left when constraint is violated.
> This pattern solves most *"longest subarray/substring satisfying X"* problems.

**2. 📊 HashMap = Window's Memory**
> `f.size()` = number of distinct chars in current window.
> When a frequency hits 0, erase from map to keep `size()` accurate.

**3. ⚡ Amortized O(n) Despite Nested Loop**
> Two pointers only move **forward**. Total steps = 2n max.
> Nested loop ≠ O(n²) when total inner iterations are bounded by n.

**4. 🎯 "Exactly k" ≠ "At Most k"**
> A tiny `==` vs `<=` difference completely changes the problem.
> Always read the constraint carefully before coding.

---

## 🔗 Related Problems

| Problem | Pattern | Twist |
|---------|---------|-------|
| Longest Substring with At Most K Distinct | Sliding Window | `≤ k` instead of `= k` |
| Longest Substring Without Repeating Characters | Sliding Window | k = all distinct (no repeats) |
| Fruit Into Baskets | Sliding Window | Same problem, k = 2 |
| Subarrays with K Different Integers | Sliding Window | Count subarrays, not length |

---

*Master the sliding window pattern and 30+ problems become easy 🚀*