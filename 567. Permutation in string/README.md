

# 🧩 Problem Statement

We need to check if any **permutation of `s1`** exists as a substring of `s2`.
Example:

```
s1 = "ab"
s2 = "eidbaooo"
```

👉 Permutations of `"ab"` are `"ab"` and `"ba"`.
Since `"ba"` exists inside `s2`, the answer = ✅ true.

---

# 🏗️ Approach: Sliding Window + Frequency Count

### 🎨 Visual Intuition

Think of `s1`’s character counts as a **lock 🔒**.
We slide a **window 🔑** of the same size across `s2`.
At each step, we check if the window’s character counts match the lock → if yes, the substring is a permutation.

---

### ⚙️ Step-by-Step

1. **Count frequencies of `s1`**

   ```cpp
   int count1[26] = {0};
   for (char c : s1) count1[c - 'a']++;
   ```

   Example: `"ab"` → `[1,1,0,0,...]`

   📊 This is our **reference lock**.

---

2. **Initialize first window in `s2`**

   ```cpp
   int count2[26] = {0};
   for (first window chars in s2) count2[c - 'a']++;
   ```

   Example: window `"ei"` → `count2 = [0,0,0,1,0,...]`

---

3. **Compare lock 🔒 and key 🔑**

   ```cpp
   if (checkEqual(count1, count2)) return true;
   ```

   If counts match → permutation found. ✅

---

4. **Slide the window → Move one char at a time**

   * Add the new char at the right.
   * Remove the old char at the left.
   * Compare counts again.

   ```cpp
   count2[s2[i] - 'a']++;               // add new char
   count2[s2[i - windowSize] - 'a']--;  // remove old char
   ```

   👉 This keeps the window always of length `|s1|`.

---

5. **Keep sliding until end**

   * If match found → return true
   * Else, after sliding through all → return false.

---

### 🖼️ Visual Sliding Window

`s1 = "ab"`, `s2 = "eidbaooo"`

```
Step 1: "ei"   ❌
Step 2: "id"   ❌
Step 3: "db"   ❌
Step 4: "ba"   ✅  (match!)
```

![Sliding Window Diagram](https://i.imgur.com/4AfVZgi.png)

---

# 📊 Complexity Analysis

### ⏱️ Time Complexity

* Build `count1` → O(|s1|)
* First window → O(|s1|)
* Sliding window → O(|s2|)
* Each comparison (`checkEqual`) → O(26) = O(1)
  👉 **Total = O(|s1| + |s2|)**

### 💾 Space Complexity

* Two arrays of size 26 (fixed)
  👉 **O(1)** (constant space)

---

# ✅ Key Takeaways

* 🔑 **Sliding Window + Frequency Array** is a powerful pattern for substring/permutation problems.
* 🚀 Runs in linear time (very efficient).
* 🧩 Always watch for **off-by-one errors** when updating the window.


