

## 🌟 Problem Statement (Word Search)

You are given a 2D board of characters and a word.
You need to check **if the word exists in the grid** — by moving **horizontally or vertically** to adjacent cells 🧭.
You **cannot reuse a cell** once it’s used in the current path 🚫.

---

## 🧠 Intuition — *What’s the idea behind this code?*

Think of the board as a **maze 🌀**,
and the `word` as a **path** you need to trace through the maze.

We start from each cell that matches the **first character** of the word.
Then, like a detective 🔍, we move in all 4 directions:
→ Right
← Left
↑ Up
↓ Down

At each step:

* If the character matches ✅, we move to the next letter.
* If it doesn’t ❌ or we go out of bounds, we backtrack ⏪.

So essentially, this is a **Depth-First Search (DFS)** + **Backtracking** problem! 🌊

---

## ⚙️ Approach Breakdown

Let’s break it down step by step visually 🔽

---

### 🧩 Step 1 — Initialization

```cpp
m = board.size();
n = board[0].size();
```

We store the dimensions of the board (`m` × `n`)
so we can easily check boundaries later ✅

---

### 🧭 Step 2 — Direction Vectors

```cpp
vector<vector<int>> direction{{1,0}, {-1,0}, {0,1}, {0,-1}};
```

These represent movements:

* ↓ Down → (1, 0)
* ↑ Up → (-1, 0)
* → Right → (0, 1)
* ← Left → (0, -1)

Visual Representation:

```
      ↑ (-1,0)
← (0,-1)   → (0,1)
      ↓ (1,0)
```

---

### 🚀 Step 3 — DFS Function `find(...)`

**Goal:** Try to match the word from the current cell onward.

```cpp
bool find(board, i, j, index, word)
```

#### 🧩 Base Case:

```cpp
if (index == word.length()) return true;
```

If we matched all characters → 🎯 Word found!

#### 🚧 Boundary Checks:

```cpp
if (i<0 || j<0 || i>=m || j>=n || board[i][j]=='$') return false;
```

Stops recursion if we go **out of grid** or revisit a cell 🚫.

#### ❌ Mismatch Check:

```cpp
if (board[i][j] != word[index]) return false;
```

#### ✅ Match Found:

Mark cell as **visited** temporarily:

```cpp
char temp = board[i][j];
board[i][j] = '$'; // visited
```

Then explore all 4 directions recursively 🔄:

```cpp
for (auto& dir : direction)
    if (find(board, i+dir[0], j+dir[1], index+1, word)) return true;
```

If none of the directions work:

* **Backtrack** — restore the cell for future searches:

```cpp
board[i][j] = temp;
```

---

### 🔍 Step 4 — Loop Through Each Cell

```cpp
for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
        if (board[i][j] == word[0] && find(board, i, j, 0, word))
            return true;
```

We check **every starting position** that matches the first character of the word 🏁

---

### ✅ Step 5 — Final Return

If no starting point leads to success → `return false;`

---

## 🧩 Visual Example

### Example:

```
Board:
A B C E
S F C S
A D E E

Word: "ABCCED"
```

🧭 Path Found:

```
A → B → C
        ↓
        C
        ↓
        E
        ↓
        D
```

✅ The function returns **true** 🎉

---

## ⏱️ Time Complexity

🧮 Let’s analyze:

* There are `m * n` cells.
* For each cell, we might explore up to **4 directions** recursively.
* The depth of recursion = `length of the word (L)`.

👉 **Time Complexity = O(m × n × 4^L)**
Because from each cell, we may branch 4 ways.

⚠️ But due to backtracking and pruning (when characters mismatch early),
average runtime is **much faster in practice** 💨

---

## 💾 Space Complexity

We use recursion + board modification:

* Recursion stack depth = O(L)
* No extra space except board (which is reused)

👉 **Space Complexity = O(L)**

---

## 🎯 Summary Table

| Step | Purpose                 | Concept Used | Emoji |
| ---- | ----------------------- | ------------ | ----- |
| 1    | Start from each cell    | Loop         | 🔁    |
| 2    | Explore in 4 directions | DFS          | 🧭    |
| 3    | Avoid revisiting        | Backtracking | 🔒    |
| 4    | Match all letters       | Recursion    | 🧠    |
| 5    | Restore and continue    | Undo step    | ⏪     |

---

## 🖼️ Concept Map (Text Visual)

```
     ┌────────────────────────────┐
     │        exist()             │
     └────────────┬───────────────┘
                  │
                  ▼
          ┌────────────┐
          │  find(i,j) │──► checks boundaries
          └────────────┘
                  │
          ┌───────┴────────┐
          │  match letter?  │
          └───────┬────────┘
                  │yes
                  ▼
          explore 4 directions
                  │
              success?
          ┌───────┴────────┐
          │ true if found  │
          └────────────────┘
```

---

## 🧩 In Simple Words:

> “We try to walk through the board letter by letter.
> If the path matches the word, we win!
> If we hit a dead end, we backtrack and try another direction.” 🧭🌈

---



