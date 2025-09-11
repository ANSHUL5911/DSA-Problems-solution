

# 🧑‍💻 Problem Statement

👉 We need to find the **most frequently occurring character** in a string.

Example:
`"output"` → `'t'` occurs **2 times** → ✅ Answer = `'t'`

---

# 💡 Intuition

When you see "maximum occurrence", you should immediately think:
📊 **Count frequencies of characters** → then pick the one with the highest count.

It’s similar to:

* Counting votes 🗳️ in an election → winner = candidate with most votes
* Counting likes ❤️ on posts → most liked post = answer

---

# 🔎 Step-by-Step Approach

## 🔹 Step 1: Frequency Array

We create an array of size **26** → each index represents a lowercase letter.

```
arr[26] = {0};
```

📌 Mapping:

* `'a' → index 0`
* `'b' → index 1`
* ...
* `'z' → index 25`

---

## 🔹 Step 2: Traverse the String

For every character `ch` in string `s` → calculate index (`number`) and increment count.

✨ Conversion trick:

* If `ch` is lowercase → `ch - 'a'`
* If `ch` is uppercase → `ch - 'A'`

So `"A"` and `"a"` both map to index `0`. Nice, right? 😎

---

## 🔹 Step 3: Find Maximum Occurrence

Now scan through `arr[]` and keep track of:

* `maximum` → highest frequency seen so far
* `ans` → index of that character

Finally, return `ans + 'a'` to convert back into character.

---

# 🎨 Visual Representation

📦 Example Input: `"Output"`

### Step 1: Count array after processing

```
arr = [a=1, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0,
       k=0, l=0, m=0, n=0, o=1, p=1, q=0, r=0, s=0, t=2, ...]
```

### Step 2: Max Occurrence

`t → 2` (largest frequency)

✅ Answer = `'t'`

---

# ⚡ Complexity Analysis

⏱️ **Time Complexity**:

* Traversing string → `O(N)` (where `N = s.size()`)
* Scanning frequency array (26 letters only) → `O(26) ≈ O(1)`
  👉 Total = **O(N)**

💾 **Space Complexity**:

* Extra array of size 26 → **O(1)** constant

---

# 🎯 Final Takeaway

* ✅ Use **frequency counting** when asked for “most occurring / least occurring / duplicates”.
* ✅ This code is **efficient** (linear time, constant space).
* ✅ Handles both **uppercase & lowercase** letters.

---


🌈 Here’s a **mini infographic style summary** for you:

```
String → Count Frequencies 📊 → Find Max 🔝 → Return Char ✅
```

