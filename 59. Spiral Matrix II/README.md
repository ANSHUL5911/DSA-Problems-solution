

# 🎯 **Problem: Generate a Spiral Matrix**

We want to build an **n × n matrix** and fill it **in spiral order** like this:

```
1   2   3   4
12  13  14  5
11  16  15  6
10  9   8   7
```

---

# 🧠 **Intuition (Think Like a Senior Developer)**

Imagine you're peeling an onion 🧅 layer by layer.
A spiral matrix works exactly the same way — filling **outer layers first**, then moving inward.

Every layer has **4 moves**:

### ➡️ Left → Right

### ⬇️ Top → Bottom

### ⬅️ Right → Left

### ⬆️ Bottom → Top

And after each move, the **boundaries shrink** because that row/column is already filled.

It's like tightening a square coil 🔄.

---

# 🏗 **Visual Representation of Boundaries**

Let's visualize the matrix with boundaries:

```
┌────────────────────────┐
│   → → → → → → → → → →  │  startingRow
│   ↓                 ↑  │  
│   ↓                 ↑  │  
│   ↓                 ↑  │  
│   ← ← ← ← ← ← ← ← ←   │  endingRow
└────────────────────────┘
 startingCol       endingCol
```

We maintain **four pointers**:

* 🟦 `startingRow`
* 🟩 `endingRow`
* 🟨 `startingCol`
* 🟪 `endingCol`

Each iteration fills **one boundary**.

---



# 🔍 **Detailed Explanation of Each Step**

## 1️⃣ **Left → Right (Top Row)**

✔ Fill the topmost unfilled row
✔ Move from `startingCol` → `endingCol`

```
[ 1  2  3  4 ]
```

Then:

```
startingRow++;
```

---

## 2️⃣ **Top → Bottom (Right Column)**

✔ Fill the rightmost unfilled column
✔ Move from `startingRow` → `endingRow`

```
           ↓
[          5 ]
[          6 ]
[          7 ]
```

Then:

```
endingCol--;
```

---

## 3️⃣ **Right → Left (Bottom Row)**

✔ Fill the bottom row (right to left)

```
[ 10  9  8 ]
```

Then:

```
endingRow--;
```

---

## 4️⃣ **Bottom → Top (Left Column)**

✔ Fill the leftmost column (bottom to top)

```
↑
|
11
|
12
```

Then:

```
startingCol++;
```

---

# 🔁 **Repeat until all numbers (1 → n²) are filled**

---

# 🧠 **Time & Space Complexity**

### ⏱ Time Complexity – **O(n²)**

Because we fill **each cell exactly once**.

### 🧱 Space Complexity – **O(n²)**

For storing the output matrix `ans`.

### 👉 Boundaries shrink each iteration, ensuring efficient traversal without revisits.

---

# 💎 Final Takeaway (Senior Engineer Advice)

✔ Use boundary pointers for spiral problems
✔ Update boundaries progressively
✔ Ensure loop stops after filling all elements
✔ Spiral traversal is a classic interview pattern

This approach is *clean*, *efficient*, and *scalable* — things big MNCs want from their engineers. 🚀

---



