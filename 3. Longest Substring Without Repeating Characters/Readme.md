
---

# 🔍 Problem Overview

We want to compute:

> **Length of the longest substring without repeating characters**

Given a string `s`, find the maximum length of a contiguous substring that contains only unique characters.

---

# 1️⃣ Intuition (Plain Language)

### 🎯 What are we trying to achieve?

We need the **largest continuous segment** of the string where **no character appears more than once**.

Example:

```
Input:  "abcabcbb"
Output: 3  ("abc")
```

---

## 💡 Why Two Pointers + Sliding Window?

Instead of checking every substring (which would be O(n²)), we:

* Use two pointers:

  * `low` → start of window
  * `high` → end of window
* Maintain a **window** `[low, high]`
* Expand right (`high++`)
* If duplicate appears → shrink from left (`low++`)

This is called the **Sliding Window Technique**.

### Core Idea:

* Expand window to grow substring
* If constraint breaks (duplicate appears) → shrink until valid again

---

# 2️⃣ Approach (Step-by-Step Code Breakdown)

Here is the given code:

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int high = 0;
        int low = 0;
        int res = INT_MIN;
        int n = s.length();
        unordered_map<char,int> f;

        for (high = 0; high < n; high++) {

            f[s[high]]++;

            int k = high - low + 1;

            while (f.size() < k) {

                f[s[low]]--;

                if (f[s[low]] == 0) {
                    f.erase(s[low]);
                }

                low++;
                k = high - low + 1;
            }

            int len = high - low + 1;
            res = max(res, len);
        }
        return res;
    }
};
```

---

## 🧩 Initialization

```cpp
int high = 0;
int low = 0;
int res = INT_MIN;
int n = s.length();
unordered_map<char,int> f;
```

* `low` → start of window
* `high` → end of window
* `res` → stores maximum length found
* `f` → frequency map of characters in current window
* `n` → string length

---

## 🚀 Window Expansion

```cpp
for (high = 0; high < n; high++)
```

We expand the window from left to right.

Each step:

```cpp
f[s[high]]++;
```

We add the new character to the frequency map.

---

## ❗ Duplicate Detection Logic

```cpp
int k = high - low + 1;

while (f.size() < k)
```

### Why does this work?

* `k = window length`
* `f.size() = number of unique characters`

If:

```
f.size() < k
```

👉 That means some character is repeated.

Because:

```
Window length > unique characters
```

So we shrink the window.

---

## 🔄 Window Contraction

```cpp
f[s[low]]--;

if (f[s[low]] == 0) {
    f.erase(s[low]);
}

low++;
```

We:

* Decrease frequency of left character
* Remove if count becomes 0
* Move `low` forward

This continues until:

```
window becomes valid again (all unique)
```

---

## 📏 Update Result

After fixing duplicates:

```cpp
int len = high - low + 1;
res = max(res, len);
```

We update the maximum valid window length.

---

# 3️⃣ Correctness Sketch

Why does this work?

* The window always maintains:

  ```
  All characters inside it are unique
  ```
* We only shrink when duplicates exist.
* Every character is:

  * Added once (via `high`)
  * Removed once (via `low`)

Thus:

* Every possible valid window is considered.
* The largest valid window is stored in `res`.

✔ Therefore, the algorithm correctly computes the answer.

---

# 4️⃣ Complexity Analysis

## ⏱ Time Complexity: **O(n)**

* `high` moves from `0 → n-1`
* `low` moves from `0 → n-1`
* Each character enters and leaves window at most once

Even though we use a `while`, total operations remain linear.

---

## 🧠 Space Complexity: **O(min(n, charset))**

* In worst case, all characters are unique.
* Map stores at most:

  * `n` characters
  * or 256 for ASCII

So:

```
O(n) worst case
```

---

# 5️⃣ Potential Pitfalls & Fixes

## ⚠ 1. `res = INT_MIN`

Problem:

* If string is empty → loop never runs
* Returns `INT_MIN`

✅ Better:

```cpp
int res = 0;
```

---

## ⚠ 2. Empty String Case

If:

```cpp
s = ""
```

Current code returns `INT_MIN`.

Fix:

```cpp
if (s.empty()) return 0;
```

---

## ⚠ 3. Off-by-One Errors

Be careful with:

```
high - low + 1
```

This correctly computes inclusive window length.

---

## ⚠ 4. Map.size() Trick

Condition:

```cpp
while (f.size() < k)
```

This works but is slightly indirect.

More readable approach:

```cpp
while (f[s[high]] > 1)
```

---

# 6️⃣ Optional Enhancements

## 🔥 Better Implementation (Using Last Seen Index)

Instead of shrinking one-by-one:

```cpp
vector<int> last(256, -1);
int res = 0, start = 0;

for (int i = 0; i < s.size(); i++) {
    if (last[s[i]] >= start) {
        start = last[s[i]] + 1;
    }
    last[s[i]] = i;
    res = max(res, i - start + 1);
}
```

### Why Better?

* No inner while loop
* Direct jump of `low`
* Cleaner logic
* Still O(n)

---

## 🔥 If only ASCII:

Use:

```cpp
int freq[256] = {0};
```

Faster than unordered_map.

---

# 7️⃣ Visual Aids Guidance (For Teaching)

If presenting this:

---

## 📊 Slide 1: Sliding Window Diagram

Draw:

```
a b c a b c b b
^     ^
low   high
```

Use:

* 🟢 Green box → valid window
* 🔴 Red highlight → duplicate detected
* ➡ Arrow showing pointer movement

---

## 📈 Slide 2: Flowchart

```
Start
  ↓
Expand high
  ↓
Duplicate?
  ↓ Yes → Shrink low
  ↓ No
Update res
```

---

## 📘 Slide 3: Example Trace Table

| high | low | Window | Map     | res |
| ---- | --- | ------ | ------- | --- |
| 0    | 0   | a      | {a:1}   | 1   |
| 1    | 0   | ab     | {a,b}   | 2   |
| 2    | 0   | abc    | {a,b,c} | 3   |
| 3    | 1   | bca    | {b,c,a} | 3   |

Use:

* Blue for expansion
* Orange for contraction
* Green for valid window

---

# 8️⃣ Knowledge Extraction (Key Learnings)

### 🧠 Core Concepts

1. Sliding Window = Efficient substring problems
2. Two Pointers reduce O(n²) → O(n)
3. Maintain window invariant:

   ```
   "Window must satisfy condition"
   ```
4. Frequency map helps detect violations
5. Each element should be processed constant times

---

### 🔄 Where Else Can You Apply This?

* Longest substring with at most K distinct characters
* Minimum window substring
* Subarray sum problems
* Longest repeating character replacement
* Binary array longest ones with K flips

---

# 🎯 Final Takeaway

This is a classic:

> "Expand → Fix → Record → Continue"

pattern.

Whenever a problem asks:

* "Longest/Smallest subarray/substring"
* "With condition"
* "Contiguous"

Think:

```
Sliding Window
```

---

