

# 📝 Problem Statement

👉 Replace every **space `' '`** in a string with **`@40`**.

Example:

```
Input:  "I love C++"
Output: "I@40love@40C++"
```

---

# 🧠 Intuition

When we see a space in the original string:

* We **cannot simply overwrite it with `@40`**, because `@40` is **3 characters long**, not 1.
* Instead, we need to **build a new string**:

  * If character = space → insert `@40`
  * Else → insert character as is

Think of it like **copy-pasting into a new notebook** 📝:

* If the word is normal → copy directly
* If the word is a space → instead of writing `' '`, write `@40`

---

# ⚙️ Approach (Step by Step with Flowchart Style)

📦 Let’s take input string = `"I love C++"`

1️⃣ Initialize an **empty string** `temp = ""`

2️⃣ Traverse the string character by character

* 🔎 If current char = `' '`
  ➝ Push `'@'`, `'4'`, `'0'` into `temp`

* ✅ Else
  ➝ Push the same char into `temp`

3️⃣ After loop ends → return `temp`

---

# 🎨 Visual Walkthrough

```
Original String: "I love C++"
```

➡️ Step 1: Read `'I'` → not space → `temp = "I"`

➡️ Step 2: Read `' '` → space → add `@40` → `temp = "I@40"`

➡️ Step 3: Read `'l'` → `temp = "I@40l"`

➡️ Step 4: Read `'o'` → `temp = "I@40lo"`

➡️ Step 5: Read `'v'` → `temp = "I@40lov"`

➡️ Step 6: Read `'e'` → `temp = "I@40love"`

➡️ Step 7: Read `' '` → add `@40` → `temp = "I@40love@40"`

➡️ Step 8: Read `'C'` → `temp = "I@40love@40C"`

➡️ Step 9: Read `'+'` → `temp = "I@40love@40C+"`

➡️ Step 🔟: Read `'+'` → `temp = "I@40love@40C++"`

✅ Final Output:

```
"I@40love@40C++"
```

---

# ⏳ Time & Space Complexity Analysis

⚡ **Time Complexity:**

* We loop through all characters **once** → **O(n)**
  (where `n = length of string`)

⚡ **Space Complexity:**

* We create a new string (`temp`) that could be up to **3n in worst case** (if every char is a space).
* So complexity = **O(n)** additional space.

---

# 📊 Big Picture

✔️ **Why this approach?**

* Simple, clean, and easy to debug 🧹
* Directly builds the result → avoids messy in-place modifications

✔️ **When is this useful?**

* Encoding strings in URLs
* Preprocessing inputs for databases
* Sanitizing user input

---

# 🎯 Summary

✨ You used:

* **Traversal** → iterate once 🔄
* **String building** → efficient with `push_back` 🧩
* **Replacement logic** → replace `' '` with `@40`

👉 Complexity is **O(n)** time & **O(n)** space.
👉 Approach is **scalable, clean, and production-ready** ✅

---

🔥 Mentor’s Tip:
If you ever need to handle **very large strings** (like millions of characters), consider doing this **in-place** with a character array to save memory. But for most real-world apps, your approach is perfect 💯.


