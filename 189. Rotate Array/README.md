

## 🔎 Problem Intuition

We’re asked to **rotate an array by `k` steps** to the right.
Example:

```
Input:  nums = [1,2,3,4,5,6,7], k = 3  
Output: [5,6,7,1,2,3,4]
```

The last `k` elements should "wrap around" and appear at the beginning.

Think of it like a **circular shift ⭕** — after rotating, the array looks like we "pushed" elements forward, and those that went out on the right come back from the left.

---

## 💡 Approach (Used in Your Code)

1. ✅ Create a **temporary array (`temp`)** of the same size.
2. ✅ For every element at index `i` in `nums`, compute its new position:

   ```
   new_index = (i + k) % nums.size()
   ```

   * `%` ensures wrapping around (like a clock going back to 0 after 12 ⏰).
3. ✅ Place `nums[i]` at `temp[new_index]`.
4. ✅ Finally, copy `temp` back to `nums`.

---

## 🛠️ Example Walkthrough

Let’s take: `nums = [10,20,30,40,50], k = 2`

* `i = 0 → (0+2)%5 = 2 → temp[2] = 10`
* `i = 1 → (1+2)%5 = 3 → temp[3] = 20`
* `i = 2 → (2+2)%5 = 4 → temp[4] = 30`
* `i = 3 → (3+2)%5 = 0 → temp[0] = 40`
* `i = 4 → (4+2)%5 = 1 → temp[1] = 50`

Result → `temp = [40,50,10,20,30]` 🎉

---

## ⏱️ Complexity Analysis

* **Time Complexity:**

  * One loop through `nums` → **O(n)**
* **Space Complexity:**

  * Extra `temp` array → **O(n)**

⚡ This is simple and efficient, but not *in-place*.

---

## 🏆 Possible Improvement

If memory is a concern, we can do it **in-place** with:

1. Reverse the whole array
2. Reverse the first `k` elements
3. Reverse the remaining `n-k` elements

That way we get the same result in **O(1) extra space**.

---

✅ **Summary**:

* Intuition → Think circular shift ⭕
* Approach → Place each element at `(i+k)%n` in a temp array 📦
* Complexity → `O(n)` time, `O(n)` space
* Improvement → Use reverse method for in-place `O(1)` space 🔄


