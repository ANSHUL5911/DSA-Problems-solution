
This problem is famously known as:

# 🎨 Dutch National Flag Algorithm

Proposed by: **Edsger W. Dijkstra**

Used in: **Sort Colors (0s, 1s, 2s problem)**

---

# 🧠 Problem Understanding

You are given an array containing only:

```
0 → Red
1 → White
2 → Blue
```

Goal:

```
Sort them in-place
Without using extra space
In ONE PASS
```

Example:

```
Input:  [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

---

# 💡 Core Intuition

Instead of sorting normally (O(n log n)),
we use **3 pointers** to divide the array into 4 regions.

Imagine this structure:

```
| 0s zone | 1s zone | Unknown zone | 2s zone |
|---------|---------|--------------|---------|
   0      low      mid           high      n-1
```

We maintain:

```
[0 ... low-1]     → All 0s ✅
[low ... mid-1]   → All 1s ✅
[mid ... high]    → Unknown ❓
[high+1 ... n-1]  → All 2s ✅
```

We process the **unknown zone**.

---

# 🔥 The 3 Pointer Strategy

```cpp
int low = 0;
int mid = 0;
int high = n - 1;
```

---

## 🟥 Case 1: nums[mid] == 0

```
swap(nums[low], nums[mid]);
low++;
mid++;
```

Why?

Because 0 belongs to the **left side**.

Move both pointers forward.

---

## ⬜ Case 2: nums[mid] == 1

```
mid++;
```

Why?

1 is already in correct middle region.

Just move forward.

---

## 🟦 Case 3: nums[mid] == 2

```
swap(nums[mid], nums[high]);
high--;
```

Why?

2 belongs to the **right side**.

⚠️ IMPORTANT:
We DO NOT increment mid here.

Because after swapping, we must check the new value that came from the right.

---

# 🎯 Visual Dry Run

Input:

```
[2,0,2,1,1,0]
```

Step-by-step:

```
low=0 mid=0 high=5

[2,0,2,1,1,0]
 ↑         ↑
 mid       high
```

2 found → swap with high

```
[0,0,2,1,1,2]
```

Now:

```
mid=0 (check again)
```

0 found → swap with low

Eventually becomes:

```
[0,0,1,1,2,2]
```

All in one pass 🔥

---

# ⏱️ Time & Space Complexity

### ⏳ Time Complexity

```
O(n)
```

Each element is processed at most once.

Even though swaps happen,
each pointer moves only forward/backward once.

---

### 📦 Space Complexity

```
O(1)
```

No extra array used.
Pure in-place sorting.

This is why interviewers LOVE this solution.

---

# 🧩 Why This is Better Than Sorting?

Normal sort:

```
O(n log n)
```

Counting sort:

```
Two passes
```

Dutch National Flag:

```
Single pass
Constant space
Linear time
```

Optimal solution ✅

---

# 🏆 Why This Pattern Is Important

This teaches:

* Two pointer technique
* Partition logic (used in QuickSort)
* In-place array manipulation
* Thinking in regions instead of values

This exact concept is used in:

* Partitioning in QuickSort
* Segregating negatives/positives
* 3-way partitioning problems

---

# 🛠 Code Review (Senior Engineer Perspective)

Your implementation is ✅ clean and correct.

Only small improvement:

Your `solve()` returns `nums` but you don't use the return value.

Better version:

```cpp
void solve(int n, vector<int> &nums){
```

Since you modify in-place.

That’s more professional.

---

# 🧠 Key Learning Takeaways

✨ Always think in terms of regions
✨ Use pointers to shrink problem space
✨ Avoid unnecessary re-checks
✨ Don't move pointer blindly after swap
✨ Optimize time + space simultaneously

---

# 🎓 Final Summary

| Feature         | Value               |
| --------------- | ------------------- |
| Algorithm       | Dutch National Flag |
| Time            | O(n)                |
| Space           | O(1)                |
| Passes          | Single              |
| Interview Level | 🔥 Very Important   |

---


