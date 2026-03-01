
---

# 🧠 1️⃣ Intuition — What Problem Are We Solving?

### 📌 Problem

Given:

* An array `arr`
* A fixed window size `k`

👉 Find the **maximum sum of any contiguous subarray of size `k`**.

---

## 💡 Why Sliding Window Works

If we try brute force:

```
For every starting index i:
    Compute sum of next k elements
```

⛔ That costs **O(n × k)** time.

Instead, notice something powerful:

If we know the sum of:

```
Window1: [a b c d]  (size k)
```

Then the next window is:

```
Window2:   [b c d e]
```

We don’t need to recompute everything!

We can:

```
New Sum = Old Sum 
          - element leaving window 
          + element entering window
```

That’s the core sliding window insight. 🚀

---

# 🔍 2️⃣ Step-by-Step Approach

Let’s visually track what your code does.

---

## 🔹 Step 1: Initialization

```cpp
int low  = 0;
int high = k - 1;
```

We define a window of size `k`:

```
[ low ........ high ]
```

Initial window:

```
Index: 0 1 2 3 4 5 6
Array: 2 3 5 1 6 4 8
Window size k = 3

Window: [2 3 5]
```

Then compute initial sum:

```cpp
for(int i = low; i<=high;i++){
    sum += arr[i];
}
```

This gives the first valid window sum.

---

## 🔹 Step 2: Window Maintenance (Sliding)

Core loop:

```cpp
while(high < n)
```

Inside:

### ① Update result

```cpp
res = max(res, sum);
```

### ② Slide window right

```cpp
low++;
high++;
```

### ③ Update sum efficiently

```cpp
sum = sum + arr[high] - arr[low - 1];
```

This is the magic:

```
Remove: arr[low-1]
Add:    arr[high]
```

---

## 🧊 Visual Sliding Representation

```
Before Slide:
[ 2 3 5 ] 1 6 4 8
  ^     ^
 low   high

After Slide:
2 [ 3 5 1 ] 6 4 8
    ^     ^
   low   high
```

We:

* Removed `2`
* Added `1`

No recomputation needed.

---

## 🔹 Step 3: Termination Logic

You stop when:

```cpp
if(high == n) break;
```

This prevents out-of-bounds access.

The loop ends after the last valid window is processed.

---

# ⏱ 3️⃣ Complexity Analysis

Let `n = arr.size()`.

---

### 🟢 Time Complexity: **O(n)**

Breakdown:

* First window sum → O(k)
* Sliding through remaining windows → O(n - k)

Total:

```
O(k + (n - k)) = O(n)
```

✅ Tight bound: **Θ(n)**

---

### 🟢 Space Complexity: **O(1)**

We use:

* `sum`
* `res`
* `low`, `high`

No extra data structures.

✅ Tight bound: **Θ(1)**

---

# ⚠️ 4️⃣ Edge Cases & Robustness Notes

### ❗ 1. What if `k > n`?

Your code assumes valid input.

Safer version:

```cpp
if(k > arr.size()) return 0;
```

---

### ❗ 2. All numbers negative

Your code initializes:

```cpp
int res = 0;
```

If array is:

```
[-5, -2, -8, -1]
k = 2
```

Correct answer = -3
But your function returns 0 ❌

### ✅ Fix:

Initialize:

```cpp
int res = sum;
```

This ensures negative cases work correctly.

---

### ❗ 3. Integer overflow

If values are large:

```cpp
vector<int> arr = {1e9, 1e9, 1e9};
```

Better use:

```cpp
long long sum = 0;
```

---

# 🧾 5️⃣ Clean Pseudocode

```
FUNCTION maxSubarraySum(arr, k):

    n = length(arr)
    IF k > n:
        RETURN 0

    sum = 0
    
    // Build first window
    FOR i from 0 to k-1:
        sum += arr[i]

    maxSum = sum

    // Slide window
    FOR i from k to n-1:
        sum = sum + arr[i] - arr[i-k]
        maxSum = max(maxSum, sum)

    RETURN maxSum
```

---

# 💻 6️⃣ Clean & Robust C++ Snippet

```cpp
int maxSubarraySum(vector<int>& arr, int k) {
    int n = arr.size();
    if (k > n) return 0;

    long long sum = 0;

    // 🟢 Build first window
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    long long maxSum = sum;

    // 🔄 Slide the window
    for (int i = k; i < n; i++) {
        sum += arr[i];        // add incoming
        sum -= arr[i - k];    // remove outgoing
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}
```

Cleaner, safer, more readable.

---

# 🎯 7️⃣ Common Pitfalls (Very Important)

| Mistake                             | Why It Happens            | Fix                            |
| ----------------------------------- | ------------------------- | ------------------------------ |
| `res = 0`                           | Fails for negative arrays | Initialize to first window sum |
| Wrong loop condition                | Off-by-one error          | Use `i = k → n-1`              |
| Updating sum before checking bounds | Access arr[n]             | Carefully order operations     |
| Forgetting initial window sum       | Garbage result            | Always compute first window    |

---

# 🔄 8️⃣ Alternatives & Context

## 🔹 A) Prefix Sum Approach

We build:

```
prefix[i] = sum of elements 0 → i
```

Then any window sum:

```
sum(i to j) = prefix[j] - prefix[i-1]
```

Time: O(n)
Space: O(n)

Sliding window is better because it uses **O(1) space**.

---

## 🔹 B) Kadane’s Algorithm (Comparison)

Kadane solves:

> Maximum subarray of ANY size.

Your problem is:

> Maximum subarray of FIXED size k.

Kadane doesn’t directly apply unless window size is flexible.

Time: O(n)
Space: O(1)

---

# 🏁 Final Mental Model

Think of it like:

```
🟦 A fixed-size glass (k)
🟨 You slide it over a row of numbers
🔄 Instead of refilling from scratch,
   you pour out the leftmost water
   and pour in the new rightmost water
```

Efficient. Clean. Linear time.

---

# 🚀 Summary for Teammates

* Problem: Max sum of fixed-size subarray
* Technique: Sliding Window
* Time: Θ(n)
* Space: Θ(1)
* Key Insight: Reuse previous window sum
* Critical Fix: Initialize `res = first window sum`

---

