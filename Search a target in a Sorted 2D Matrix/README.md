

# 🎯 Problem: Search a target in a **Sorted 2D Matrix**

We’re given a matrix where:

* Each **row** is sorted in ascending order.
* Each **column** is also sorted in ascending order.

Example:

```
Matrix:
[ 1   4   7   11 ]
[ 2   5   8   12 ]
[ 3   6   9   16 ]
[10  13  14   17 ]
```

We need to **check if a target exists** in this matrix ✅❌.

---

# 🧠 Intuition (Think Smart, Not Hard!)

👉 Notice:

* If you start at the **top-right corner** (`matrix[0][col-1]`):

  * Everything **to the left** is **smaller** (⬅️).
  * Everything **below** is **larger** (⬇️).

So, at each step:

* If the element is **greater** than the target → move **left** ⬅️.
* If the element is **smaller** than the target → move **down** ⬇️.

This way, we **eliminate one row or column each step** without searching the whole matrix. 🎯

---

# 🛠️ Approach (Step-by-Step)

### 🔍 Starting Point:

* `rowIndex = 0` (top row)
* `colIndex = col-1` (last column = top-right element)

### ⏩ Steps:

1. Compare `matrix[rowIndex][colIndex]` with `target`.

   * ✅ If equal → **Found! Return true**.
   * 🔽 If element < target → Move **down** (`rowIndex++`).
   * ⬅️ If element > target → Move **left** (`colIndex--`).

2. Keep going until:

   * You go **out of bounds** (target not found).

---

# 🎨 Visualization

Imagine the matrix as a grid ⬛⬜, and we move step by step:

```
Start: Top-Right 🟩
↓ if element < target
← if element > target
🎯 if element == target
```

Example: Searching for **9** in the matrix:

```
[ 1   4   7   11 ]
[ 2   5   8   12 ]
[ 3   6   9🎯  16 ]
[10  13  14   17 ]
```

Path taken:
👉 11 (too big → left)
👉 7 (too small → down)
👉 8 (too small → down)
👉 9 ✅ Found!

---

# ⏱️ Complexity Analysis

* **Time Complexity:**
  Each step eliminates **1 row OR 1 column**.
  → At most `row + col` steps.
  → **O(m + n)**, where `m = rows`, `n = cols`.

* **Space Complexity:**
  No extra storage used.
  → **O(1)**.

⚡ Very efficient compared to brute-force **O(m·n)** search.

---

# 🌟 Key Takeaways

✅ Smart starting point (top-right or bottom-left) makes life easier.
✅ Each step **cuts down the search space**.
✅ One of the **best tricks** in matrix search problems.

---

📌 **Summary with Emojis:**

* Start ➡️ Top-right corner
* Compare 🎯
* Move ⬇️ (if smaller) or ⬅️ (if bigger)
* Complexity = **O(m+n)** ⏱️


