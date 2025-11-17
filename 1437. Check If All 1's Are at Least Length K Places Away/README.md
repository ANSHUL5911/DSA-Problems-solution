



# 🎯 **Problem Summary**

You're given a binary array (only 0 and 1).
You must verify that **all 1s are spaced at least `k` positions apart**.

---

# 💡 **Intuition **

Think of the array as a **road** 🛣️ and every `1` is a **streetlight** 💡.

If streetlights are **too close**, the city violates safety rules.

You must ensure:

> **Between every two consecutive streetlights, there should be at least `k` empty road spaces.**

Visually:

```
1   0   0   0   1
^           ^
light      light
```

If `k = 3` → ✔️ Valid
There are **exactly 3 zeros** between 1s.

But if:

```
1   0   0   1
^       ^
light  light
```

`k = 3` → ❌ Invalid
Only **2 zeros** are there.

---

# 🧠 **Approach**

### ✔️ Step 1 — Track the previous `1`

We maintain a variable:

```
prev = -1
```

This tells us the **index of the last seen 1**.

### ✔️ Step 2 — Walk through the array once

Use a simple for-loop:

```
for i in nums:
    if nums[i] == 1:
        check distance from previous 1
```

### ✔️ Step 3 — When you meet a new `1`

Check:

```
distance = i - prev - 1
```

📌 If `distance < k` → ❌ FAIL
📌 Else → ✔️ Continue safely

### ✔️ Step 4 — Update previous index & move forward

---

# 🎨 **Visual Diagram (Colorful Explanation)**

```
Index:    0   1   2   3   4   5   6
Array:    1   0   0   0   0   1   0
           🔥               🔥
          prev             curr

Distance = (5 - 0 - 1) = 4
k = 3

✔️ 4 >= 3 → Valid
```

**Legend**
🔥 = position of `1`
🟦 = zero space
📏 = distance being measured

---

# ⭐ Code (Final Polished Version)

```cpp
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;  // last index of 1

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (prev != -1 && i - prev - 1 < k) {
                    return false;  // gap too small ❌
                }
                prev = i;  // update previous 1 index ✔️
            }
        }
        return true; // all gaps valid ✔️
    }
};
```

---

# ⚙️ **Time & Space Complexity**

### ⏱️ **Time Complexity → O(n)**

We scan the array **only once**.
Like reading a book from first page → last page.

### 📦 **Space Complexity → O(1)**

No extra data structures used.
Just one variable → `prev`.

Super efficient. 🚀

---

# 🏆 Final Summary (Color-Coded)

| Concept      | Explanation                                     |
| ------------ | ----------------------------------------------- |
| 🧠 Intuition | Check spacing between 1s like streetlights      |
| 🔧 Approach  | Track previous 1 → measure gap → compare with k |
| 📏 Condition | `i - prev - 1 >= k`                             |
| ⏱️ Time      | O(n)                                            |
| 📦 Space     | O(1)                                            |
| ✔️ Result    | Simple, clean, highly efficient solution        |

---




