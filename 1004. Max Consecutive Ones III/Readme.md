
---

# 1. Intuition 🧠

### Problem Idea

You are given a binary array `nums` and an integer `k`.
You can **flip at most `k` zeros to 1s**.

Goal:
Find the **maximum length subarray that can become all 1s after flipping ≤ k zeros**.

---

### Why Sliding Window Works 🔁

Instead of checking **all possible subarrays (O(n²))**, we maintain a **dynamic window** `[low, high]` that always satisfies:

```
number_of_zeros_in_window ≤ k
```

This is our **main invariant**.

If the window contains **too many zeros**, we **shrink it from the left** until it becomes valid again.

---

### Window Evolution Example

Example:

```
nums = [1 1 1 0 0 0 1 1 1 1]
k = 2
```

We expand the window using `high`.

---

#### Step 1

```
Window: [1 1 1]
low = 0, high = 2
zeros = 0
```

Valid ✔

---

#### Step 2

Add another element:

```
Window: [1 1 1 0]
zeros = 1
```

Still valid ✔

---

#### Step 3

Add more:

```
Window: [1 1 1 0 0]
zeros = 2
```

Still valid ✔

---

#### Step 4

Add another zero:

```
Window: [1 1 1 0 0 0]
zeros = 3
```

Now:

```
zeros > k
```

Window becomes **invalid** ❌

So we **shrink from left**:

```
low moves forward until zeros ≤ k
```

---

### Visual Sliding Window

```
Initial
[1 1 1 0 0]
 L       H
zeros = 2

Add new element
[1 1 1 0 0 0]
 L         H
zeros = 3 (invalid)

Shrink window
   [1 1 0 0 0]
    L       H
zeros = 2 (valid again)
```

This ensures we **always keep the largest valid window**.

---

# 2. Step-by-Step Approach ⚙️

### Step 1 — Initialize variables

```
low = start of window
high = end of window
zeros = number of zeros in window
res = maximum window length
```

---

### Step 2 — Expand the window

Loop through array with `high`.

```
for each element:
    include nums[high] in window
```

---

### Step 3 — Track zeros

If element is zero:

```
zeros++
```

---

### Step 4 — Shrink when constraint breaks

If we exceed allowed flips:

```
while zeros > k:
    remove nums[low] from window
    low++
```

If removed element was zero:

```
zeros--
```

---

### Step 5 — Update maximum length

```
res = max(res, window size)
```

Window size:

```
high - low + 1
```

---

Core idea:

```
Expand → Break constraint → Shrink → Record answer
```

---

# 4. Complexity Analysis 📊

## Time Complexity

### Worst Case

```
O(n)
```

Why?

Each element is:

* visited once by `high`
* removed once by `low`

So total operations:

```
high moves n times
low moves n times
```

Total:

```
O(2n) ≈ O(n)
```

---

### Best Case

If array already valid:

```
[1 1 1 1 1]
```

Window never shrinks.

```
Time = O(n)
```

---

### Average Case

Typical arrays cause occasional shrinking, but still:

```
O(n)
```

---

## Space Complexity

We only use:

```
low
high
zeros
res
```

No extra structures.

```
Space = O(1)
```

Constant memory. ✅

---

# 5. Edge Cases ⚠️

### Case 1 — No zeros

```
nums = [1 1 1 1]
k = 2
```

Answer:

```
4
```

Window never shrinks.

---

### Case 2 — All zeros

```
nums = [0 0 0 0]
k = 2
```

Best subarray:

```
[0 0] → flip both
length = 2
```

---

### Case 3 — k = 0

```
nums = [1 1 0 1 1]
```

We cannot flip zeros.

Window must contain **only 1s**.

---

### Case 4 — k ≥ number of zeros

```
nums = [1 0 1 0 1]
k = 5
```

We can flip all zeros.

Answer:

```
n
```

---

# 6. Common Pitfalls 🚫

### ❌ Mistake 1: Using `if` instead of `while`

Wrong:

```cpp
if (zeros > k)
```

Correct:

```cpp
while (zeros > k)
```

Reason:

There may be **multiple zeros to remove**.

---

### ❌ Mistake 2: Forgetting to decrement zeros

When removing:

```
if nums[low] == 0
    zeros--
```

Without this, window logic breaks.

---

### ❌ Mistake 3: Updating result before fixing window

Must update result **after window becomes valid**.

---

# 7. Optimization Insight 🔍

This problem is a **classic pattern**:

```
Longest Subarray With At Most K Violations
```

Same idea appears in problems like:

* Longest substring with at most K distinct characters
* Max consecutive ones III
* Longest repeating character replacement

General formula:

```
while (constraint violated)
    shrink window
```

---

# 8. Mental Model 🧩

Think of the window like a **rubber band**:

```
expand → expand → expand
         |
     constraint breaks
         ↓
      shrink left
```

Graphically:

```
[----valid window----]
 L                 H

Add element → invalid

[------invalid------]
 L                  H

Shrink left →

   [----valid----]
    L           H
```

---

✅ **Final takeaway**

Sliding window works because we maintain the invariant:

```
zeros ≤ k
```

This lets us scan the array **once** and keep track of the **largest valid window**.

```
Time  : O(n)
Space : O(1)
```

---




