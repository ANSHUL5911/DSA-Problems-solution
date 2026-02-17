

# 🧠 Problem Intuition — *What are we really doing?*

We’re given a **sorted array** (can contain negatives):

```
nums = [-7, -3, 0, 2, 5]
```

If we square everything directly ❌:

```
[49, 9, 0, 4, 25]  // not sorted
```

💡 **Key Insight**

* Negative numbers become **large** after squaring
* Positive numbers stay in order after squaring

So we:

1. Separate negatives and positives
2. Square them
3. Merge like **merge step of merge sort**

---

# 🧩 High-Level Strategy (Big Picture)

```
nums
 │
 ├── neg (≤0) → square → reverse
 │
 └── pos (>0) → square
        ↓
      MERGE (two pointers)
        ↓
      sorted result
```

---

# 🛠️ Step-by-Step Breakdown of YOUR Code

---

## 1️⃣ Splitting numbers by sign

```cpp
vector<int> pos;
vector<int> neg;

for(int i = 0; i < nums.size(); i++){
    if(nums[i] > 0)
        pos.push_back(nums[i]);
    else
        neg.push_back(nums[i]);
}
```

📦 Example:

```
nums = [-4, -1, 0, 3, 10]

neg = [-4, -1, 0]
pos = [3, 10]
```

---

## 2️⃣ Edge cases (excellent thinking 👏)

### Only positives

```cpp
if(neg.size() == 0){
    square pos and return
}
```

### Only negatives

```cpp
if(pos.size() == 0){
    square neg
    reverse
    return
}
```

🚀 This avoids unnecessary merging.

---

## 3️⃣ Preparing for merge

```cpp
vector<int> res(m + n);
```

🔑 **Important rule**

> If you want to write using `res[index]`, the vector MUST be resized first

You did this correctly ✅

---

## 4️⃣ Squaring both arrays

```cpp
for(int i=0;i<pos.size();i++)
    pos[i] *= pos[i];

for(int i=0;i<neg.size();i++)
    neg[i] *= neg[i];

reverse(neg.begin(), neg.end());
```

📊 Example after this step:

```
neg = [0, 1, 16]
pos = [9, 100]
```

Now both arrays are **sorted** 👍

---

## 5️⃣ Two-pointer merge (core logic)

```cpp
while(i < pos.size() && j < neg.size()){
    if(pos[i] < neg[j])
        res[id++] = pos[i++];
    else
        res[id++] = neg[j++];
}
```

🧠 This is **exactly merge sort logic**
📌 Linear, clean, optimal

---

## ❌ BUG (Important 🔥)

### Here is a subtle but critical mistake:

```cpp
while(j < neg.size()){
    res[id] = pos[j];   // ❌ WRONG
    id++;
    j++;
}
```

👉 You are copying from **pos**, but `j` belongs to **neg**

### ✅ Correct version

```cpp
while(j < neg.size()){
    res[id++] = neg[j++];
}
```

This bug can cause:

* Wrong output
* Out-of-bounds access
* Runtime errors in some cases

---

# ✅ Final Corrected Version (Clean & Safe)

```cpp
while(i < pos.size()){
    res[id++] = pos[i++];
}

while(j < neg.size()){
    res[id++] = neg[j++];
}
```

---

# ⏱️ Time & Space Complexity

### ⏳ Time

* Splitting: `O(n)`
* Squaring: `O(n)`
* Merging: `O(n)`

✅ **Total: `O(n)`**

---

### 💾 Space

* `pos`, `neg`, `res`

✅ **Total: `O(n)` extra space**

---

# 🎯 Interview-Ready Explanation (Use This!)

> We separate negative and non-negative numbers because squaring negatives reverses their order. After squaring both parts, we reverse the negative portion to make it sorted, then merge the two sorted arrays using a two-pointer approach. This achieves linear time complexity.

---

