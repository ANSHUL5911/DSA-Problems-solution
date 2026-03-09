# 🐢🐇 Floyd's Cycle Detection Algorithm
### LeetCode #141 — Linked List Cycle

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Linked%20List-blue?style=for-the-badge)
![Technique](https://img.shields.io/badge/Technique-Two%20Pointers-orange?style=for-the-badge)
![Time](https://img.shields.io/badge/Time-O(n)-success?style=for-the-badge)
![Space](https://img.shields.io/badge/Space-O(1)-informational?style=for-the-badge)

---
## Interactive Explanation - https://linkedlistcycle.netlify.app/
---

## 📌 Problem Statement

> Given the `head` of a linked list, determine if the linked list has a **cycle** in it.
> A cycle exists if some node can be reached again by continuously following the `next` pointer.
> Return `true` if a cycle exists, otherwise return `false`.

---

## 🧠 Section 01 — The Intuition

### 🏃 Real-World Analogy: The Running Track

Imagine **two runners** on a circular track:

- 🐢 **Slow runner** jogs at normal speed
- 🐇 **Fast runner** sprints at double speed

> **If the track is circular (cycle exists):** The fast runner will eventually **lap** the slow runner — they *will* meet.
> **If the track is a straight road (no cycle):** The fast runner disappears into infinity — they *never* meet.

### 💡 The Key Insight

| Condition | What Happens | Result |
|---|---|---|
| 🔄 Cycle exists | Fast laps slow → they collide at same node | `return true` |
| 🏁 No cycle | Fast pointer hits `null` (end of list) | `return false` |

> **Zero extra memory. Zero visited arrays. Just two pointers.** That's the beauty of Floyd's algorithm. 🎯

---

## 🔗 Section 02 — Visualizing the Problem

### The Linked List (with a cycle)

```
Head
 │
 ▼
[1] ──→ [2] ──→ [3] ──→ [4] ──→ [5]
         ▲                        │
         └────────────────────────┘
              cycle back to node 2
```

- Nodes `2 → 3 → 4 → 5 → 2` form an **infinite loop**
- Node `1` is outside the cycle (the "tail")

---

### 📊 Step-by-Step Pointer Movement

> Starting: `slow = head (Node 1)`, `fast = head (Node 1)`

| Step | 🐢 Slow (moves +1) | 🐇 Fast (moves +2) | Same Node? |
|:----:|:-------------------:|:-------------------:|:----------:|
| Init | Node 1 | Node 1 | ⏭ Skip (both at start) |
| 1 | Node 2 | Node 3 | ❌ No |
| 2 | Node 3 | Node 5 | ❌ No |
| 3 | Node 4 | Node 3 | ❌ No |
| **4** | **Node 5** | **Node 5** | **✅ 🎯 MEET! Cycle Found!** |

> 🏆 They collide at **Node 5** — cycle confirmed!

---

## ⚙️ Section 03 — The Approach

```
ALGORITHM: Floyd's Tortoise and Hare
═══════════════════════════════════════
  STEP 1 ──→ Initialize slow = head, fast = head
  STEP 2 ──→ Enter loop while fast ≠ null AND fast.next ≠ null
  STEP 3 ──→ Move slow by 1 step  →  slow = slow.next
  STEP 4 ──→ Move fast by 2 steps →  fast = fast.next.next
  STEP 5 ──→ If slow == fast → CYCLE DETECTED → return true
  STEP 6 ──→ If loop ends (fast hit null) → return false
═══════════════════════════════════════
```

### 🔍 Why Each Step Matters

**Step 1 — Both start at head**
> Starting both at the same node ensures we don't miss any node and the comparison `slow == fast` is only checked *after* moving, so the initial collision at head doesn't trigger a false positive.

**Step 2 — The while condition: `fast != nullptr && fast->next != nullptr`**
> - `fast != nullptr` → guards against dereferencing null
> - `fast->next != nullptr` → guards against `fast->next->next` crashing on a list with even number of nodes

**Step 3 & 4 — Different speeds**
> The speed difference of 1 step per iteration means fast gains on slow by exactly 1 node per loop. If a cycle of length `λ` exists, they meet within `λ` iterations of entering the cycle.

**Step 5 — Pointer equality, NOT value equality**
> `slow == fast` compares **memory addresses** (same node object), not `val`. Two different nodes with the same value is NOT a cycle.

---

## 💻 Section 04 — The Code (Fully Annotated)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {

        // 🐢 Slow pointer — moves 1 step at a time (Tortoise)
        ListNode* slow = head;

        // 🐇 Fast pointer — moves 2 steps at a time (Hare)
        ListNode* fast = head;

        // ⚠️  Guard: fast must have a node AND a next-next node to jump safely
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;           // 🐢 Tortoise: one hop forward
            fast = fast->next->next;     // 🐇 Hare:     two hops forward

            // 🎯 Same memory address = same node = CYCLE DETECTED
            if (slow == fast) return true;
        }

        // 🏁 fast reached null → list ends normally → no cycle
        return false;
    }
};
```

### 🔑 The 3 Critical Lines

```cpp
slow = slow->next;          // Line A: Tortoise hops once
fast = fast->next->next;    // Line B: Hare hops twice
if (slow == fast) ...       // Line C: Collision check
```

> These 3 lines ARE the entire algorithm. Everything else is just safety guards.

---

## 📈 Section 05 — Complexity Analysis

### ⏱️ Time Complexity: `O(n)`

```
Case 1: No Cycle
─────────────────
fast pointer travels the entire list → O(n) iterations

Case 2: Cycle Exists
─────────────────────
Let:  n = total nodes
      λ = cycle length
      μ = nodes before cycle starts

Phase 1: fast reaches cycle entry  → O(μ) steps
Phase 2: fast catches slow inside  → O(λ) steps
Total                              → O(μ + λ) = O(n)
```

### 💾 Space Complexity: `O(1)`

```
Variables used:
  ListNode* slow  →  8 bytes (one pointer)
  ListNode* fast  →  8 bytes (one pointer)
  ─────────────────────────────────────────
  Total           →  O(1) constant space ✅
  
  No arrays. No hash sets. No recursion stack.
```

---

### ⚔️ Approach Comparison Table

| Approach | Time | Space | Modifies Input? | Interview Preferred? |
|---|:---:|:---:|:---:|:---:|
| 🗂️ HashSet (store visited nodes) | O(n) | ❌ O(n) | No | ❌ Wastes memory |
| ✏️ Mark nodes (set val = INT_MIN) | O(n) | ✅ O(1) | ⚠️ Yes | ❌ Destructive |
| 🏆 **Floyd's Two Pointer** | **O(n)** | **✅ O(1)** | **No** | **✅ Optimal!** |

> 🥇 Floyd's wins on **all three criteria**: fast, memory-efficient, and non-destructive.

---

## 🛡️ Section 06 — Edge Cases

All edge cases are handled **automatically** by the while-loop guard:

| Edge Case | Input | Expected Output | Handled? |
|---|---|:---:|:---:|
| 🫙 Empty list | `head = null` | `false` | ✅ |
| 1️⃣ Single node, no self-loop | `[1] → null` | `false` | ✅ |
| 🔄 Single node self-loop | `[1] → [1]` | `true` | ✅ |
| 🔚 Two nodes, cycle | `[1] → [2] → [1]` | `true` | ✅ |
| 📏 Two nodes, no cycle | `[1] → [2] → null` | `false` | ✅ |
| ♾️ Full circular list | All nodes in cycle | `true` | ✅ |
| 🐛 Cycle at the very last node only | Tail points back to head | `true` | ✅ |

---

## 💡 Senior Dev Tips & Interview Insights

### 🎤 Tip 1 — Communicate the Algorithm Name
> In an interview at **Google, Microsoft, or Amazon**, saying:
> *"I'll use Floyd's Cycle Detection algorithm — O(n) time, O(1) space"*
> instantly signals strong algorithmic knowledge. Name-dropping the algorithm is a green flag.

---

### 🔢 Tip 2 — Does Speed Have to Be 2x?
> No! Any speed ratio > 1 works (e.g., 3x, 4x). But **2x is optimal** because:
> - Simplest to implement
> - Guaranteed to detect cycle in at most `2 * cycle_length` steps
> - No risk of "jumping over" the slow pointer (which can happen at higher speeds in theory with uneven cycles)

---

### 🗺️ Tip 3 — This is the Gateway Algorithm
> Master this, and these become easy too:

| Problem | Connection |
|---|---|
| 🔍 LeetCode #142 — Find Cycle Start | Same algorithm + second phase math |
| 🔢 LeetCode #287 — Find Duplicate Number | Array treated as linked list with cycle |
| 😊 LeetCode #202 — Happy Number | Infinite sequence = cycle detection |

---

### ⚡ Tip 4 — Pointer vs Value Equality
```cpp
// ✅ CORRECT — comparing node addresses (same object in memory)
if (slow == fast)

// ❌ WRONG — comparing values (two nodes can have same val but be different nodes)
if (slow->val == fast->val)
```

---

### 🚫 Tip 5 — When Interviewer Says "O(1) Space"
> If the problem says **"solve without modifying the list"** and **"use constant space"** — Floyd's is the **only** valid approach. HashSet → O(n) space. Marking nodes → modifies input. Floyd's → ✅ both constraints satisfied.

---

## 🧩 Mathematical Proof (Bonus)

> *Why do they ALWAYS meet if a cycle exists?*

```
Let:
  μ  = distance from head to start of cycle
  λ  = length of the cycle

When slow enters the cycle, fast is already inside.
Fast is ahead of slow by some distance d.

Each step:
  slow moves +1 inside cycle
  fast moves +2 inside cycle
  → fast gains +1 on slow per step

After exactly λ steps (one full cycle traversal by slow),
fast has gained λ positions → they are at the same position.

∴ They ALWAYS meet within λ steps of slow entering the cycle.
∴ Total steps = O(μ + λ) = O(n)  ✅
```

---

## 🏁 Summary

```
┌─────────────────────────────────────────────────────────┐
│              FLOYD'S CYCLE DETECTION                    │
├─────────────────────────────────────────────────────────┤
│  Algorithm  │  Two Pointer (Tortoise & Hare)            │
│  Time       │  O(n)                                     │
│  Space      │  O(1)  ← The killer feature               │
│  Invented   │  Robert W. Floyd, 1967                    │
│  Use cases  │  Cycles, duplicates, infinite sequences   │
└─────────────────────────────────────────────────────────┘
```

> **The Zen of Floyd's Algorithm:**
> *"Two travelers walking a path at different speeds — if the path is circular, they will always find each other."* 🌀

---

*⭐ If this helped you, consider starring the repo or upvoting on LeetCode!*

**Tags:** `#LinkedList` `#TwoPointers` `#Floyd` `#CycleDetection` `#O(1)Space` `#LeetCode141`