

# 🎯 Problem: Search in 2D Matrix

We’re given a **2D matrix** where:

* Each row is sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.

This means 👉 the entire matrix can be imagined as **one sorted 1D array**.

Our goal: Find whether `target` exists in this matrix. ✅

---

# 💡 Intuition

Imagine flattening the 2D matrix into a **1D sorted array**.
For example:

```
Matrix:
[ 1   3   5   7 ]
[ 10  11  16  20 ]
[ 23  30  34  60 ]

Flattened:
[ 1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60 ]
```

👉 Now the problem is just a **Binary Search** on this sorted list.
But instead of actually flattening it (which costs extra space), we **simulate the mapping**:

* Index `mid` in the 1D array maps to:

  * **Row = mid / col**
  * **Col = mid % col**

So we can directly access `matrix[row][col]` without extra memory. ⚡

---

# 🛠️ Approach (Step by Step with Graphics)

1️⃣ **Define boundaries**:

* `start = 0`, `end = row * col - 1`

📐 Example: If matrix has 3x4 = 12 elements → `end = 11`

---

2️⃣ **Binary Search loop**:

```
while (start <= end):
    mid = (start + end) / 2
    element = matrix[mid / col][mid % col]
```

📊 Visual:

```
start → mid → end
   |-----|-----|
```

---

3️⃣ **Compare**:

* If `element == target` → 🎉 found! return true
* If `element < target` → move right (`start = mid + 1`)
* Else → move left (`end = mid - 1`)

---

4️⃣ **If loop ends** → target doesn’t exist → return false. ❌

---

# ⏱️ Complexity Analysis

* **Time Complexity**:
  Binary Search over `row * col` elements → `O(log(row * col))`
  Much faster than linear search. ⚡

* **Space Complexity**:
  `O(1)` → No extra data structures, only variables.

---

# 🎨 Attractive Representation

```
Matrix (2D)
   ↓ flatten mapping
[ 1  3  5  7 ]
[10 11 16 20 ]
[23 30 34 60 ]

   ↓ simulate as 1D
[ 1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60 ]

Binary Search 🔍
 ┌───────────────┐
 | start  mid end|
 └───────────────┘
```

