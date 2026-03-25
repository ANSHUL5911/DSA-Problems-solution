

# 🎯 Problem Understanding

We need to find the **smallest (minimum) sum of any contiguous subarray**.

👉 Example:

```
Input: [3, -4, 2, -3, -1, 7, -5]
Output: -6   // subarray = [-4, 2, -3, -1]
```

---

# 🧠 Core Intuition (Think Like a Pro)

This is a **mirror version of Kadane’s Algorithm**.

💡 Normally:

* Kadane finds **maximum subarray sum**

💡 Here:

* We tweak it to find **minimum subarray sum**

---

## 🔥 Key Idea

At every index, you have 2 choices:

🔷 **Start a new subarray**

```
v1 = a[i]
```

🔷 **Extend the previous subarray**

```
v2 = bestEnding + a[i]
```

👉 Then choose the **minimum**:

```
bestEnding = min(v1, v2)
```

---

## 🎨 Visual Representation

Let’s visualize how the algorithm behaves:

```
Array:   [ 3   -4   2   -3   -1   7   -5 ]
Index:    0    1    2    3     4    5    6
```

We track two things:

🟢 `bestEnding` → minimum sum ending at current index
🔴 `res` → overall minimum

---

### 📊 Step-by-step Table

| i | a[i] | bestEnding | res |
| - | ---- | ---------- | --- |
| 0 | 3    | 3          | 3   |
| 1 | -4   | -4         | -4  |
| 2 | 2    | -2         | -4  |
| 3 | -3   | -5         | -5  |
| 4 | -1   | -6         | -6  |
| 5 | 7    | 1          | -6  |
| 6 | -5   | -5         | -6  |

---

## 🧩 Why This Works

Think of it like this:

🧠 *"If my previous sum is already bad (small/negative), I should continue it to make it even smaller."*

💬 Decision Logic:

* If previous sum helps → extend
* If not → restart from current element

---

# ⚙️ Approach Breakdown

### 🟢 Step 1: Initialization

```cpp
int bestending = a[0];
int res = a[0];
```

---

### 🔁 Step 2: Traverse Array

```cpp
for(int i = 1; i < n; i++)
```

---

### ⚡ Step 3: Decide

```cpp
int v1 = a[i];                   // start new
int v2 = bestending + a[i];     // extend

bestending = min(v1, v2);
```

---

### 🏆 Step 4: Update Result

```cpp
res = min(res, bestending);
```

---

# 🎯 Final Insight (Golden Line)

✨
👉 “At every step, we greedily choose the smallest possible sum ending here.”

---

# ⏱️ Complexity Analysis

### 🕒 Time Complexity

```
O(n)
```

✔ Single pass through array
✔ No nested loops

---

### 🧠 Space Complexity

```
O(1)
```

✔ Only variables used
✔ No extra memory

---

# 🚀 Pattern Recognition (Interview Gold)

This problem belongs to:

🔶 **Kadane’s Algorithm Family**

| Problem Type      | Goal               |
| ----------------- | ------------------ |
| Maximum Subarray  | max sum            |
| Minimum Subarray  | min sum (this one) |
| Circular Subarray | both max + min     |

---

# 💡 Pro Tips (From Experience)

✅ Always remember:

* Replace `max` → `min` to flip the problem
* Works for **negative-heavy arrays**
* Very common in **Google/Microsoft interviews**

---

# 🎉 Final Takeaway

🧠 Think in terms of:

```
"Continue or Restart?"
```

⚡ That’s the entire magic behind this algorithm.

---

