

## 🎯 **Goal of the Program**

> 👉 To **find and print all repeating elements** in an integer array.

Example:
🧩 Input → `{1, 1, 2, 3, 4, 4, 5, 2}`
🧾 Output → `1 2 4`

---

## 💡 **Intuition (The “Why” behind it)**

When we want to find duplicate numbers in an array, we can:

1. Compare every element with every other element 👀
2. If they match → it means that element is **repeating** 🔁
3. Store it somewhere (in another array `dup[]`)
4. Finally, print those stored duplicates once each ✨

---

## 🧠 **Step-by-Step Approach (The “How” part)**

Let’s go line by line with a **visual guide** 🧩

---

### 🧱 **1. Function Declaration**

```cpp
void findRepeatingElements(int arr[], int n)
```

➡️ Takes the array `arr[]` and its size `n` as input.

---

### ⚙️ **2. Variables Setup**

```cpp
int cnt = 0;
int dup[n];
```

* `cnt` keeps track of how many duplicates we found so far.
* `dup[]` temporarily stores all duplicate elements.

---

### 🔄 **3. Nested Loop — Brute Force Comparison**

```cpp
for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
        if(arr[i] == arr[j]) dup[cnt++] = arr[i];
    }
}
```

🧩 **Logic visualization:**

| i | j | arr[i] | arr[j] | Match? | Action     |
| - | - | ------ | ------ | ------ | ---------- |
| 0 | 1 | 1      | 1      | ✅      | dup[0] = 1 |
| 0 | 2 | 1      | 2      | ❌      | -          |
| 1 | 2 | 1      | 2      | ❌      | -          |
| 2 | 7 | 2      | 2      | ✅      | dup[1] = 2 |
| 3 | 4 | 3      | 4      | ❌      | -          |
| 4 | 5 | 4      | 4      | ✅      | dup[2] = 4 |

So finally, `dup[] = {1, 2, 4}`
and `cnt = 3`.

---

### 🖨️ **4. Printing Unique Duplicates**

```cpp
for(int i = 0; i < cnt; i++)
    if(dup[i] != dup[i+1]) cout << dup[i] << " ";
```

➡️ This ensures we **don’t print the same duplicate twice** (in case there were more than 2 identical elements).

---

## 🔍 **Dry Run Example**

Input:

```cpp
int arr[] = {1, 1, 2, 3, 4, 4, 5, 2};
```

| Step          | Action  | dup[] Contents | cnt |
| ------------- | ------- | -------------- | --- |
| Compare (1,1) | Match ✅ | {1}            | 1   |
| Compare (2,2) | Match ✅ | {1,2}          | 2   |
| Compare (4,4) | Match ✅ | {1,2,4}        | 3   |

Final Output:

```
The repeating elements are: 1 2 4
```

---

## 📊 **Time & Space Complexity**

| Type         | Complexity | Explanation                                                                   |
| ------------ | ---------- | ----------------------------------------------------------------------------- |
| ⏱ **Time**   | **O(n²)**  | Because we compare each element with all elements ahead of it (nested loops). |
| 💾 **Space** | **O(n)**   | The `dup[]` array may store up to `n` duplicates in the worst case.           |

---

## ⚠️ **Limitations**

🚫 Works fine for small arrays, but **inefficient for large n** (due to O(n²) comparisons).
🚫 Doesn’t handle the case where **duplicates are far apart** efficiently.
🚫 Might print wrong values if duplicates are not sorted in `dup[]`.

---

## ✅ **Optimized Approach (for learners)**

You can do the same task more efficiently using a **hash map** 🧮:

```cpp
unordered_map<int, int> freq;
for(int x : arr) freq[x]++;
for(auto it : freq)
    if(it.second > 1)
        cout << it.first << " ";
```

💥 Complexity →

* Time: **O(n)**
* Space: **O(n)**

---

## 🎨 **Visual Summary**

```
🧩 Input → {1, 1, 2, 3, 4, 4, 5, 2}
🔁 Compare all pairs
📦 Store repeating ones in dup[]
🖨️ Print unique duplicates → 1 2 4
```

---

## 🧠 Key Takeaway

> This code teaches the **brute-force foundation** 🔍 of finding duplicates — great for beginners to understand **pairwise comparison**, **nested loops**, and **array manipulation** before moving to optimized methods.


