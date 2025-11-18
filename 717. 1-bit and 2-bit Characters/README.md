

# 🎯 **Problem Understanding (with visuals)**

You are given a binary array `bits`, where:

### ✔ One-bit character → `0`

### ✔ Two-bit character → `10` or `11`

So encoding works like this:

```
0 → 🟢 single char  
10 → 🔵 double char  
11 → 🔵 double char  
```

We must answer:

### **👉 Is the *last character* of the array a "one-bit" character?**

This means we need to check if the last `0` is **alone** or part of a **2-bit pair** (like "10").

---

# ❌ **Why simple size checks don’t work**

Examples that break the wrong logic:

### Example 1

```
[1,1,0] → ❌ last 0 is part of "10"
```

### Example 2

```
[1,0,0] → ✔ last 0 is single
```

Both look similar in size…
But their **decoding behavior** is different.

---

# 🌈 **Intuition (Explained Like a Senior Engineer)**

Think of the bit array as a **train track** 🛤️
You are a **train engine 🚂** moving from left to right.

Two types of tiles are placed on the track:

### 🟩 **1-step tile**

If you step on `0`, move **1 step forward**.

### 🟦 **2-step tile**

If you step on `1`, it *automatically forms a 2-step tile* (`10` or `11`).
So you must move **2 steps forward**.

Your goal:

### 👉 Will the engine stop precisely **on the last tile** (meaning that last tile was a single-step `0`)?

If yes → `true`
If not → `false`

---

# 🧠 **Approach (Decoded with Visual Flow)**

We start from index `i = 0` and move until the *second last* bit.

### 🔍 Rule:

* If `bits[i] == 1` → jump 2 steps ➡️➡️
* If `bits[i] == 0` → jump 1 step ➡️

### 🎨 Visual Walkthrough

Example:
`[1, 0, 0]`

```
i = 0 → 1 ➡️ jump to i = 2  
i = 2 → last element  
```

Since we land **exactly** on last index → ✔ last is 1-bit character.

---

Example:
`[1,1,0]`

```
i = 0 → 1 ➡️ jump to i = 2  
i = 2 → NOT last, because last index is 2? Yes
BUT we reached here after a 2-bit jump,
meaning this 0 is part of the 2-bit pair.
```

We didn't "decode" onto it as a standalone → ❌ return false.

---



# ⏱️ **Time & Space Complexity**

### **👉 Time Complexity: O(n)**

Because we traverse the array once, jumping by 1 or 2 steps.

### **👉 Space Complexity: O(1)**

No extra memory used except variables.

---

# ✨ Final Summary (Beautiful and Simple)

| Step                   | Meaning                                        |
| ---------------------- | ---------------------------------------------- |
| 🧠 Understand encoding | 0 = 1-bit, 10/11 = 2-bit                       |
| 🚂 Traverse from start | Move 1 or 2 steps                              |
| 🎯 Check last stop     | If pointer ends *exactly* at last index → true |

---



