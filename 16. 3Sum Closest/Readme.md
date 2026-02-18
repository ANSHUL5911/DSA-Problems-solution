
---

# 🚀 Problem: 3Sum Closest

### 🧩 Problem Statement (in simple words)

You’re given:

* an array `nums`
* an integer `target`

👉 Pick **any 3 numbers** such that their **sum is closest to `target`**
👉 Return that **sum**, not the indices.

---

## 🧠 Core Intuition (THE MOST IMPORTANT PART)

Think of this problem as:

> 🎯 *“I want to aim as close as possible to the target using exactly 3 arrows.”*

But trying **all triplets** would be:

```
O(n³) ❌ (Too slow!)
```

So we need a **smart way to shrink the search space**.

---

## 🔑 Big Insight

### ❓ Why sorting helps?

Once the array is sorted:

* If the sum is **too small**, we can **increase it**
* If the sum is **too large**, we can **decrease it**

➡️ This gives us **directional control**, like steering a car 🚗

---

## 🧭 Strategy Overview (High-Level)

```
1️⃣ Sort the array
2️⃣ Fix one number (i)
3️⃣ Use two pointers (left, right) to find best pair
4️⃣ Track the closest sum globally
```

This transforms the problem from:

```
O(n³) ➜ O(n²) 🚀
```

---

## 🧩 Visual Mental Model

```
Sorted Array:
[10, 20, 30, 40, 50, 60, 70, 80, 90]
   i   L                        R
```

* `i` → fixed anchor ⚓
* `L` → moves right ➡️ to increase sum
* `R` → moves left ⬅️ to decrease sum

---



## 🧠 Step-by-Step Execution (Example)

### Input

```
nums = [10,20,30,40,50,60,70,80,90]
target = 1
```

### Smallest possible sum

```
10 + 20 + 30 = 60
```

✔️ Since **all numbers are positive**, **every other sum is larger**
✔️ So **60 is the closest possible answer**

---

## 🚨 Common Mistakes

### ❌ Resetting closest difference inside loop

```cpp
int max_diff = INT_MAX; // ❌ wrong place
```

💥 This forgets previous better answers.

### ❌ Initializing result as 0

```cpp
int res_sum = 0; // ❌ dangerous default
```

✔️ Always initialize with **first valid triplet**

---

## 🎯 Key Interview Insights (WRITE THESE DOWN 📝)

🔹 Closest problems = **GLOBAL comparison**, not local
🔹 Sorting + Two pointers = **power combo**
🔹 Directional decisions save time
🔹 Always initialize answer **meaningfully**

---

## ⏱️ Time & Space Complexity

| Metric   | Value                    |
| -------- | ------------------------ |
| ⏱ Time   | **O(n²)**                |
| 🧠 Space | **O(1)** (ignoring sort) |

---

## 🏆 Final Takeaway (Senior Dev Wisdom)

> **Don’t chase exact answers.
> Chase the *distance* from the answer.**

Once you understand this mindset, problems like:

* 3Sum
* 4Sum
* K-Sum
* Closest Pair
  become much easier 💡

---

