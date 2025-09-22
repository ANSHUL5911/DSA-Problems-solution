

# 🌊 Wave Print Traversal of a Matrix

Imagine you have a **matrix (2D array)** — think of it like an Excel sheet 📑.
Now, instead of reading row by row like normal, you read it in a **wave pattern**:

⬇️ Top to bottom on the **first column**,
⬆️ Bottom to top on the **second column**,
⬇️ Top to bottom on the **third column**,
⬆️ Bottom to top on the **fourth column**, and so on…

Basically:
🔵 Even columns → **go down**
🟢 Odd columns → **go up**

---

## 🎯 Intuition

💡 Imagine a person walking column by column:

* In **column 0**, they walk 🟦 **downwards** from top to bottom.
* In **column 1**, they switch direction 🔄 and walk upwards ⬆️.
* In **column 2**, again downwards ⬇️.
* And this keeps repeating…

👉 This zigzag/wave movement ensures **all elements are covered once**, but in a wavy sequence 🌊.

---

## 🛠 Approach (Step by Step)

1. **Initialize** an empty list `ans` ✅ to store the result.
2. Loop through each column `col` (0 → mCols - 1).

   * If `col` is **even (col % 2 == 0)** → Traverse **Top → Bottom** ⬇️.
   * If `col` is **odd (col % 2 == 1)** → Traverse **Bottom → Top** ⬆️.
3. Append each element into `ans`.
4. Finally, return `ans`.

---

## 🔍 Example Visualization

Say our matrix is:

```
1   2   3
4   5   6
7   8   9
```

🌀 Wave print = `[1, 4, 7, 8, 5, 2, 3, 6, 9]`

### Visual Walkthrough 🧑‍🏫

* Col 0 → `1 → 4 → 7`
* Col 1 → `8 → 5 → 2`
* Col 2 → `3 → 6 → 9`

✅ That’s the wave 🌊!

---

## ⚡ Complexity Analysis

* **Time Complexity** ⏱:

  * We touch **each element exactly once** → `O(nRows * mCols)`
* **Space Complexity** 💾:

  * Output array `ans` stores all elements → `O(nRows * mCols)`
  * No extra memory besides that → efficient ✅

---

## 📊 Summary with Icons

* 📥 Input: Matrix (nRows × mCols)
* 🌊 Traversal: Zigzag column-wise
* ⏱ Time: `O(N*M)`
* 💾 Space: `O(N*M)` (output only)
* 🔥 Usage: Printing matrix in fancy order, UI grids, animations

---

✨ So in short:
👉 **We’re reading the matrix column by column, alternating between downward and upward traversal — like a snake 🐍 moving through grass but vertically.**


