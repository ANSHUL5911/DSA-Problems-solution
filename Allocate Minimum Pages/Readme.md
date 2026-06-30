<div align="center">

# 📚 Allocate Minimum Number of Pages
### 💙 Binary Search on Answer | Greedy Allocation

<img src="https://readme-typing-svg.demolab.com?font=Poppins&weight=700&size=28&duration=3500&pause=1000&color=4FC3F7&center=true&vCenter=true&width=850&lines=Allocate+Minimum+Pages+Like+a+Pro!;Binary+Search+on+Answer;Greedy+Validation;Classic+Interview+Problem" />

<br>

<img src="https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Topic-Binary%20Search-blueviolet?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Approach-Greedy-success?style=for-the-badge"/>
<img src="https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge"/>

</div>

---

# ✨ Problem Statement

Given an array where each element represents the number of pages in a book, allocate books to **K students** such that

- Every student gets **at least one book**
- Books are allocated **contiguously**
- Minimize the **maximum pages assigned** to any student.

---

# 💡 Key Observation

We are **NOT** searching for the student.

We are searching for the answer:

> 🎯 **What is the minimum possible maximum pages a student can receive?**

That value lies between

```
Maximum book pages
        and
Total pages of all books
```

Hence...

> 🚀 Binary Search on Answer!

---

# 🎯 Search Space

```
Books

12 34 67 90

Maximum Book = 90

Total Pages = 203

Search Space

90 ----------------------------------203
```

Instead of checking every value...

Binary Search cuts the search space in half every iteration.

---

# 🧠 Greedy Validation

Suppose

```
limit = 113
```

Books

```
12 34 67 90
```

Student 1

```
12 + 34 + 67 = 113 ✅
```

Next book

```
90

Cannot fit
```

Assign to Student 2

```
90
```

Only 2 students needed.

Valid Allocation ✅

---

Suppose

```
limit = 80
```

```
12+34=46

+67 -> exceeds
```

Student 2

```
67
```

Next

```
90

Needs Student 3
```

If only 2 students exist...

❌ Invalid

---

# ⚙️ Algorithm

```
Binary Search

        |
        v

Guess maximum pages

        |
        v

Can we allocate books
within this limit?

        |

  Yes -------- No
   |             |
Smaller      Increase
Answer        Limit
```

---

# 📊 Dry Run

```
Books

12 34 67 90

Students = 2
```

Search Space

```
90........203
```

### Guess =146

Allocation

```
12+34+67=113

+90 exceeds

Student 2

90
```

Needed

```
2 students
```

Valid ✅

Search Left

---

### Guess =117

Still Valid ✅

---

### Guess =103

Needs 3 students ❌

Search Right

---

Eventually

```
Answer =113
```

---

# 🚀 Primary Solution (Your Approach)

```cpp
class Solution {
public:

    bool maxPages(vector<int> &arr, int k, int n, int limit) {

        int no_of_stud = 1;
        int pages = 0;

        for(int i=0;i<n;i++){

            if(arr[i]+pages<=limit){
                pages+=arr[i];
            }

            else{

                no_of_stud++;
                pages=arr[i];

                if(no_of_stud>k)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int> &arr, int k) {

        int n=arr.size();

        if(n<k)
            return -1;

        int low=0;
        int high=0;
        int res=-1;

        for(int i=0;i<n;i++){

            low=max(low,arr[i]);
            high+=arr[i];
        }

        while(low<=high){

            int guess=(low+high)/2;

            if(maxPages(arr,k,n,guess)){

                res=guess;
                high=guess-1;
            }

            else{

                low=guess+1;
            }
        }

        return res;
    }
};
```

---

# ⚡ Optimized Solution

### Improvements

✅ Cleaner helper function

✅ Early impossible allocation check

✅ Overflow-safe midpoint

✅ Better variable names

```cpp
class Solution {
public:

    bool canAllocate(vector<int>& books, int students, int maxPages) {

        int usedStudents = 1;
        int currentPages = 0;

        for (int pages : books) {

            if (currentPages + pages <= maxPages) {
                currentPages += pages;
            }
            else {

                usedStudents++;
                currentPages = pages;

                if (usedStudents > students)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int>& arr, int k) {

        int n = arr.size();

        if (n < k)
            return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canAllocate(arr, k, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};
```

---

# 🌟 Why Greedy Works?

Whenever a book fits inside the current student's limit...

```
Give it immediately.
```

Why?

Because delaying it to another student

- never reduces students
- may only increase students

Hence

Greedy always gives the optimal allocation for a fixed limit.

---

# 📈 Complexity Analysis

| Operation | Complexity |
|------------|------------|
| Finding Search Space | **O(N)** |
| Validation | **O(N)** |
| Binary Search Iterations | **log(Sum)** |

Overall

```
Time

O(N log(Sum of Pages))
```

```
Space

O(1)
```

---

# 🎯 Important Edge Cases

✅ Number of students > books

```
Return -1
```

---

✅ Single Student

```
Answer = Total Pages
```

---

✅ Students = Books

```
Answer = Maximum Book
```

---

✅ Large page values

Use

```cpp
mid = low + (high-low)/2;
```

to avoid overflow.

---

# 🧩 Binary Search Pattern

```
Minimize Maximum

↓

Guess Answer

↓

Can we achieve it?

↓

YES → Try Smaller

NO → Increase
```

This exact pattern appears in

- 📚 Allocate Books
- 🐄 Aggressive Cows
- 🍌 Koko Eating Bananas
- 🚢 Capacity To Ship Packages
- ⛽ Minimize Maximum Distance
- 🏠 Split Array Largest Sum

Master this pattern once...

Solve dozens of interview problems.

---

<div align="center">

# ⭐ If this helped you...

### Give it a ⭐ and Happy Coding 🚀

<img src="https://media.giphy.com/media/LmNwrBhejkK9EFP504/giphy.gif" width="260"/>

### 💙 "Binary Search doesn't search the array... it searches the Answer."

</div>