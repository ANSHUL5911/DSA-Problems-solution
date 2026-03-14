
---

# 🐢⚡ Detect Cycle in Linked List — Floyd’s Tortoise & Hare

> **Goal:** Find the node where the cycle begins in a singly linked list.
> If no cycle exists, return `nullptr`.

---

# 🧩 Problem Overview

You are given the **head of a singly linked list**.

Sometimes the list might secretly contain a **loop** where a node points back to a previous node.

Your task:

✔ Detect if a cycle exists
✔ If yes, **return the node where the cycle begins**
✔ If not, return `nullptr`

⚠️ Constraint:
You **must not modify the linked list** and should aim for **constant extra space**.

---

# 💡 Core Idea

Instead of using extra memory like a `hash set`, we use a **two-pointer trick** known as:

### 🐢 Slow Pointer (Tortoise)

Moves **1 step at a time**

### ⚡ Fast Pointer (Hare)

Moves **2 steps at a time**

If a cycle exists, these two pointers will **eventually collide** inside the loop.

Think of it like **two runners on a circular track**:

* One runs slow
* One runs fast
* Eventually the fast runner **laps and meets** the slow runner.

---

# 🔍 Phase 1 — Detect the Cycle

We move both pointers until:

```
slow = slow -> next
fast = fast -> next -> next
```

Two possibilities occur:

### ❌ No Cycle

`fast` reaches `nullptr`.

### ✅ Cycle Exists

`slow == fast`

They meet somewhere **inside the loop**.

---

# 🎯 Phase 2 — Find the Cycle Start

Once they meet:

1️⃣ Reset `slow` to the **head**

2️⃣ Keep `fast` where they met

3️⃣ Move both **one step at a time**

```
slow = slow -> next
fast = fast -> next
```

📍 The point where they meet again is the **start of the cycle**.

---

# 🧠 Why This Works (Mathematical Insight)

Let:

```
L = distance from head to cycle start
C = cycle length
x = distance from cycle start to meeting point
```

When slow and fast meet:

```
slow distance = L + x
fast distance = 2(L + x)
```

Since fast moves twice as fast:

```
2(L + x) = L + x + kC
```

Simplifying:

```
L = kC − x
```

Which means:

➡ Starting one pointer at **head**
➡ Starting the other at **meeting point**

They will meet **exactly at the cycle start**.

Elegant, right? ✨

---

# 🧑‍💻 Implementation

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;

                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
```

---

# ⏱ Complexity Analysis

| Metric               | Complexity |
| -------------------- | ---------- |
| **Time Complexity**  | 🟢 `O(n)`  |
| **Space Complexity** | 🟢 `O(1)`  |

Why?

* Each pointer traverses the list **at most a few times**
* No extra data structures are used

---

# 📊 Example

```
Linked List:

3 → 2 → 0 → -4
    ↑       ↓
    └───────┘
```

Cycle begins at node:

```
2
```

Output:

```
Node with value = 2
```

---

# ✨ Key Takeaways

✔ Uses **Floyd’s Cycle Detection Algorithm**
✔ Elegant **two-pointer technique**
✔ **No extra memory required**
✔ Runs in **linear time**

---

⭐ **If this explanation helped you understand the algorithm better, consider upvoting it on LeetCode!**

---

## Interactive explanation page - https://linkedlistcycle2.netlify.app/ go check it out