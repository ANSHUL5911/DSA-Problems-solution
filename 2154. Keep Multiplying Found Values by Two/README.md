

# 🎯 **Problem Recap**

You are given an array `nums` and a number `original`.

👉 If `original` exists in the array → double it
👉 Check again
👉 Repeat until the doubled value no longer exists

This is the classic LeetCode problem: **Keep Multiplying Found Values**.

---

# 🧠 **Intuition — What Are We Really Doing?**

Imagine you have a treasure map 🗺️ and you’re searching for a number.

Whenever you *find* the number in the forest 🌲 you:

💥 **Double it (power-up!)**
and
🔄 **Start searching again from the beginning**

This continues until…

❌ You can’t find your number anymore
🎉 That final number is your answer.

---

# 🏗️ **Approach Breakdown (with visuals 👇)**

---

## 🟦 **Step 1: Sort the Array**

Binary search only works on sorted data.

```
Unsorted:   [5, 3, 2, 8]
Sorted:     [2, 3, 5, 8]
```

✨ Sorting makes the search faster and structured.

---

## 🟩 **Step 2: Use Recursive Binary Search**

### 📌 Why Binary Search?

Because instead of scanning the full array:

❌ Linear search → O(n)
✔ Binary search → O(log n)

We divide the array like this:

```
          [ 2 | 3 | 5 | 8 ]
              🔼 mid
```

At every step, we cut the search space in half.

---

## 🧩 **Binary Search Logic (🚦Flow)**

Let’s visualize the recursion:

```
              🔍 Search(nums, 0, n-1, original)
                        |
              +---------+---------+
              |                   |
        nums[mid] == original ?  ❌ nums[mid] < original ?
              |                          |
        YES → Double & Restart      YES → Search right half
                                     NO → Search left half
```

---

## 🔥 **Power-Up Mechanism (The Magic Part)**

Whenever we find the number:

```
original = 2 * original
```

Then we restart the search:

```
Search(nums, 0, nums.size()-1, original)
```

This ensures we check the **whole array again** for the new value.

---

# 🖼️ **Graphical Run Example**

Let:

```
nums = [2, 3, 4, 8, 16]
original = 2
```

### ▶ First Round

```
🔍 Searching for 2
🎯 FOUND
💥 original = 4
```

### ▶ Second Round

```
🔍 Searching for 4
🎯 FOUND
💥 original = 8
```

### ▶ Third Round

```
🔍 Searching for 8
🎯 FOUND
💥 original = 16
```

### ▶ Fourth Round

```
🔍 Searching for 16
🎯 FOUND
💥 original = 32
```

### ▶ Fifth Round

```
🔍 Searching for 32
❌ NOT FOUND
✔ Return 32
```

---

# 📦 **Fixed Code (For Reference)**

(Already explained earlier)

---

# ⏱️ **Time & Space Complexity**

### ⭐ Sorting

```
O(n log n)
```

### ⭐ Binary Search

Each search = O(log n),
Worst case: we double value *k times* (k ≈ log(max_value)).

Total:

```
O(n log n) + k * O(log n)
```

Since `k` is small, dominant term = sorting.

### ✔ **Final Time Complexity = O(n log n)**

### ✔ **Space Complexity = O(log n)**

(recursion stack depth of binary search)

---

# 🧑‍💻 **Senior Developer Summary (Clean & Crisp)**

* We sort the list to allow binary search.
* We recursively search for the current `original`.
* If found → double and restart search.
* If not found → return the last value.
* Efficient because binary search reduces lookup time drastically.

---



