

## 🚀 **Problem:**

We are given a **rotated sorted array** (like a sorted array that was cut and rotated around some pivot), and we need to find a **target element** efficiently.

🧩 **Example:**

```
Original Sorted: [0, 1, 2, 4, 5, 6, 7]
Rotated Version: [4, 5, 6, 7, 0, 1, 2]
Target = 0 → Output: 4 (index)
```

---

## 🎯 **Goal**

Find the index of the target in **O(log n)** time — using **Binary Search** 🧭
Not linear search (❌ O(n)), because that’s too slow for large arrays!

---

## 🧠 **Intuition (Think Like a Detective 🕵️‍♂️)**

We know that even after rotation:
➡️ **At least one half** of the array (left or right) is always **sorted**.
So in each step, we:

1. Check which half is sorted. ✅
2. Check if the target lies **inside** that sorted half. 🎯
3. Move search boundaries (`start`, `end`) accordingly. 🧱

This is what makes this binary search *smart* and efficient!

---

## ⚙️ **Approach Breakdown (Step-by-Step Animation 💡)**

### 🪜 Step 1: Initialization

```cpp
int start = 0;
int end = nums.size() - 1;
```

We start with the **whole array**.

---

### 🪜 Step 2: Binary Search Loop

```cpp
while (start <= end) {
    int mid = start + (end - start) / 2;
```

We compute `mid` safely (avoiding overflow).

📍Imagine:

```
[4, 5, 6, 7, 0, 1, 2]
  ↑        ↑        ↑
 start    mid       end
```

---

### 🪜 Step 3: Check for Match

```cpp
if (nums[mid] == target)
    return mid;
```

If found — boom 💥 — return the index!

---

### 🪜 Step 4: Identify the Sorted Half 🧭

```cpp
if (nums[start] <= nums[mid]) {   // Left half is sorted
```

If the **left half** is sorted (notice `<=`, not `<` — handles duplicates or rotation points).

---

### 🪜 Step 5: Check Where the Target Lies 🎯

```cpp
if (target >= nums[start] && target < nums[mid])
    end = mid - 1;
else
    start = mid + 1;
```

If the target lies **within** the sorted left half → we shrink the right half.
Otherwise, shift focus to the **right** side.

---

### 🪜 Step 6: Otherwise, Right Half Must Be Sorted

```cpp
else {  // Right half is sorted
    if (target > nums[mid] && target <= nums[end])
        start = mid + 1;
    else
        end = mid - 1;
}
```

Same logic mirrored for the right side 🔁

---

### 🪜 Step 7: Not Found 😞

If we exit the loop:

```cpp
return -1;
```

Means target doesn’t exist in the array.

---

## 🌈 **Visual Representation**

```
Rotated Array: [4, 5, 6, 7, 0, 1, 2]
                 └─────┬─────┘
                 Sorted Half 🟩

Target = 1
1️⃣ mid = 3 → nums[mid] = 7  
   Left sorted → [4,5,6,7]
   Target (1) not in [4,7] → Move right  
2️⃣ start = 4, end = 6  
   mid = 5 → nums[mid] = 1 ✅ FOUND at index 5!
```

---

## ⏱ **Time & Space Complexity**

| Complexity            | Explanation                                                     |
| --------------------- | --------------------------------------------------------------- |
| 🕒 **Time: O(log n)** | Because each iteration halves the search space (binary search). |
| 💾 **Space: O(1)**    | No extra data structures used, just variables.                  |

---

## 🧩 **Summary Diagram**

```
                🔍 Binary Search in Rotated Sorted Array
 ┌────────────────────────────────────────────────────────┐
 │ Step 1: Find Mid                                       │
 │ Step 2: Check if Left Half Sorted                      │
 │ Step 3: Decide which half to explore next              │
 │ Step 4: Narrow search range                            │
 │ Step 5: Repeat until found or start > end              │
 └────────────────────────────────────────────────────────┘
```

---

## 🏁 **Final Thoughts (Senior Dev Wisdom 💬)**

> “Binary search is like dividing a problem in half each time —
> but the trick in rotated arrays is knowing **which half** to trust.” ⚔️

👉 Always remember: **In every rotation, there’s still order — find it, use it, win it.** 🧩






