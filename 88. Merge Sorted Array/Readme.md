💡 Intuition
We are asked to merge two sorted arrays nums1 and nums2 into a single sorted array — but here’s the catch ⚡:

nums1 already has enough space at the end to hold elements of nums2.
Instead of creating a new array (extra space ❌), we should reuse nums1 and place elements in the right position.
👉 The trick is to fill the array from the back instead of the front.
Why? Because if we start filling from the front, we’d overwrite important values in nums1. By filling from the back, we avoid overwriting since the "empty slots" are already at the end.

🛠️ Approach (Two-Pointer + Backfill Strategy)
Initialize 3 pointers:

p1 = m-1 → last valid element in nums1.
p2 = n-1 → last element in nums2.
p = m+n-1 → last index of nums1 (total size).
Compare & Fill from the Back 🔄:

While both p1 and p2 are valid:

If nums1[p1] > nums2[p2], put nums1[p1] at position p.
Else, put nums2[p2] at position p.
Move pointers accordingly.
Handle leftovers 🍕:

If nums2 still has elements left, copy them into nums1.
No need to check for leftovers in nums1 because they are already in place.
⏱️ Complexity Analysis
Time Complexity: O(m + n) ⏰

Each element from both arrays is touched once.
Space Complexity: O(1) 💾

No extra space, just pointers.
✨ Example Walkthrough
Input:

nums1 = [1,2,3,0,0,0], m = 3  
nums2 = [2,5,6], n = 3
Steps:

Compare 3 & 6 → put 6 at end → [1,2,3,0,0,6]
Compare 3 & 5 → put 5 at next → [1,2,3,0,5,6]
Compare 3 & 2 → put 3 → [1,2,0,3,5,6]
Compare 2 & 2 → put 2 → [1,2,2,3,5,6]
Leftovers handled ✅
Output:

[1,2,2,3,5,6]
🎯 Final Verdict
This solution is a classic application of the two-pointer technique 🏹.
It’s efficient, in-place, and avoids unnecessary space usage — a hallmark of clean, production-level code ✅.