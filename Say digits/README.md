

# 🌟 **🔤 Convert Number Digits Into Words — Full Intuition + Approach + Complexity**

---

# 🎯 **✨ Goal of the Code**

You want to take a number like:

```
8934
```

and print it as:

```
eight nine three four
```

But the trick is 👉 **you must print digits in correct order** using **recursion**.

---

# 🧠 **✨ Intuition Behind the Solution**

Think of recursion like a **stack of boxes** 📦📦📦 :

* First, you keep **opening** boxes (recursive calls) until you hit the base case.
* Then, while *coming back*, each box prints its digit.

This gives you **Left-to-Right printing**, even though digits are extracted **Right-to-Left**.

---

## 📌 **🎨 Visual Intuition (Very Important!)**

### ⭐ Step-by-Step Recursion Visualization

For `8934`:

### Step 1: n = 8934

👉 Extract digit = 4
👉 Recurse on 893

### Step 2: n = 893

👉 Extract digit = 3
👉 Recurse on 89

### Step 3: n = 89

👉 Extract digit = 9
👉 Recurse on 8

### Step 4: n = 8

👉 Extract digit = 8
👉 Recurse on 0

### Step 5: n = 0

🎉 Base Case → Stop Recursing

---

### 🌀 **Now the recursion unwinds (LIFO)**:

| Stack Return Order | Printed Digit | Word  |
| ------------------ | ------------- | ----- |
| Step 4             | 8             | eight |
| Step 3             | 9             | nine  |
| Step 2             | 3             | three |
| Step 1             | 4             | four  |

✔ Output: **eight nine three four**
Exactly what we wanted 😄🎯

---

# 🧩 **✨ Approach Explanation (Like a Senior Developer)**

---

## 🔹 **1. Base Case**

```cpp
if(n == 0) return;
```

When the number becomes 0, we **stop** recursion.
This prevents infinite calls and also marks the **deepest level** of recursive stack.

---

## 🔹 **2. Extract Last Digit**

```cpp
int digit = n % 10;
n = n / 10;
```

* `% 10` gives last digit
* `/ 10` removes last digit
  These operations shrink the number each recursion → leading to termination.

---

## 🔹 **3. Recursive Call**

```cpp
printWord(n, arr);
```

We call the function **before printing the digit**
🔥 This is the master trick!

This ensures digits print in **forward order**.

If you print before recursive call → output becomes **reverse** ❌.

---

## 🔹 **4. Print the Word**

```cpp
cout << arr[digit - 1] << " ";
```

Because your array starts from `"one"` → index = `digit - 1`.

---

# 🧮 **✨ Time & Space Complexity**

---

## ⏱ **Time Complexity → O(D)**

Where **D = number of digits** in the number.

Each digit causes one recursive call → linear.

Example: `8934` → 4 recursive calls.

---

## 🗂 **Space Complexity → O(D)**

Because recursion uses a **call stack**.

Each digit → one stack frame.

---

# 🎨 **✨ Final Beautiful Flow Diagram (ASCII Art)**

```
           printWord(8934)
                 |
                 v
          ┌─────────────────┐
          | digit = 4       |
          | n = 893         |
          └─────────────────┘
                 |
                 v
          printWord(893)
                 |
                 v
          ┌─────────────────┐
          | digit = 3       |
          | n = 89          |
          └─────────────────┘
                 |
                 v
          printWord(89)
                 |
                 v
          ┌─────────────────┐
          | digit = 9       |
          | n = 8           |
          └─────────────────┘
                 |
                 v
          printWord(8)
                 |
                 v
          ┌─────────────────┐
          | digit = 8       |
          | n = 0           |
          └─────────────────┘
                 |
                 v
          printWord(0)
          BASE CASE → RETURN
```

### 🌈 Output while unwinding:

```
eight nine three four
```

---

# 🏁 **✨ Summary (Very Easy to Remember)**

| Step                      | What Happens         |
| ------------------------- | -------------------- |
| 1️⃣ Extract last digit    | `digit = n % 10`     |
| 2️⃣ Recurse for remaining | `printWord(n/10)`    |
| 3️⃣ Print digit word      | from array           |
| 4️⃣ Order fixed           | because of recursion |

---

