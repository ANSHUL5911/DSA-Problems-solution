

# 🌟 Problem: Maximum Product Subarray

👉 You are given an array and need to find a **contiguous subarray** with the **maximum product**.

---

# 🧠 Intuition (Core Idea)

### 🔥 Key Observation:

Multiplication behaves differently than addition:

* ✅ Positive × Positive → Positive
* ❌ Negative × Positive → Negative
* 💥 Negative × Negative → **Positive (Important!)**

---

### 💡 Why we track BOTH max and min?

Because a **negative number can flip the game**:

```
Example:
nums = [2, 3, -2, 4]

At -2:
max becomes small ❌
BUT min becomes large negative

Later:
negative × negative = HUGE positive ✅
```

👉 So:

* `maxend` → Maximum product ending at current index
* `minend` → Minimum product ending at current index

---

# 🎯 Visual Flow (Step-by-Step)

Let’s take an example:

```
nums = [2, 3, -2, 4]
```

| i | nums[i] | maxend | minend | res |
| - | ------- | ------ | ------ | --- |
| 0 | 2       | 2      | 2      | 2   |
| 1 | 3       | 6      | 3      | 6   |
| 2 | -2      | -2     | -12    | 6   |
| 3 | 4       | 4      | -48    | 6   |

👉 Final Answer = **6**

---

# ⚙️ Approach (Line-by-Line Thinking)

### 🟦 Step 1: Initialization

```cpp
int maxend = nums[0];
int minend = nums[0];
int res = nums[0];
```

📌 Start from first element since subarray must be non-empty.

---

### 🟩 Step 2: Traverse Array

For each element, compute 3 possibilities:

```cpp
int v1 = nums[i];                  // start fresh
int v2 = maxend * nums[i];         // extend max
int v3 = minend * nums[i];         // extend min (important!)
```

---

### 🟨 Step 3: Update max & min

```cpp
maxend = max(v1, max(v2, v3));
minend = min(v1, min(v2, v3));
```

🎯 Why?

* `maxend` → best possible product till now
* `minend` → worst (can become best later!)

---

### 🟥 Step 4: Update Result

```cpp
res = max(res, max(maxend, minend));
```

👉 Technically, `maxend` is enough, but your version is **extra safe** ✔️

---

# 🎨 Intuition Diagram

```
        Current Number
              │
   ┌──────────┼──────────┐
   │          │          │
Start      Extend     Extend
Fresh      maxend     minend
(v1)        (v2)       (v3)
   │          │          │
   └───────Compare───────┘
            │
   maxend (best)
   minend (worst)
```

---

# ⚡ Key Insight (INTERVIEW GOLD 🏆)

👉 The trick is:

> "Track both maximum and minimum because a negative number can turn the smallest product into the largest."

---

# ⏱️ Complexity Analysis

### 🕒 Time Complexity:

```
O(n)
```

* Single pass through array

---

### 🧠 Space Complexity:

```
O(1)
```

* No extra space used (only variables)

---

# 🚀 Pro Tips (Senior Dev Advice)

✅ Always think:

* “Can sign flip change the result?”
* If YES → track min & max both

✅ Common mistake:

* Ignoring negative numbers → ❌ Wrong answer

---

# 🧩 Final Takeaway

✨ This problem is a **twist on Kadane’s Algorithm**:

* Instead of sum → we handle **product + sign flips**

---



