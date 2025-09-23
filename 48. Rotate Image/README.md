

# 🎯 Problem: Rotate Matrix by 90° Clockwise

We’re asked to rotate an `n x n` matrix **in place**.
Example:

📥 Input:

```
1 2 3
4 5 6
7 8 9
```

📤 Output (rotated 90° clockwise):

```
7 4 1
8 5 2
9 6 3
```

---

# 💡 Intuition

Think about how rotation works:

* **Step 1: Transpose (↘️ along the diagonal)**
  Swap `matrix[i][j]` with `matrix[j][i]`.
  Essentially flipping rows into columns.

* **Step 2: Reverse each row (↔️ left-right flip)**
  After transpose, the matrix looks "mirrored".
  Reversing each row finishes the 90° clockwise rotation.

👉 Two simple transformations = rotation done! 🎉

---

# 🛠️ Approach (with visuals)

### 🔹 Step 1: Transpose

Before transpose:

```
1 2 3
4 5 6
7 8 9
```

After transpose (swap across diagonal):

```
1 4 7
2 5 8
3 6 9
```

---

### 🔹 Step 2: Reverse each row

Row-wise reverse:

```
1 4 7   →   7 4 1
2 5 8   →   8 5 2
3 6 9   →   9 6 3
```

Final Answer ✅:

```
7 4 1
8 5 2
9 6 3
```

---

# 🧮 Complexity Analysis

* **Time Complexity ⏱️:**

  * Transpose = visiting \~ half of matrix → `O(n^2)`
  * Reverse rows = touching every element once → `O(n^2)`
  * Total = `O(n^2)`

* **Space Complexity 💾:**

  * No extra matrix used, only swaps in-place → `O(1)`

⚡ This is **optimal**.

---



# 🎨 Attractive Summary Card

📌 **Rotate 90° Clockwise**

* 🔄 **Step 1:** Transpose (↘️ swap across diagonal)
* ↔️ **Step 2:** Reverse each row

⏱️ Time: **O(n²)**
💾 Space: **O(1)**
✨ In-place, efficient, and clean.

---

