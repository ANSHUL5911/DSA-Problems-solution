

# 🧠 Problem: Generate All Subsets (Power Set)

Given an array:

```
nums = [1, 2, 3]
```

We need **all possible subsets**, including:

* Empty subset `[]`
* Single elements `[1]`
* Combinations `[1,2]`
* Full array `[1,2,3]`

📌 This is called the **Power Set**.

---

## 🔑 Core Intuition (MOST IMPORTANT)

For **every element**, you always have **two choices**:

```
👉 Include it
👉 Exclude it
```

This is the **foundation of recursion & backtracking**.

Think like a decision tree 🌳

---

## 🌳 Decision Tree Visualization

For `nums = [1, 2]`

```
                      []
               /                 \
        exclude 1               include 1
            []                    [1]
         /      \               /        \
   exclude 2  include 2   exclude 2   include 2
      []         [2]         [1]        [1,2]
```

🟢 **Each path = one subset**
🟢 **Leaf nodes = final answers**

---

## 🔍 Code Walkthrough (Line by Line, Intuition First)

### 🔒 Helper Function

```cpp
void solve(vector<int> nums, vector<int> output, int index,
           vector<vector<int>>& ans)
```

| Parameter | Meaning                    |
| --------- | -------------------------- |
| `nums`    | Original input array       |
| `output`  | Current subset being built |
| `index`   | Current position in `nums` |
| `ans`     | Final list of all subsets  |

---

## 🛑 Base Case (Stopping Condition)

```cpp
if (index >= nums.size()) {
    ans.push_back(output);
    return;
}
```

🧠 **What it means**:

* We have processed **all elements**
* Current `output` is a **complete subset**
* Save it 📝

🎯 **Golden Rule of Recursion**

> Always ask: *"When should I stop?"*

---

## ❌ Exclude Case

```cpp
solve(nums, output, index + 1, ans);
```

📌 We **skip** the current element
📌 Move to next index
📌 `output` remains unchanged

---

## ✅ Include Case

```cpp
int element = nums[index];
output.push_back(element);
solve(nums, output, index + 1, ans);
```

📌 Add current element
📌 Move forward
📌 Explore all subsets **that include this element**

---

## 🔁 Why Include AFTER Exclude?

This maintains:

* Clean recursion flow
* Avoids unnecessary backtracking cleanup
* Predictable subset ordering

💡 **Industry Tip**:
This pattern is **standard in Google/Microsoft interviews**

---

## 🧩 Full Flow Summary (Mental Model)

For every element:

```
Step 1 → Ignore it ❌
Step 2 → Take it ✅
```

Repeat until:

```
index == nums.size()
```

🎉 Subset completed!

---

## ⏱️ Time & Space Complexity (VERY IMPORTANT)

### ⏱️ Time Complexity

```
O(2^n)
```

Why?

* Each element has **2 choices**
* Total subsets = `2^n`

---

### 💾 Space Complexity

```
O(n)   → recursion stack
O(2^n * n) → output storage
```

📌 `n` depth recursion
📌 Each subset can take up to `n` space

---

## 🏆 Why This Solution Is PERFECT

✅ Clean recursion
✅ No global variables
✅ Easy to debug
✅ Interview-approved
✅ Scales well for constraints

This is **textbook backtracking** 💯

---

## 🧠 Knowledge You Should Take Away (VERY IMPORTANT)

### 🔑 Core Learnings

1. **Every recursion problem = choices + base case**
2. Subsets = **Include / Exclude pattern**
3. Pass `output` by value to avoid manual backtracking
4. Think in **decision trees**, not loops
5. `2^n` → always suspect subsets / combinations

---

## 🚀 Pro Tip from Senior Dev

If you master this pattern, you can easily solve:

* ✅ Subsets II
* ✅ Permutations
* ✅ Combination Sum
* ✅ Letter Combinations
* ✅ Backtracking on strings

---

## 🎯 Final Thought

> **Recursion is not magic**
> It’s just **trusting the function to solve smaller problems** 🧩

