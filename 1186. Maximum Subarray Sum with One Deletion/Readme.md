

# 🧠 Problem Intuition

👉 You are solving:
**Maximum subarray sum with at most ONE deletion**

Normal Kadane's Algorithm gives:

* Max sum of subarray with **no deletions**

But here’s the twist ⚡
👉 You can delete **at most one element**

---

## 💡 Key Insight

At every index `i`, you have **2 choices**:

```
1️⃣ Continue subarray WITHOUT deletion
2️⃣ Continue subarray WITH one deletion
```

So we maintain **2 states**:

| State          | Meaning                                        |
| -------------- | ---------------------------------------------- |
| 🟢 `nodelete`  | Max subarray sum ending at i WITHOUT deletion  |
| 🔴 `onedelete` | Max subarray sum ending at i WITH one deletion |

---

# 🎯 Visual Intuition

Imagine array:

```
[ 1, -2, 0, 3 ]
```

At `-2` ❌ → maybe we delete it
So best subarray becomes: `[1, 0, 3] = 4`

👉 That’s why we track both possibilities simultaneously

---

# ⚙️ Approach Breakdown

## 🟢 1. Initialization

```cpp
int nodelete = arr[0];
int onedelete = INT_MIN;
int res = arr[0];
```

* `nodelete` → same as Kadane
* `onedelete` → not started yet → so `INT_MIN`

---

## 🔄 2. Transition at each index

### 🟢 Update `nodelete`

```cpp
nodelete = max(nodelete + arr[i], arr[i]);
```

📌 Same as Kadane:

* Extend previous subarray
* OR start fresh

---

### 🔴 Update `onedelete`

Two cases:

---

### 🧩 Case 1: Extend previous deleted subarray

```cpp
v2 = prevonedelete + arr[i];
```

👉 Already deleted something before, just keep adding

---

### 🧩 Case 2: Delete current element

```cpp
onedelete = prevnodelete;
```

👉 Skip current element
So sum becomes previous `nodelete`

---

### ⚠️ Edge Case Handling

```cpp
if (prevonedelete == INT_MIN)
    v2 = arr[i];
```

👉 Means no deletion happened yet
So we **start fresh**

---

### 🔥 Final Transition

```cpp
onedelete = max(v2, prevnodelete);
```

---

## 🏁 3. Update Result

```cpp
res = max(res, max(onedelete, nodelete));
```

👉 Best of:

* no deletion
* one deletion

---

# 🎨 Flow Diagram

```
            arr[i]
               ↓
     ┌─────────────────────┐
     │   nodelete update   │
     │ max(prev + arr[i],  │
     │        arr[i])      │
     └─────────────────────┘
               ↓
     ┌─────────────────────┐
     │  onedelete update   │
     │ max(                │
     │   prevonedelete + a │
     │   prevnodelete      │
     │ )                   │
     └─────────────────────┘
               ↓
           update res
```

---

# 🔥 Example Walkthrough

### Input:

```
[1, -2, 0, 3]
```

| i | arr[i] | nodelete 🟢 | onedelete 🔴 | res |
| - | ------ | ----------- | ------------ | --- |
| 0 | 1      | 1           | -∞           | 1   |
| 1 | -2     | -1          | 1            | 1   |
| 2 | 0      | 0           | 1            | 1   |
| 3 | 3      | 3           | 4            | 4   |

👉 Final Answer = **4**

---

# 🚀 Complexity Analysis

### ⏱ Time Complexity

```
O(n)
```

✔ Single pass
✔ Constant operations

---

### 🧠 Space Complexity

```
O(1)
```

✔ No extra arrays
✔ Only variables

---

# 💎 Why This is Powerful

✅ Combines:

* Kadane’s Algorithm
* Dynamic Programming
* State Optimization

---

# 🧩 Interview Insight (VERY IMPORTANT)

💬 If interviewer pushes:

👉 You can say:

> “This is an extension of Kadane’s algorithm where we maintain two DP states — one for normal subarray and one allowing a single deletion. At each step, we either extend or perform deletion, ensuring O(n) time and O(1) space.”

---

# 🏆 Final Takeaway

🔑 Golden Rule:

> Whenever you see **"at most one operation/modification"** →
> Think **multiple DP states**

---




