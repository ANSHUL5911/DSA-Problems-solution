# 🌀 Spiral Matrix Traversal

Imagine you are tracing the matrix like peeling layers of an onion 🧅, moving in a **spiral** direction:

1. **Left ➡ Right (Top row)**
2. **Top ⬇ Bottom (Right column)**
3. **Right ➡ Left (Bottom row)**
4. **Bottom ⬆ Top (Left column)**

Then shrink the boundary and repeat until all elements are visited ✅.

---

## 💡 Intuition

* A **matrix** is like a chessboard 🏁.
* Spiral traversal means:

  * Walk along the **top wall**,
  * Slide down the **right wall**,
  * Walk back along the **bottom wall**,
  * Climb up the **left wall**,
  * Then **shrink the walls inward** and repeat 🔄.

Think of a robot 🤖 walking around the edges, then stepping inside one layer after finishing the boundary.

---

## 🧭 Approach (Step by Step)

Let’s take a **4×4 matrix**:

```
1   2   3   4
5   6   7   8
9  10  11  12
13 14  15  16
```

We define **boundaries**:

* `startingRow`, `endingRow`
* `startingCol`, `endingCol`

---

### 🔹 Step 1: Traverse **Top Row** (→)

Pick: `1 2 3 4` ✅
Now shrink `startingRow++` ⬇

---

### 🔹 Step 2: Traverse **Right Column** (↓)

Pick: `8 12 16` ✅
Now shrink `endingCol--` ⬅

---

### 🔹 Step 3: Traverse **Bottom Row** (←)

Pick: `15 14 13` ✅
Now shrink `endingRow--` ⬆

---

### 🔹 Step 4: Traverse **Left Column** (↑)

Pick: `9 5` ✅
Now shrink `startingCol++` ➡

---

🔁 Repeat inside the new smaller box:

```
6   7
10  11
```

Resulting spiral order:
`1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10`

---

## ⚙️ Code Flow (Visualized)

```
while (count < total):
    ➡ Traverse top row
    ⬇ Traverse right col
    ⬅ Traverse bottom row
    ⬆ Traverse left col
    🔄 Shrink boundaries
```

🟩 **Visited cells** get pushed into result vector.
🟥 **Boundaries shrink** after each direction.

---

## 📊 Complexity Analysis

* **Time Complexity** ⏱️

  * Every element is visited exactly **once**.
  * `O(m × n)` where `m = rows`, `n = cols`.

* **Space Complexity** 📦

  * Output vector stores all `m × n` elements.
  * Extra space = `O(1)` (no additional data structures).

So overall:
👉 **Optimal solution** 💯.

---

## ✨ Final Takeaways

* Spiral traversal = **Layer by layer peeling** 🧅.
* Boundaries help avoid **re-visiting** elements.
* Use `count < total` check ✅ to prevent infinite loops.

---
