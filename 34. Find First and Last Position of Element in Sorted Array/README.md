

# 🧠 Intuition — “Finding both edges of the target”

Imagine the sorted array as a **line of numbers** 📏:

```
[1, 2, 3, 3, 3, 4, 5]
           ↑     ↑
         First  Last
```

Our goal 🎯 is to find **both arrows** —

* The **first position** of the target (`3`)
* The **last position** of the target (`3`)

But we don’t want to scan the entire array (that’d be linear 👎).
Instead, we’ll use **Binary Search** 🧩 twice —
each time “narrowing down” our search range logarithmically.

---

# ⚙️ Approach — Step-by-Step with Visualization

Let’s break it into two phases 🔍

---

## 🔹 Phase 1: Find the **first occurrence**

We use **binary search** to go left whenever we find the target.

### 🧭 Logic Flow:

1. Start with the entire range `start = 0, end = n - 1`.
2. Find mid: `mid = start + (end - start) / 2`
3. Three cases:

   * If `nums[mid] == target` → ✅ store this as a **potential first position**,
     but still go **left (end = mid - 1)** to check if there’s another one.
   * If `nums[mid] < target` → move **right**.
   * If `nums[mid] > target` → move **left**.

This ensures we end up with the **leftmost index** of the target.

---

### 🧩 Visual Example

```
nums = [1, 2, 3, 3, 3, 4, 5], target = 3

Iteration 1 → mid = 3 (nums[mid]=3) → go LEFT
Iteration 2 → mid = 1 (nums[mid]=2) → go RIGHT
Iteration 3 → mid = 2 (nums[mid]=3) → go LEFT
⏩ Found leftmost = index 2
```

🟢 **Left boundary found: 2**

---

## 🔹 Phase 2: Find the **last occurrence**

Same binary search, but this time go **right** whenever you find the target.

### 🧭 Logic Flow:

1. Start again with `start = 0, end = n - 1`
2. If `nums[mid] == target` → ✅ store mid as **potential last position**,
   but still go **right (start = mid + 1)** to check for more.
3. Move left or right as usual otherwise.

---

### 🧩 Visual Example

```
nums = [1, 2, 3, 3, 3, 4, 5], target = 3

Iteration 1 → mid = 3 (nums[mid]=3) → go RIGHT
Iteration 2 → mid = 5 (nums[mid]=4) → go LEFT
Iteration 3 → mid = 4 (nums[mid]=3) → go RIGHT
⏩ Found rightmost = index 4
```

🟣 **Right boundary found: 4**

---

# 💎 Final Result

✅ `result = [2, 4]`

Meaning the target `3` appears from index **2 → 4** (inclusive).

---

# ⚡ Complexity Analysis

| Aspect       | Explanation                                                         | Complexity   |
| :----------- | :------------------------------------------------------------------ | :----------- |
| **Time** ⏱   | Each binary search takes `O(log n)` and we run it twice             | **O(log n)** |
| **Space** 💾 | We only use a few extra variables (`start`, `end`, `mid`, `result`) | **O(1)**     |

---

# 🧰 Summary of Key Ideas

| Concept                | Insight                                                     |
| :--------------------- | :---------------------------------------------------------- |
| 🎯 Two binary searches | One for the first index, one for the last                   |
| 🧩 Edge movement       | Go left (for first), go right (for last) after a match      |
| 🧠 Boundary checks     | Use `start <= end` not `start < end`                        |
| 🛡 Prevent overflow    | `mid = start + (end - start) / 2`                           |
| 🧮 Handles edge cases  | Empty array, single element, not found → returns `[-1, -1]` |

---

# 🪄 Visual Summary — Binary Search in Action


![Find First and Last Position Visualization](https://i.postimg.cc/zBy7Gsn5/Chat-GPT-Image-Oct-8-2025-08-18-35-PM.png)




---

# 🧩 In Short

> “We run binary search twice — once to catch the first fish 🐟 (leftmost target),
> once to catch the last fish 🐠 (rightmost target).
> Together, they form the exact interval where the target swims.” 🌊

---




