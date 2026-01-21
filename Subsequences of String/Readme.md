
---

# 🌱 Generating All Subsequences of a String

*(Power of Recursion & Backtracking)*

---

## 🧠 Intuition (Think Like a Pro)

Imagine you’re standing at **each character** of the string and asking a **binary decision**:

> ❓ **Should I take this character or skip it?**

This decision happens for **every character**, which naturally forms a **decision tree** 🌳.

👉 This is why **recursion** is the perfect tool here.

---

## 🔁 What is a Subsequence?

A **subsequence**:

* Maintains **relative order**
* Characters **may be skipped**
* Does **not need to be contiguous**

📌 Example for `"abc"`

```
"", "a", "b", "c", "ab", "ac", "bc", "abc"
```

👉 Your code **excludes the empty string**.

---

## 🧩 Core Idea (High-Level)

For **each character**, you have **2 choices**:

```
1️⃣ Exclude it  
2️⃣ Include it
```

This creates:

```
2 × 2 × 2 × ... = 2ⁿ subsequences
```

---

## 🧪 Dry Run Example: `"abc"`

### Decision Tree 🌳

```
                    ""
              /               \
           ""                    "a"
        /      \              /       \
      ""        "b"         "a"        "ab"
     /   \     /   \       /   \      /    \
   ""   "c"  "b"  "bc"   "a"  "ac"  "ab"  "abc"
```

📌 Empty string is ignored
✅ Final Answer:

```
"a", "b", "c", "ab", "ac", "bc", "abc"
```

---

## 🔍 Code Walkthrough (Line-by-Line Intuition)

---

### 🛠️ Recursive Function

```cpp
void solve(string str, string output, int index, vector<string> &ans)
```

### 🔑 Parameters Meaning

| Parameter | Meaning                         |
| --------- | ------------------------------- |
| `str`     | Original string                 |
| `output`  | Current subsequence being built |
| `index`   | Current position in string      |
| `ans`     | Stores all valid subsequences   |

---

### 🛑 Base Case (VERY IMPORTANT)

```cpp
if(index >= str.length()){
    if(output.length() > 0 ){
        ans.push_back(output);
    }
    return ;
}
```

🧠 Meaning:

* We have processed **all characters**
* If `output` is **not empty**, store it
* Stop recursion 🔚

---

### 🚫 Exclude Case

```cpp
solve(str, output, index + 1, ans);
```

📌 We **skip** the current character
👉 Output remains unchanged

---

### ✅ Include Case

```cpp
char element = str[index];
output.push_back(element);
solve(str, output, index + 1, ans);
```

📌 We **take** the current character
👉 Output grows

---

### 🎯 Entry Function

```cpp
vector<string> subsequences(string str){
    vector<string> ans;
    string output = "";
    int index = 0;

    solve(str, output, index, ans);
    return ans;
}
```

🧠 Clean separation:

* Setup
* Recursive processing
* Return result

---

## 🧠 Why This Works (Senior Insight 💡)

✔️ Each character creates **two paths**
✔️ Recursion explores **all combinations**
✔️ Backtracking happens automatically when function returns
✔️ No extra cleanup needed because `output` is **passed by value**

---

## ⏱️ Time Complexity

### ⏳ Time:

```
O(2ⁿ)
```

* Every character doubles the possibilities

---

### 🧠 Space Complexity:

| Type            | Complexity |
| --------------- | ---------- |
| Recursion Stack | `O(n)`     |
| Output Storage  | `O(2ⁿ)`    |

---

## 🔥 Key Learnings (VERY IMPORTANT)

### 🧠 Core Concepts You Master Here:

✅ **Recursion Fundamentals**
✅ **Include–Exclude Pattern**
✅ **Backtracking without explicit undo**
✅ **Decision Tree Thinking**
✅ **Subsequence vs Substring clarity**

---

## 🚀 Where This Pattern is Used

💡 This SAME logic applies to:

* Subsets problems
* Power set
* String combinations
* Bitmasking (advanced)
* Dynamic Programming foundations

📌 Example Problems:

* LeetCode: Subsets
* GFG: Subsequences of string
* Interview favorite ⭐⭐⭐⭐⭐

---

## 🎯 Final Pro Tip (From Industry Experience)

> If you understand this problem deeply,
> **50% of recursion problems become easy** 💪

This is not just a question —
👉 **It’s a recursion blueprint** 🧩

---


