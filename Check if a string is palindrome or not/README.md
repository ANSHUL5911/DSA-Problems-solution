

## 🧠 **Intuition**

A **palindrome** is a word/phrase that reads the same **forward 🔜 and backward 🔙**.
👉 Example:

* `"madam"` ✅
* `"racecar"` ✅
* `"hello"` ❌

The simplest way to check:

* Compare the **first** character with the **last**,
* then the **second** with the **second-last**,
* keep moving **inward** until the middle.

If **all pairs match**, it’s a palindrome! 🎯

---

## 🛠️ **Approach (Two-Pointer Technique)**

Think of two guards 👮 👮 checking a tunnel:

```
s = "madam"

start → m a d a m ← end
         ↑     ↑
```

* Guard **Start** stands at index `0`.
* Guard **End** stands at index `n-1`.
* While moving inward:

  * If `s[start] != s[end]` → ❌ Not palindrome.
  * Else → ✅ Move both one step.

Repeat until they **meet in the middle** 🏰.

---

## 📜 **Code (Cleaned & Readable)**

```cpp
bool checkPalindrome(string s) {
    int start = 0;
    int end = s.size() - 1;

    while (start <= end) {
        if (s[start] != s[end]) {
            return false;  // ❌ mismatch
        }
        start++;
        end--;
    }
    return true; // ✅ all matched
}
```

---

## ⏱️ **Complexity Analysis**

* **Time Complexity**:
  We only check each character **once**, so `O(n)` 💨.

* **Space Complexity**:
  No extra storage except a few variables → `O(1)` ⚡.

---

## 🎨 **Visual Graphic**

Imagine this 👇

```
   "radar"
    ↓   ↓
   (r == r) ✅
     ↓ ↓
   (a == a) ✅
      ↓
      d ✅
```

All pairs matched = **Palindrome** 🎉

If even **one pair** mismatches → ❌ Not a palindrome.

---

## 🌟 Why This Approach Rocks

✔️ Simple and easy to understand
✔️ Efficient (linear time, constant space)
✔️ Works for any string input

