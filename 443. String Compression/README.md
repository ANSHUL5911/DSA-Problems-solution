

# 🔹 Problem in Simple Words

We are asked to **compress a string (given as a char array)** by replacing groups of repeated characters with:

* The character itself
* Followed by the count (if count > 1).

👉 Example:
`["a","a","b","b","c","c","c"]` → `["a","2","b","2","c","3"]`

---

# 🎯 Intuition

Think of this like **zipping a file 📦**:

* If a character repeats consecutively, instead of storing all of them, just store **one copy + how many times it appeared**.
* We do this **in-place** (without extra array) to save memory 💾.

---

# 🛠️ Approach (Step by Step)

Let’s decode the code visually:

---

### ✅ Step 1: Initialize

```cpp
int i = 0;              // pointer to read input
int ansIndex = 0;       // pointer to write compressed result
int n = chars.size();   // total length
```

---

### ✅ Step 2: Process each group of characters

We loop through `chars` using `i`. For each group:

* Use `j` to move forward until characters differ.
* `count = j - i` gives the number of repeats.

Visual Example 👇

```
chars = [a, a, b, b, b, c]
 i
 j
```

Here, `i = 0` and `j` moves until a different char is found.
So `count = j - i = 2` for `'a'`.

---

### ✅ Step 3: Store compressed result

* Write the character at `ansIndex`.
* If count > 1, convert count → string, and write digits one by one.

Example for `'b'` group:

```
Group: [b, b, b]
Write: 'b' → '3'
```

So compressed part becomes: `[b, 3]`.

---

### ✅ Step 4: Move to next group

Update `i = j` and continue.

---

### ✅ Step 5: Return length

Return `ansIndex`, which is the final compressed size.

---

# ⚡ Visual Flow (Diagram)

```
Input:  [a, a, b, b, b, c]
Process:
   i=0 → a → count=2 → store [a, 2]
   i=2 → b → count=3 → store [b, 3]
   i=5 → c → count=1 → store [c]
Output: [a, 2, b, 3, c]
Return length = 5
```

---

# ⏱️ Complexity Analysis

### ⌛ Time Complexity: **O(n)**

* Each character is visited once by `i` and `j`.
* Count conversion (`to_string`) takes log(count) digits, but overall still linear.

### 💾 Space Complexity: **O(1)**

* In-place compression, no extra storage apart from a few variables.

---

# 🌟 Why This Solution is Great

✅ Efficient (linear time)
✅ In-place (saves memory)
✅ Works for all edge cases (single char, large counts, etc.)

---

# 🎨 Attractive Mnemonic (for memory)

👉 **“Read 👀 → Count 🔢 → Write ✍ → Repeat 🔁”**

That’s the essence of this algorithm.


