
This code is a **classic HackerRank problem: *Attribute Parser (HRML)***.
Your solution is actually **clean, efficient, and interview-worthy** 👏
I’ll explain it so deeply that **you’ll never forget this pattern again**.

---

# 🧠 INTUITION (Big Picture Thinking)

Think of this problem like navigating **HTML / XML**:

```html
<tag1 value = "Hello">
    <tag2 name = "World">
    </tag2>
</tag1>
```

And queries like:

```
tag1.tag2~name
```

So the core challenge is:

> ❓ **How do we uniquely identify an attribute inside nested tags?**

### 💡 Senior Dev Insight:

👉 Use a **FULL PATH KEY**
Just like a file system:

```
/home/user/docs/file.txt
```

Here, the **unique key** becomes:

```
tag1.tag2~name
```

🔥 That’s the whole idea behind this solution.

---

# 🏗️ CORE DATA STRUCTURES

## 1️⃣ Tag Stack 🧱

```cpp
vector<string> tag_stack;
```

📌 Acts like a **directory stack**
Keeps track of where we currently are in the tag hierarchy.

Example:

```
<tag1>
  <tag2>
```

👉 `tag_stack = ["tag1", "tag2"]`

---

## 2️⃣ Attribute Map 🗺️

```cpp
map<string, string> attrs;
```

📌 Stores:

```
KEY   → VALUE
```

Example:

```
"tag1.tag2~name" → "World"
```

Why `map`?

* 🔍 Fast lookup
* 🎯 Perfect for query-based problems

---

# ⚙️ HELPER FUNCTION — `insert_attr`

```cpp
void insert_attr(string &name , string &val)
```

### 🎯 Purpose:

Create a **unique full-path key** and store the attribute value.

---

### 🧩 Step-by-Step Visual

#### Current stack:

```
["tag1", "tag2"]
```

#### Attribute:

```
name = "value"
val  = "Hello"
```

#### Build path:

```
tag1.tag2~value
```

📦 Store it:

```cpp
attrs["tag1.tag2~value"] = "Hello";
```

---

### 🔍 Code Breakdown

```cpp
for(string &str : tag_stack)
    full += str + ".";
```

➡️ Builds: `tag1.tag2.`

```cpp
full.pop_back();
```

➡️ Removes trailing `.` → `tag1.tag2`

```cpp
full += "~" + name;
```

➡️ `tag1.tag2~value`

---

# 🔄 MAIN LOGIC FLOW

---

## 📥 Input

```cpp
int n, q;
cin >> n >> q;
```

* `n` → number of HRML lines
* `q` → number of queries

---

## 🔁 Parsing HRML Lines

### 🧠 Strategy:

Read **character-by-character**, then decide:

* Opening tag?
* Closing tag?
* Attributes present?

---

### 🔍 Detect Closing Tag

```cpp
if (cin.peek() == '/')
```

Example:

```html
</tag1>
```

👉 Pop from stack:

```cpp
tag_stack.pop_back();
```

🧹 Clean exit from scope.

---

### 🔓 Opening Tag (No Attributes)

```cpp
<tag1>
```

Handled by:

```cpp
if(name.back() == '>')
```

✔️ Push tag into stack

---

### 🏷️ Opening Tag (With Attributes)

```html
<tag1 value = "Hello" name = "World">
```

#### 🔁 Infinite loop (`for(;;)`)

Reads:

```cpp
attr_name >> eq >> attr_val
```

Example:

```
value = "Hello"
```

---

### 🧼 Cleaning Attribute Values

Raw input:

```
"Hello">
```

Cleanup steps:

```cpp
attr_val.pop_back();      // >
attr_val.pop_back();      // "
attr_val = attr_val.substr(1); // remove opening "
```

💎 Result:

```
Hello
```

📦 Stored via `insert_attr(...)`

---

# 🔍 QUERY PROCESSING

```cpp
if(attrs.find(quer) != attrs.end())
    cout << attrs[quer];
else
    cout << "Not Found!";
```

🎯 **O(log N)** lookup
⚡ Fast and clean

---

# 🧪 COMPLETE FLOW (VISUAL)

```
<tag1>
   <tag2 name="World">
   </tag2>
</tag1>
```

🧱 Stack evolution:

```
[] 
["tag1"]
["tag1","tag2"]
["tag1"]
[]
```

🗺️ Map entry:

```
"tag1.tag2~name" → "World"
```

---

# ⏱️ TIME & SPACE COMPLEXITY

## ⏳ Time Complexity

| Operation     | Complexity   |
| ------------- | ------------ |
| Parsing HRML  | **O(N)**     |
| Building keys | **O(depth)** |
| Query lookup  | **O(log M)** |

👉 Overall: **O(N log N)** (safe & efficient)

---

## 🧠 Space Complexity

| Structure | Space               |
| --------- | ------------------- |
| Stack     | O(depth)            |
| Map       | O(total attributes) |

---

# 🏆 WHY THIS SOLUTION IS INTERVIEW-GOLD

✅ Uses **stack-based parsing**
✅ Uses **path flattening technique**
✅ Efficient query resolution
✅ Clean separation of concerns
✅ Easily extensible

💬 This same idea appears in:

* XML parsers
* DOM traversal
* Configuration systems
* Compiler design (symbol tables)

---

# 🧠 KNOWLEDGE YOU SHOULD REMEMBER FOREVER

🔑 **Key Insight**

> *Whenever nested data needs fast lookup → flatten it into a unique key*

💥 This idea alone solves **tons of problems**.

---


