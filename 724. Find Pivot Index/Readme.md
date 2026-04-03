# 🚀 Pivot Index

## 📌 Problem Statement

Given an array of integers `nums`, return the **pivot index** where:

> 🔹 Sum of elements on the left == Sum of elements on the right

If no such index exists, return `-1`.

---

## 🧠 Intuition

Instead of recalculating left and right sums for every index ❌,
we optimize using a **running sum approach** ✅.

### 💡 Key Formula:

```
RIGHT = TOTAL_SUM - CURRENT_ELEMENT - LEFT_SUM
```

---

## ⚙️ Approach

1. Compute total sum of the array
2. Initialize `left = 0`
3. Traverse the array:

   * Calculate `right = total - nums[i] - left`
   * If `left == right`, return index
   * Update `left += nums[i]`
4. If no pivot found, return `-1`

---

## 🧾 Code Implementation

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;

        // Step 1: Calculate total sum
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        // Step 2: Find pivot index
        for(int i = 0; i < n; i++){
            right = sum - nums[i] - left;

            if(left == right){
                return i;
            }

            left += nums[i];
        }
        return -1;
    }
};
```

---

## 🔍 Example

```
Input:  [1, 7, 3, 6, 5, 6]
Output: 3
```

### 📊 Explanation

| Index | Left Sum | Right Sum |
| ----- | -------- | --------- |
| 3     | 11       | 11        |

✅ Pivot found at index `3`

---

## ⏱️ Complexity

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(n)       |
| Space | O(1)       |

---

## 🎯 Key Takeaways

✨ Avoid redundant computations
✨ Use **prefix sum technique**
✨ Convert brute force → optimized solution

---

## 🏆 Pro Tip

> Whenever you see problems involving **left vs right comparisons**,
> think **"Can I use prefix sums?"** 🤔

---

## 💡 Author

👨‍💻 Crafted with clean logic & optimization mindset
🚀 Keep learning, keep building!

---
