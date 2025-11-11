

## 🧠 Intuition – *What Are We Trying to Do?*

Imagine your array 🧩 like a **train of sorted numbers**, and some compartments 🚆 have **duplicate passengers**.

We want to:

* Keep only **one passenger** per unique number ✅
* Move them all to the **front of the train** 🚉
* Fill the **remaining compartments** with placeholders (empty seats) 🪑

Example:

```
Before ➡️ [1, 1, 2, 3, 3]
After  ➡️ [1, 2, 3, _, _]
```

---

## 💡 Approach (Step-by-Step Visual)

### 🎯 Step 1: Start with first number

We **know** the first element is always unique.

🧮 `count = 1`
👉 It points to where the next **unique** element should go.

```
Index:  0 1 2 3 4
Array: [1,1,2,3,3]
Count: ^
```

---

### 🔁 Step 2: Traverse the array from index 1 ➡️ end

For each `nums[i]`, compare it with `nums[i - 1]`.

#### ✅ If different

That means it’s a **new unique** element!

➡️ Copy it to position `count`
➡️ Increment `count`

#### ❌ If same

Ignore it (duplicate).

---

### 🧩 Step 3: Example Flow

| Step | i | nums[i] | nums[i-1] | Action                   | nums (after) | count |
| ---- | - | ------- | --------- | ------------------------ | ------------ | ----- |
| 1    | 1 | 1       | 1         | duplicate → skip         | [1,1,2,3,3]  | 1     |
| 2    | 2 | 2       | 1         | unique → move to index 1 | [1,2,2,3,3]  | 2     |
| 3    | 3 | 3       | 2         | unique → move to index 2 | [1,2,3,3,3]  | 3     |
| 4    | 4 | 3       | 3         | duplicate → skip         | [1,2,3,3,3]  | 3     |

✅ Final Result:
`[1,2,3,3,3]`
(we can later replace extra values with placeholders)

---

### 🖼️ Simple Visual Diagram

```
[1, 1, 2, 3, 3]
 ↑     ↑
unique found → move 2 here
↓
[1, 2, 2, 3, 3]
        ↑   ↑
unique found → move 3 here
↓
[1, 2, 3, 3, 3]
```

---

## ⚙️ Complexity Analysis

| Metric                  | Value    | Explanation                           |
| ----------------------- | -------- | ------------------------------------- |
| ⏱️ **Time Complexity**  | **O(n)** | Single pass through the array         |
| 🧮 **Space Complexity** | **O(1)** | Modifies in place, no extra space     |
| 💪 **Stability**        | ✅ Stable | Keeps first occurrence of each number |

---

## 💬 In Simple Words

> “We’re using two pointers —
> one for **scanning**, and one for **placing unique elements**.
> Everything happens in a single smooth pass 🚀.”

---

## 🧭 Key Takeaways

🌟 **Efficient:** O(n) time, O(1) space
🧩 **Clean logic:** compare neighbors, shift unique
🚫 **No erase() or push_back():** avoids TLE
🧠 **Scalable:** works even for huge input sizes

---

## 🖼️ Concept Visualization

```
 ┌──────────────────────────────────────────────┐
 |           Original Sorted Array              |
 |  [ 1, 1, 2, 3, 3 ]                          |
 └──────────────────────────────────────────────┘
             ⬇ unique filtering ⬇
 ┌──────────────────────────────────────────────┐
 |           Cleaned (Unique) Array              |
 |  [ 1, 2, 3, _, _ ]                          |
 └──────────────────────────────────────────────┘
```

---

## 💎 Final Thoughts from a Senior Dev 👨‍💻

> Always remember — **vector erase() is costly** 😅.
> In interviews or production, try to avoid O(n²) operations inside loops.
>
> Instead, think in **two-pointer patterns** 🧠 —
> it’s the secret weapon for most array problems. ⚔️

---



