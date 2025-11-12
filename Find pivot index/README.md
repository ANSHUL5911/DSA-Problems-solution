

## 🎯 **Problem Goal**

> Find the **pivot index** in an array —
> an index where the **sum of all elements to the left = sum of all elements to the right**.

---

### 💡 **Example**

```
nums = [1, 7, 3, 6, 5, 6]
```

Visual representation 👇

| Index |  0  |  1  |  2  |  3  |  4  |  5  |
| :---- | :-: | :-: | :-: | :-: | :-: | :-: |
| Value |  1  |  7  |  3  |  6  |  5  |  6  |

Now look at index **3 (value = 6)** 🟩

* Left side sum = 1 + 7 + 3 = **11**
* Right side sum = 5 + 6 = **11**

✅ **Both sides equal → Pivot index = 3**

---

## 🧠 INTUITION

Let’s think like a senior developer 🧑‍💻:

* Instead of calculating **left** and **right** sums again and again (which is costly ❌),
  we can be *smart* 💡 — just **track** them as we move through the array.

* Initially, we know the **total sum** of the array.

  * Think of it like having a bag 💼 full of all elements’ weights.
  * As we move from left ➡️ right, we remove items one by one from that bag.
  * The remaining items’ total weight is our **right sum**.

* At any point:

  ```
  total_sum = left_sum + nums[i] + right_sum
  ```

  So,

  ```
  right_sum = total_sum - left_sum - nums[i]
  ```

👉 If at any index, `left_sum == right_sum`,
that index is our **pivot** ⚖️

---

## 🧩 APPROACH (Step-by-Step Flow)

### Step 1️⃣ — Calculate Total Sum

We start by calculating the **total sum** of all elements.
This represents the **entire weight** of the array 🎒.

```cpp
int sum_r = 0;
for(int i = 0; i < n; i++)
    sum_r += nums[i];
```

---

### Step 2️⃣ — Iterate Through Each Element

We maintain two sums:

* `sum_l` 🟦 (Left Sum)
* `sum_r` 🟥 (Right Sum)

Initially:

* `sum_l = 0`
* `sum_r = total_sum`

For each element `nums[i]`:

1. Remove `nums[i]` from `sum_r` → because we are standing *on* it now.
2. Compare `sum_l` and `sum_r`.

   * If they’re equal ✅ → Pivot found.
3. Add `nums[i]` to `sum_l` → move forward for next iteration.

---

### 🧭 Visualization

Let's take the same example:

```
nums = [1, 7, 3, 6, 5, 6]
```

| Step  |  i  | nums[i] | sum_l (left) | sum_r (right before check) |      Equal?      |
| :---- | :-: | :-----: | :----------: | :------------------------: | :--------------: |
| Start |  -  |    -    |       0      |             28             |         -        |
| 1     |  0  |    1    |       0      |             27             |         ❌        |
| 2     |  1  |    7    |       1      |             20             |         ❌        |
| 3     |  2  |    3    |       8      |             17             |         ❌        |
| 4     |  3  |    6    |      11      |             11             | ✅ PIVOT FOUND 🎯 |

---

## 🧮 COMPLEXITY ANALYSIS

| Metric                  | Complexity | Reason                                               |
| :---------------------- | :--------- | :--------------------------------------------------- |
| **Time Complexity** ⏱️  | `O(n)`     | One pass to find total sum + one pass to check pivot |
| **Space Complexity** 💾 | `O(1)`     | Only using constant extra variables                  |

---



## 🧩 Quick Recap with Visual Metaphor 🖼️

Imagine the array as a **see-saw ⚖️**:

* Each index is a possible *pivot*.
* Left weights = sum of left numbers 🟦
* Right weights = sum of right numbers 🟥
* The point where it **balances perfectly** → Pivot Index 🎯

---

## 🏁 Final Output Example

**Input:** `[1, 7, 3, 6, 5, 6]`
**Output:** `3`

✅ Because the see-saw balances perfectly at index **3** 💪

---



