
---

# 🐀 Rat in a Maze — Backtracking Explained (Senior-Level)

---

## 🧩 Problem Intuition (Think Like an Engineer)

Imagine a **rat 🐀** placed at the **top-left corner (0,0)** of a maze:

```
S  1  0
1  1  0
0  1  E
```

* `1` → Open path ✅
* `0` → Blocked ❌
* `S` → Start
* `E` → End

The rat can move in **4 directions**:

```
⬇️ Down (D)
⬅️ Left (L)
➡️ Right (R)
⬆️ Up (U)
```

🎯 **Goal**:
Find **all possible paths** from `S` to `E` **without visiting a cell more than once**.

This is a **classic backtracking problem** because:

* You explore **all possible paths**
* You **undo choices** when you hit a dead end
* You try **every valid combination**

---

## 🧠 Key Insight (Why Backtracking?)

At every cell, the rat has **choices**:

```
        (x,y)
      /   |   |   \
     D    L   R    U
```

* Some choices lead to the destination ✅
* Some lead to dead ends ❌

👉 So we:

1. **Try a move**
2. **Go deeper (recursion)**
3. **Backtrack if it fails**

This is exactly what **DFS + Backtracking** is made for.

---

## 🏗️ High-Level Approach

### ✅ Step 1: Safety Check (`isSafe`)

Before moving, check:

* Inside grid boundaries
* Not already visited
* Cell is open (`1`)

```cpp
bool isSafe(int x, int y, int n,
            vector<vector<int>> visited,
            vector<vector<int>>& maze)
```

📌 This prevents:

* Infinite loops 🔁
* Invalid moves ❌

---

### ✅ Step 2: Recursive Exploration (`solve`)

This function:

* Explores **all paths**
* Builds the path string (`"DRRUL..."`)
* Stores valid paths

#### 🧠 Base Case

```cpp
if(x == n-1 && y == n-1)
```

🎉 Destination reached → store the path!

---

### 🔄 Backtracking Flow (Very Important)

```cpp
visited[x][y] = 1;   // mark visited

// Try all 4 directions
path.push_back('D'); solve(...); path.pop_back();
path.push_back('L'); solve(...); path.pop_back();
path.push_back('R'); solve(...); path.pop_back();
path.push_back('U'); solve(...); path.pop_back();

visited[x][y] = 0;   // unmark (BACKTRACK)
```

📌 **Why unmark visited?**
Because this cell might be part of **another valid path** later.

This is the **core backtracking concept** 🔁

---

## 🎨 Visual Flow of Recursion

```
Start (0,0)
   |
   D
   |
 (1,0)
   |
   R
   |
 (1,1)
   |
   D
   |
 End (2,1) ✅
```

If a move fails:

```
❌ Dead End
⬅️ Backtrack
Try another direction
```

---

## 🧾 Path Representation

We build paths as strings:

```
"D R D R"
↓
"DRDR"
```

Each recursive call **adds one character**
Each backtrack **removes it**

👉 This ensures **correct path tracking**

---

## 📦 Data Structures Used

| Structure                  | Purpose               |
| -------------------------- | --------------------- |
| `vector<vector<int>> maze` | Maze layout           |
| `visited[][]`              | Prevent revisits      |
| `string path`              | Current path          |
| `vector<string> ans`       | Store all valid paths |

---

## 🧮 Time & Space Complexity (Interview Gold ⭐)

### ⏱️ Time Complexity

```
O(4^(n²))
```

🔍 Why?

* Each cell can explore **4 directions**
* In worst case, all cells are open
* Exponential paths possible

📌 This is **expected** for path enumeration problems.

---

### 💾 Space Complexity

```
O(n²)
```

Because:

* `visited` matrix → `n × n`
* Recursion stack → max depth `n²`

---

## 🏆 Why This Solution Is Clean & Professional

✔ Uses **DFS + Backtracking**
✔ Proper **visited tracking**
✔ Clear **direction ordering (D,L,R,U)**
✔ Sorted output (important for platforms like GFG)
✔ Easy to extend (can add diagonals, weights, etc.)

This is **production-quality recursive logic**, not just competitive coding.

---

## 🧠 Key Takeaways (Remember These!)

✨ Backtracking = **Try → Explore → Undo**
✨ Always **mark before recursion** & **unmark after**
✨ Pass `path` by value or undo changes carefully
✨ Safety checks prevent infinite recursion

---


