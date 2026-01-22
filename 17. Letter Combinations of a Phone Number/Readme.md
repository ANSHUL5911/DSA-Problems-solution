
---

# 📱 Letter Combinations of a Phone Number

*(Backtracking / Recursion Masterclass)*

---

## 🧠 Intuition (Think Like a Human)

Imagine you’re typing on an **old mobile keypad** 📞:

```
2 → abc
3 → def
```

If the input is `"23"`, your brain automatically thinks:

👉 Pick **one letter from "abc"**
👉 For each of those, pick **one letter from "def"**

That’s it.
You’re just **exploring all possible paths** formed by choices at each digit.

🧩 This is a **decision tree problem**:

* At each digit → multiple choices (letters)
* Final goal → all complete paths

Sounds like **recursion + backtracking**, right? ✅

---

## 🌳 Visualizing the Recursion Tree

For `digits = "23"`

```
                ""
        /        |        \
       a         b         c
    /  |  \   /  |  \   /  |  \
   ad ae af  bd be bf  cd ce cf
```

🟢 Every **root-to-leaf path** = one valid answer
🟢 Total answers = product of choices

---

## 🛠️ Approach (Step-by-Step)

### 1️⃣ Mapping Digits → Letters

```cpp
string mapping[10] = {
  "", "", "abc", "def", "ghi",
  "jkl", "mno", "pqrs", "tuv", "wxyz"
};
```

📌 Index = digit
📌 Value = possible letters

---

### 2️⃣ Recursive Function `solve(...)`

```cpp
void solve(string digits, string output, int index,
           vector<string>& ans, string mapping[])
```

Think of this function as:

> 🧠 *"I will fix letters from position `index` onward."*

---

### 3️⃣ Base Case 🛑 (Very Important!)

```cpp
if (index >= digits.length()) {
    ans.push_back(output);
    return;
}
```

🎯 When:

* We’ve processed **all digits**
* `output` is now a **complete combination**

➡️ Store it and return

---

### 4️⃣ Recursive Exploration 🔁

```cpp
int number = digits[index] - '0';
string value = mapping[number];
```

📌 Get letters for current digit

Now loop through choices 👇

```cpp
for (int i = 0; i < value.length(); i++) {
    output.push_back(value[i]);      // choose
    solve(digits, output, index + 1, ans, mapping);
    output.pop_back();               // backtrack
}
```

---

## 🔙 Backtracking Explained (SUPER IMPORTANT)

### 🔄 What is Backtracking?

It’s the art of:

> **Try → Explore → Undo → Try next**

Example:

```
output = "a"
→ choose 'd' → "ad" → save
→ undo 'd' → back to "a"
→ choose 'e' → "ae"
```

🧼 `pop_back()` cleans the state so the next choice starts fresh.

---

## 🎯 Why Backtracking is Perfect Here?

| Problem Nature            | Solution        |
| ------------------------- | --------------- |
| Multiple choices per step | ✔️ Backtracking |
| Need all combinations     | ✔️ DFS          |
| Tree-like exploration     | ✔️ Recursion    |

---

## ⏱️ Time Complexity Analysis

Let:

* `n` = number of digits
* Each digit gives **up to 4 letters** (`7` and `9`)

### 🔢 Total combinations:

```
O(4ⁿ)
```

### 💡 Why?

* Each digit → branching factor ≤ 4
* Depth of recursion = n

---

## 🧠 Space Complexity

### 1️⃣ Recursion Stack

```
O(n)
```

### 2️⃣ Output Storage

```
O(4ⁿ)
```

📌 This is unavoidable because we must store all combinations.

---

## 🧪 Example Walkthrough

Input:

```cpp
digits = "23"
```

Output:

```cpp
["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

✔️ All valid
✔️ No duplicates
✔️ Clean backtracking

---

## 🧠 Key Learnings (Take This With You 🔥)

### 💎 Concepts You Master Here:

* ✅ Backtracking template
* ✅ Recursion with state
* ✅ Decision tree traversal
* ✅ Handling combinations problems

### 🧩 Same Pattern Appears In:

* Subsets
* Permutations
* Combinations
* N-Queens
* Sudoku Solver

---

## 🧠 Senior Engineer Tip 🧑‍💻

Whenever you hear:

> **“Generate all possible…”**

Immediately think:

> 🌳 **Recursion + Backtracking**

---

