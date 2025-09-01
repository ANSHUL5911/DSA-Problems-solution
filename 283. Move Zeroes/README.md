

## 🔎 **Problem Statement Recap**

We need to **move all zeroes to the end** of the array, while keeping the relative order of the non-zero elements intact.
👉 Example:
`[0,1,0,3,12] → [1,3,12,0,0]`

---

## 💡 **Intuition**

The main idea is simple:

* We want to **push all non-zero numbers forward** in their original order.
* And naturally, the **remaining space** will get filled with zeros.
* Instead of creating a new array ❌, we can do it **in-place** ✅ using two pointers.

---

## 🛠 **Approach**

We use the **Two Pointer Technique** 👫:

1. **Pointer `i`** → Tracks the position where the next non-zero element should be placed.
   (Think of it like a "slow runner" keeping the compacted list of non-zero numbers.)

2. **Pointer `j`** → Iterates through the array scanning each element.
   (The "fast runner" that looks ahead.)

👉 Steps:

* Traverse the array with `j`.
* If `nums[j]` is **non-zero**:

  * Swap it with `nums[i]`.
  * Increment `i` (because now the next non-zero should go one step further).
* Continue until the end.

---

## ✨ **Walkthrough Example**

Array: `[0,1,0,3,12]`

* `i=0, j=0 → nums[0]==0` → skip.
* `j=1 → nums[1]=1 (non-zero)` → swap(nums\[0], nums\[1]) → `[1,0,0,3,12]`, now `i=1`.
* `j=2 → nums[2]==0` → skip.
* `j=3 → nums[3]=3` → swap(nums\[1], nums\[3]) → `[1,3,0,0,12]`, now `i=2`.
* `j=4 → nums[4]=12` → swap(nums\[2], nums\[4]) → `[1,3,12,0,0]`, now `i=3`.

✅ Result: `[1,3,12,0,0]`

---

## ⏱ **Complexity Analysis**

* **Time Complexity:**

  * We traverse the array **once** → **O(n)**.
  * Each element is swapped at most once.
* **Space Complexity:**

  * No extra data structures used → **O(1)**.

This is **optimal** 💯.

---

## 🏆 **Key Takeaways**

* Used **two-pointer technique** to solve in-place.
* Preserves **order of non-zero elements**.
* Runs in **linear time with constant space**.
* Clean, efficient, and production-ready ✨.

---

