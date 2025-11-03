

## 🧩 Problem Intuition: “Plus One”

You’re given a **vector of digits** representing a **non-negative integer**.
👉 Your task: **Add one** to that number and return the new list of digits.

For example:

```
[1, 2, 3] ➜ 123 + 1 = 124 ➜ [1, 2, 4]
```

---

## 🧠 Think Like a Developer: What’s Actually Happening?

Imagine each element in the vector is a **digit** in a number:

```
   [1, 2, 9]
        ↑
We start from the last digit (like manual addition)
```

We do **“plus one”** starting from the rightmost digit:

* If it’s not `9` → just increment it and done ✅
* If it’s `9` → make it `0` and carry `1` to the next digit 💭
* If all digits are `9` → we need an extra place for the carry at the front.

Example:

```
[9, 9, 9] ➜ all turn to 0 ➜ we insert 1 at the beginning ➜ [1, 0, 0, 0]
```

---

## ⚙️ Step-by-Step Approach (Visual Intuition)

### 🔹 Step 1: Start from the last digit

We iterate **backwards** — from least significant digit to most.

```
🧮 digits = [1, 2, 9]
             ↑ ↑ ↑
             0 1 2   (indexes)
```

---

### 🔹 Step 2: Add one

* If digit < 9 → increment & return
* Else → set to 0 and continue

```
Iteration 1:
digits[2] = 9 ➜ 0 (carry = 1)
digits[1] = 2 ➜ 3 (carry handled) ✅
```

Result ➜ `[1, 3, 0]`

---

### 🔹 Step 3: Handle the “All 9s” Case

If loop finishes and all digits became `0`,
add a new `1` at the start 💥

```
[9, 9, 9] ➜ [0, 0, 0] ➜ Insert 1 ➜ [1, 0, 0, 0]
```

---



## 📊 Complexity Analysis

| Aspect       | Explanation                                                   |                  Complexity                 |
| :----------- | :------------------------------------------------------------ | :-----------------------------------------: |
| **Time** ⏰   | We may touch each digit once (worst case: all 9s)             |                   **O(n)**                  |
| **Space** 💾 | We modify in place, except possibly inserting one extra digit | **O(1)** (or O(n) if you count output size) |

---

## 🧩 Visual Representation

Here’s how the operation looks conceptually 👇

```
  Digits:   [9] [9] [9]
  +1  ➜  carry over each step
  Result:  [1] [0] [0] [0]
```

You can imagine a “ripple effect” 🌊 moving leftward across the digits when you hit a 9.

---

## 🎯 Key Takeaways

✅ Start from the **end** (rightmost digit).
✅ **Carry** only if you hit a 9.
✅ **Insert** 1 at front if all are 9.
✅ Clean, readable, and O(n) efficient.

---

## 🧠 Intuitive Analogy:

Think of it like a **car odometer** 🚗
Every time it rolls from `9` to `0`, the next wheel turns by 1.

```
   [1, 2, 9] → [1, 3, 0]
   [9, 9, 9] → [1, 0, 0, 0]
```

That’s exactly what we’re doing in code!

---

