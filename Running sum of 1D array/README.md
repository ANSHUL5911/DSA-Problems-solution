

## 🧠 **Problem Intuition**

🧩 You're given an array `nums = [a₁, a₂, a₃, ..., aₙ]`
👉 You need to find a new array `runningSum` where each element is the **sum of all elements up to that index**.

💡 Mathematically:

```
runningSum[i] = nums[0] + nums[1] + ... + nums[i]
```

📘 **Example:**

```
Input:  [1, 2, 3, 4]
Output: [1, 3, 6, 10]
```

Here’s what’s happening step-by-step 👇

| Index (i) | nums[i] | sum till i | runningSum[i] |
| --------- | ------- | ---------- | ------------- |
| 0         | 1       | 1          | 1             |
| 1         | 2       | 1+2=3      | 3             |
| 2         | 3       | 3+3=6      | 6             |
| 3         | 4       | 6+4=10     | 10            |

---

## ⚙️ **Code Walkthrough (Approach)**

Let's break it down like a pro developer explaining to juniors 👨‍💻👇

```cpp
vector<int> runningSum(vector<int>& nums) {
    int n = nums.size();  // 🧮 Get total elements
```

➡️ We're storing the size of the array once (good practice 👌).

---

```cpp
    vector<int> temp;  // 🗃️ To store the running sum
    int sum = 0;       // 🔢 This will keep cumulative total
```

➡️ We keep a variable `sum` to hold the **progressive total**.
➡️ And a vector `temp` to store each new running sum.

---

```cpp
    for(int i = 0; i < n; i++) {
        sum = sum + nums[i];  // ➕ Add current number to total
        temp.push_back(sum);  // 🧱 Push new sum into result
    }
```

🌀 The loop builds the running sum **step-by-step**:

* Start with `sum = 0`
* Add each number in order
* Store the new total into `temp`

📈 Think of it as a **cumulative graph** where each new step goes higher and higher:

```
nums:       1    2    3    4
runningSum: 1 → 3 → 6 → 10
```

---

```cpp
    nums = temp;   // 🪄 Copy the results back to nums (optional)
    return nums;   // ✅ Return final running sum
}
```

➡️ This just replaces the input array with our result (not necessary, but fine).
Returning `temp` directly would also work.

---

## 🎯 **Final Visualization**

```
     ┌────────────┐
     │  nums[i]   │
     └─────┬──────┘
           │
           ▼
   ┌─────────────┐
   │ sum = sum + │◄─── keeps adding each number
   │    nums[i]  │
   └─────────────┘
           │
           ▼
   ┌────────────────┐
   │ temp.push_back │
   │     (sum)      │
   └────────────────┘
           │
           ▼
     🔁 Repeat for all elements
```

💥 Output after full loop → `[1, 3, 6, 10]`

---

## ⏱️ **Time & Space Complexity**

| Complexity Type | Explanation                               | Value    |
| --------------- | ----------------------------------------- | -------- |
| 🧭 Time         | Loop runs once through all `n` elements   | **O(n)** |
| 💾 Space        | Extra vector `temp` to store running sums | **O(n)** |

✅ **Efficient Solution:**

* Single traversal 🔁
* Constant extra operations per element 🧮

---

## 💡 **Optimization Tip (Senior Dev Trick 😏)**

We can do this **in-place**, saving memory 👇

```cpp
for(int i = 1; i < nums.size(); i++) {
    nums[i] += nums[i-1];
}
return nums;
```

🚀 Space Complexity → **O(1)**
Same logic, less memory — very common in coding interviews 💼

---

## 🏁 **Summary (Quick Recap Table)**

| Concept         | Description                                 |
| --------------- | ------------------------------------------- |
| 💭 Intuition    | Add elements cumulatively                   |
| ⚙️ Approach     | Maintain `sum` and store partial totals     |
| ⏱️ Time         | O(n)                                        |
| 💾 Space        | O(n) or O(1) if done in-place               |
| 🧰 Optimization | Modify `nums` directly to avoid extra space |

---


