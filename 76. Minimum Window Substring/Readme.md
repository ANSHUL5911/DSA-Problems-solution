
---

# 🪟 Minimum Window Substring — Sliding Window Deep Dive

This problem is a classic **sliding window algorithm** frequently discussed in interviews at companies like **Google** and **Microsoft**.

The challenge is to efficiently find the **smallest substring of `s` containing all characters of `t`**.

---

# 📌 Problem Statement

Given two strings:

```
s → source string
t → target string
```

Find the **minimum window in `s` that contains every character in `t` (including frequency).**

### Example

```
s = "ADOBECODEBANC"
t = "ABC"
```

Answer:

```
"BANC"
```

Because `"BANC"` is the **smallest substring containing A, B, and C**.

---

# 🎯 Key Idea — Sliding Window

Instead of checking **every possible substring** (which would take **O(N²)** time), we use a **dynamic window** that slides across the string.

Think of the window like this:

```
A D O B E C O D E B A N C
^         ^
low       high
```

Two main operations occur:

🔵 **Expand window → move `high`**
🟢 **Shrink window → move `low`**

We expand until the window contains **all required characters**, then shrink it to make the window **as small as possible**.

---

# 🧑‍💻 Original Approach (Using `sahi_hai_kya()`)

Your original solution checked whether the window was valid by scanning **all ASCII characters**.

### Core idea

Two arrays track frequencies:

```
needed[256] → required frequency
have[256]   → frequency inside window
```

You used a helper function:

```
sahi_hai_kya()
```

to verify if the window satisfies all requirements.

### Original Code

```cpp
class Solution {
public:
    bool sahi_hai_kya(vector<int>& needed, vector<int>& have) {
        for (int i = 0; i < 256; i++) {
            if (have[i] < needed[i]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> needed(256, 0);
        vector<int> have(256, 0);

        int low = 0;
        int res = INT_MAX;
        int start = 0;

        for (int i = 0; i < t.length(); i++) {
            needed[(unsigned char)t[i]]++;
        }

        for (int high = 0; high < s.length(); high++) {

            have[(unsigned char)s[high]]++;

            while (sahi_hai_kya(needed, have)) {

                int len = high - low + 1;

                if (res > len) {
                    res = len;
                    start = low;
                }

                have[(unsigned char)s[low]]--;
                low++;
            }
        }

        if (res == INT_MAX) return "";
        return s.substr(start, res);
    }
};
```

---

# 🧠 Intuition Behind Your Approach

Your algorithm works like this:

```
Expand window
      ↓
Update character frequency
      ↓
Check if window contains all required characters
      ↓
If yes → shrink window
      ↓
Update smallest window
```

Visualization:

```
ADOBECODEBANC
^^^^^^
first valid window
```

Then shrinking:

```
DOBEC
^^^^^
```

Eventually we find:

```
BANC
^^^^
```

---

# ⚠️ Performance Limitation

The issue lies in this function:

```
sahi_hai_kya()
```

It loops through:

```
256 ASCII characters
```

every time we check window validity.

### Time Complexity

```
O(N × 256)
```

Even though **256 is constant**, it still adds unnecessary work.

---

# ⚡ Optimized Approach (Using `formed` Counter)

Instead of scanning the entire frequency array, we track **how many characters from `t` are already satisfied**.

We introduce two variables:

```
required → total characters needed
formed   → characters currently satisfied
```

When:

```
formed == required
```

the window is **valid**.

This eliminates the need to scan all 256 characters.

---

# 🚀 Optimized Code (Your Version)

Below is **your optimized implementation**:

```cpp
class Solution {
public:

    string minWindow(string s, string t) {
        vector<int> needed(256, 0);
        vector<int> have(256, 0);

        int low = 0;
        int start = 0;
        int res = INT_MAX;

        int formed = 0;
        int required = t.length();

        for (int i = 0; i < t.length(); i++) {
            needed[(unsigned char)t[i]]++;
        }

        for (int high = 0; high < s.length(); high++) {

            have[(unsigned char)s[high]]++;

            if (have[(unsigned char)s[high]] <= needed[(unsigned char)s[high]]) {
                formed++;
            }

            while (formed == required) {

                int len = high - low + 1;

                if (res > len) {
                    res = len;
                    start = low;
                }

                have[(unsigned char)s[low]]--;

                if (have[(unsigned char)s[low]] < needed[(unsigned char)s[low]]) {
                    formed--;
                }

                low++;
            }
        }

        if (res == INT_MAX) return "";

        return s.substr(start, res);
    }
};
```

---

# 🔍 Key Optimization Logic

When expanding the window:

```
if (have[c] <= needed[c])
    formed++
```

Meaning:

```
this character contributes to satisfying t
```

When shrinking the window:

```
if (have[leftChar] < needed[leftChar])
    formed--
```

Meaning:

```
window lost a required character
```

---

# 📊 Comparison — Original vs Optimized

| Feature           | Original Code        | Optimized Code       |
| ----------------- | -------------------- | -------------------- |
| Window validation | `sahi_hai_kya()`     | `formed == required` |
| Array scanning    | 256 checks each time | No scanning          |
| Time complexity   | O(N × 256)           | O(N)                 |
| Efficiency        | Moderate             | Optimal              |

---

# 🪟 Window Visualization

```
s = ADOBECODEBANC
t = ABC
```

Step 1 — expand:

```
ADOBEC
^^^^^^
(valid window)
```

Step 2 — shrink:

```
DOBEC
 ^^^^
```

Step 3 — smallest window:

```
BANC
^^^^
```

Result:

```
"BANC"
```

---

# ⏱ Complexity Analysis

### Original Code

Time:

```
O(N × 256)
```

Space:

```
O(256)
```

---

### Optimized Code

Time:

```
O(N)
```

Because both pointers move only forward.

```
low → N moves
high → N moves
```

Total:

```
O(2N) ≈ O(N)
```

Space:

```
O(256)
```

---

# 🧠 Sliding Window Pattern

Most substring problems follow this structure:

```
for(high pointer)
    expand window
    update frequency

    while(window valid)
        update answer
        shrink window
```

This pattern appears in many problems such as:

• Longest Repeating Character Replacement
• Fruit Into Baskets
• Max Consecutive Ones III
• Minimum Window Substring

---

# 🏆 Final Takeaway

Your original solution already used the **correct sliding window intuition**.

The optimization simply **replaces repeated scanning with a smart counter (`formed`)**, improving the complexity from:

```
O(N × 256)
```

to

```
O(N)
```

This kind of optimization is crucial when working with **large-scale systems**, like those at **Google** or **Microsoft**.

---

✅ **Engineer Tip**

Whenever you see a substring problem, ask yourself:

```
1️⃣ When does the window become valid?
2️⃣ When should it shrink?
3️⃣ What variable can track validity efficiently?
```

If you answer these three questions, most sliding window problems become straightforward.

---


