

## 🌟 **🚀 LeetCode 1929 – Concatenation of Array**

---

### 🧩 **Problem Statement**

Given an integer array `nums` of length `n`, construct an array `ans` of length `2n` such that:

> `ans[i] = nums[i]` and `ans[i + n] = nums[i]` for `0 <= i < n`

Then, return the array `ans`.

---

### 💭 **Example**

```
Input:  nums = [1, 2, 3]
Output: [1, 2, 3, 1, 2, 3]
```

---

## 🎯 **Intuition (The Thinking Part 🧠)**

We want the result to look like this:

| Original  | → | Concatenated       |
| --------- | - | ------------------ |
| [1, 2, 3] | → | [1, 2, 3, 1, 2, 3] |

So basically, we’re just **duplicating the array** — one copy right after the other 💫

---

## ⚙️ **Approach (Step-by-Step with Diagram 🎨)**

### 🪄 Step 1: Find the size

```
n = nums.size()
```

### 🪄 Step 2: Create a new array of double size

```
vector<int> ans(2 * n);
```

### 🪄 Step 3: Fill both halves in one loop

```
for (int i = 0; i < n; i++) {
    ans[i] = nums[i];      // 🧩 First half
    ans[i + n] = nums[i];  // 🔁 Second half (repeat)
}
```

### 🪄 Step 4: Return the result

```
return ans;
```

---



## 📊 **Complexity Analysis**

| Type     | Complexity | Explanation                                |
| -------- | ---------- | ------------------------------------------ |
| ⏰ Time   | **O(n)**   | We loop through `nums` once                |
| 💾 Space | **O(n)**   | We create an array twice as long as `nums` |

---

## 🎨 **Visual Flow Diagram**

```
        ┌────────────────────┐
        │  nums = [1, 2, 3]  │
        └────────┬───────────┘
                 │
                 ▼
     ┌──────────────────────────┐
     │  ans = [1, 2, 3, _, _, _] │ ← fill first half
     └──────────────────────────┘
                 │
                 ▼
     ┌──────────────────────────┐
     │  ans = [1, 2, 3, 1, 2, 3] │ ← fill second half
     └──────────────────────────┘
                 │
                 ▼
        🎉 Return ans!
```

---

## ⚡ **Common Mistake to Avoid**

Your earlier code was doing this ❌:

```cpp
if (i == (n - 1) && count <= 1) {
    i = 0;
    count++;
}
```

* `count` resets every loop 😬
* `i` keeps resetting → **infinite loop** 🌀
* Leads to **Memory Limit Exceeded 💥**

---

## 🧠 **Key Takeaway**

> Don’t manually reset loop variables inside a `for` loop.
> Instead, design your loop bounds smartly! ⚙️

---

## 🌈 **Summary**

| Concept       | Description                                    |
| ------------- | ---------------------------------------------- |
| Task          | Concatenate array with itself                  |
| Core Idea     | Repeat each element twice                      |
| Best Solution | Single loop, O(n) time                         |
| Pitfall       | Avoid resetting loop variables inside the loop |


