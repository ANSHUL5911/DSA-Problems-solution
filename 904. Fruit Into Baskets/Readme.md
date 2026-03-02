
---

# 🧺 Problem Understanding — “Fruit Into Baskets”

You’re given an array `fruits`, where:

* Each number represents a fruit type.
* You have **only 2 baskets**.
* Each basket can contain **only one type of fruit**, but unlimited quantity.
* You must pick fruits from a **contiguous subarray**.

👉 Goal: Find the **maximum number of fruits** you can collect.

In simpler terms:

> 🔎 Find the **longest contiguous subarray with at most 2 distinct numbers.**

---

# 🧠 Intuition Behind the Algorithm

This is a **variable-size sliding window** problem.

We maintain:

* A window `[low ... high]`
* A map to track fruit counts inside the window
* Expand window → if valid, keep going
* If invalid (>2 types), shrink window from left

Think of it like this:

```
Window grows ➡️ ➡️ ➡️
If > 2 fruit types ❌
Shrink from left ⬅️ until valid again
```

The key idea:

> Maintain a window that always contains **at most 2 distinct fruit types**.

The moment it exceeds 2:

* Move `low` forward
* Reduce counts
* Remove fruit type if count becomes 0

This ensures correctness while maintaining efficiency.

---

# 🔍 Step-by-Step Approach

### 1️⃣ Initialization

```cpp
int low = 0;
int high = 0;
unordered_map<int, int> f;
int res = INT_MIN;
int n = fruits.size();
```

* `low` → left boundary
* `high` → right boundary
* `f` → frequency map of fruit types in window
* `res` → stores maximum length
* `n` → array size

---

### 2️⃣ Expand the Window

```cpp
for (high = 0; high < n; high++) {
    f[fruits[high]]++;
```

We include `fruits[high]` in the window.

Example:

```
[1,2,1]
 low     high
```

Map:

```
{1:2, 2:1}
```

---

### 3️⃣ Check Constraint: At Most 2 Types

```cpp
while (f.size() > 2)
```

If the window contains more than 2 fruit types:

```
[1,2,3]
 ^     ^
low   high
```

Map:

```
{1:1, 2:1, 3:1} → ❌ size = 3
```

We shrink from left:

```cpp
f[fruits[low]]--;
if (f[fruits[low]] == 0) {
    f.erase(fruits[low]);
}
low++;
```

This continues until:

```
Window valid again (size <= 2)
```

---

### 4️⃣ Update Result

```cpp
int len = high - low + 1;
res = max(res, len);
```

We compute the current window size and update the maximum.

---

### 5️⃣ Final Edge Case Handling

```cpp
if (res == INT_MIN) {
    return 0;
}
return res;
```

This handles the empty array case.

---

# 🧩 Why This Works (Correctness Reasoning)

### Invariant Maintained:

At every iteration:

```
Window always contains ≤ 2 distinct fruit types
```

Why it's correct:

* We explore all possible valid windows.
* We never skip any valid subarray.
* We shrink only when constraint is violated.
* We always record maximum valid window.

Because each element is:

* Added once (when high moves)
* Removed at most once (when low moves)

We guarantee linear processing.

---

# ⏱ Time and Space Complexity

### ⏱ Time Complexity: O(n)

Why?

* `high` moves from 0 → n-1
* `low` also moves from 0 → n-1
* Each element enters and leaves window at most once

So total operations ≈ 2n → **O(n)**

---

### 🧠 Space Complexity: O(1)

Important insight:

Although we use `unordered_map`, it stores **at most 3 entries temporarily**, and typically at most 2.

So:

```
Space = O(1)
```

Constant space relative to input size.

---

# 🧪 Edge Cases to Consider

### 1️⃣ Empty Array

```
[]
→ returns 0
```

### 2️⃣ Single Element

```
[5]
→ returns 1
```

### 3️⃣ All Same Fruits

```
[2,2,2,2]
→ returns 4
```

### 4️⃣ Exactly Two Types Entire Array

```
[1,2,1,2,1]
→ returns 5
```

### 5️⃣ More Than Two Types

```
[1,2,3,2,2]
→ longest = 4 ([2,3,2,2])
```

---

# 🧱 Code Structure Summary

```
Initialize pointers + map
For each high:
    Add fruit to map
    While map.size() > 2:
        Remove fruit at low
        Move low forward
    Update max length
Return result
```

This is a textbook **“Longest Subarray with At Most K Distinct Elements”** pattern where K = 2.

---

# 🎯 Visual Sliding Window Example

Example:

```
fruits = [1,2,1,3,4]
```

Step progression:

```
[1]               size=1
[1,2]             size=2
[1,2,1]           size=3 ✅
[1,2,1,3]         size=3 types ❌ shrink
   [2,1,3]        size=3 types ❌ shrink
      [1,3]       size=2 ✅
```

Max length found = 3

---

# 🧠 Pattern Recognition Tip

Whenever you see:

* “Longest subarray”
* “At most K distinct elements”
* “Contiguous”
* “Maximize length”

👉 Immediately think:

```
Sliding Window + HashMap
```

---

# 🚀 Final Takeaway

This solution:

* Uses sliding window to maintain a valid range
* Uses hash map to track distinct fruit types
* Ensures O(n) time
* Maintains constant space
* Cleanly handles all edge cases

It’s efficient, elegant, and production-ready.

---


