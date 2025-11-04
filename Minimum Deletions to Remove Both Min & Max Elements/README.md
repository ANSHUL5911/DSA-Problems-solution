

## 🎯 Problem: *Minimum Deletions to Remove Both Min & Max Elements*

You’re given an array `nums`.
In one operation, you can **delete one element** from either the **front** or the **back**.
You need to find the **minimum number of deletions** required to remove **both** the smallest and largest elements.

---

## 💡 Intuition — Think Like This 👇

Imagine your array like a **queue** (📥 ... 📤):

```
[ 2, 10, 7, 5, 4, 1, 8, 6 ]
   ↑           ↑
  max=10      min=1
```

You can remove elements in **three ways**:

| Option             | 🧭 Description                                         | Example                                                               | Deletions |
| ------------------ | ------------------------------------------------------ | --------------------------------------------------------------------- | --------- |
| **1️⃣ Front only** | Keep deleting from start until both min & max are gone | Remove `[2,10,7,5,4,1]`                                               | 6         |
| **2️⃣ Back only**  | Delete from end until both min & max are gone          | Remove `[8,6,1,4,5,7,10,2]` (reverse order)                           | 3         |
| **3️⃣ Mixed**      | Remove one from front (min or max) and other from back | Remove front up to `max` (2 elements) + back up to `min` (3 elements) | 5         |

So, the **answer = minimum of (front-only, back-only, mixed)** ✅

---

## ⚙️ Approach (Step-by-Step Breakdown)

### 🧩 Step 1: Find Positions of `min` & `max`

We loop once to find:

```cpp
minVal, minValIn
maxVal, maxValIn
```

✅ Time → `O(n)`
✅ Space → `O(1)`

---

### 🧩 Step 2: Consider All Deletion Scenarios

We normalize the indices so:

```cpp
if (minValIn > maxValIn)
    swap(minValIn, maxValIn);
```

Then compute:

| Case      | Formula                           | Meaning                              |
| --------- | --------------------------------- | ------------------------------------ |
| 🟩 Case 1 | `maxValIn + 1`                    | Delete all from **front** till `max` |
| 🟦 Case 2 | `n - minValIn`                    | Delete all from **back** till `min`  |
| 🟨 Case 3 | `(minValIn + 1) + (n - maxValIn)` | Delete both sides (split deletion)   |

Push these into a vector and choose:

```cpp
return *min_element(arr.begin(), arr.end());
```

---

## 🧠 Visualization of Logic

```
Index:  0   1   2   3   4   5   6   7
Array: [2, 10, 7, 5, 4, 1, 8, 6]
         ↑               ↑
       max=10           min=1
```

### 🟢 Case 1 (Front only)

```
🧹 Remove → [2, 10, 7, 5, 4, 1]  → 6 deletions
```

### 🔵 Case 2 (Back only)

```
🧹 Remove → [8, 6, 1]  → 3 deletions
```

### 🟡 Case 3 (Split)

```
🧹 Remove → [2, 10] (front)
🧹 Remove → [8, 6] (back)
Total = 2 + 2 = 4 deletions
```

✅ Minimum = **3 deletions**

---

## 🧮 Complexity Analysis

| Type                 | Description                                            | Value  |
| -------------------- | ------------------------------------------------------ | ------ |
| **Time Complexity**  | One traversal for min/max + constant-time calculations | `O(n)` |
| **Space Complexity** | Using only a few variables + small vector              | `O(1)` |

---

## 💬 Senior Dev Insights 🧑‍💻✨

> 🔹 Always visualize **array operations** as two pointers — one at start, one at end.
> 🔹 When both min & max must go, try all 3 combinations (front, back, split).
> 🔹 Don’t overcomplicate with extra conditions — think **"distance to edges"** instead.
> 🔹 Test with edge cases like:
>
> * All elements same
> * Min/Max at same index
> * Array of size 1 or 2

---

## 🖼️ Summary Diagram (Conceptual Flow)

```
 ┌─────────────────────────────┐
 │ Find min & max + positions  │
 └──────────────┬──────────────┘
                │
        ┌───────▼────────┐
        │ Compute 3 ways │
        └───────┬────────┘
                │
        ┌───────▼────────┐
        │ Take minimum    │
        └───────┬────────┘
                │
        ┌───────▼────────┐
        │ Return answer ✅│
        └────────────────┘
```

---



## 🌈 Key Takeaways

✅ Always consider **edge-based strategies** for array problems.
✅ Visualizing the array helps you reason out deletion counts easily.
✅ Keep your solution **simple**, **readable**, and **mathematically sound**.

---



