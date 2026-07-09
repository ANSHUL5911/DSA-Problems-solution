<div align="center">

# 🌟 Kth Smallest Element in an Array
### 🚀 Priority Queue (Max Heap) | C++ | GFG

<img src="https://readme-typing-svg.herokuapp.com?font=Poppins&size=28&duration=3500&color=36BCF7&center=true&vCenter=true&width=700&lines=Find+the+Kth+Smallest+Element+Efficiently!;Master+Heap+Problems+Like+a+Pro!;C%2B%2B+%7C+STL+%7C+Priority+Queue" />

<br>

![](https://img.shields.io/badge/Difficulty-Medium-ffb020?style=for-the-badge&logo=target&logoColor=white)
![](https://img.shields.io/badge/Topic-Heaps-blueviolet?style=for-the-badge&logo=buffer&logoColor=white)
![](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![](https://img.shields.io/badge/Time-O(NlogK)-00C853?style=for-the-badge&logo=clockify&logoColor=white)
![](https://img.shields.io/badge/Space-O(K)-29B6F6?style=for-the-badge&logo=stackshare&logoColor=white)

</div>

---

## 🎯 Problem Statement

Given an array `arr[]` and an integer `k`, find the **Kth Smallest Element** present in the array.

---

# 💡 Intuition

The brute-force approach would be:

1. Sort the entire array.
2. Return the element at index `k-1`.

But sorting requires:

```text
Time Complexity = O(N log N)
```

We can do better using a **Max Heap**.

---

# 🔥 Primary Approach (Your Solution)

### Idea

Maintain a **Max Heap of size K**.

- Insert the first `k` elements into the heap.
- The heap's top stores the largest among these `k` elements.
- Traverse the remaining elements:
  - If the current element is greater than or equal to heap top, ignore it.
  - Otherwise:
    - Remove heap top
    - Insert the smaller element

At the end, the heap contains the **k smallest elements**, and its top is the **Kth smallest element**.

---

## 🧠 Dry Run

```text
arr = [7, 10, 4, 3, 20, 15]
k = 3

Initial Heap:
[10, 7, 4]

Current top = 10

Element = 3
3 < 10

Remove 10
Insert 3

Heap:
[7, 4, 3]

Element = 20
20 >= 7
Ignore

Element = 15
15 >= 7
Ignore

Top = 7

Answer = 7
```

---

# 💻 Primary Solution (Max Heap of Size K)

```cpp
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        int n = arr.size();

        for(int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }

        for(int i = k; i < n; i++) {
            if(arr[i] >= pq.top()) {
                continue;
            }

            pq.pop();
            pq.push(arr[i]);
        }

        return pq.top();
    }
};
```

---

# ⚡ Optimized Solution (Min Heap)

Instead of storing only `k` elements, we can:

1. Create a Min Heap using all elements.
2. Remove the smallest element `k-1` times.
3. The top now becomes the Kth smallest element.

---

## 💻 Optimized Code

```cpp
class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq(arr.begin(), arr.end());

        while(--k) {
            pq.pop();
        }

        return pq.top();
    }
};
```

---

# 📊 Complexity Analysis

| Approach | Time | Space |
|----------|-------|--------|
| Max Heap of Size K | O(N log K) | O(K) |
| Min Heap of All Elements | O(N + K log N) | O(N) |
| Sorting | O(N log N) | O(1) |

---

# 🎨 Visual Representation

```text
Max Heap Approach

Array
 ↓
Take first K elements
 ↓
Build Max Heap
 ↓
Traverse remaining elements
 ↓
Smaller element found ?
      /      \
    Yes       No
     |          |
Pop Top      Ignore
Push Element
      |
Continue
      |
Heap Top = Kth Smallest
```

---

# 🏆 Why the Max Heap Approach is Better?

✅ Stores only K elements

✅ Less memory usage

✅ Faster when K is small

✅ Avoids sorting the entire array

✅ Preferred solution in interviews

---

<div align="center">

### 🌟 If this solution helped you, consider giving the repository a star!

<img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExbGN5eWt4dDkzbnliY2JmbjFxN2NjOTV4dm1wc3N0MjM4cDZ1czNhYyZlcD12MV9naWZzX3NlYXJjaCZjdD1n/l3vR85PnGsBwu1PFK/giphy.gif" width="350">

### ⭐ Happy Coding! ⭐

**Keep Learning • Keep Building • Keep Growing 🚀**

</div>