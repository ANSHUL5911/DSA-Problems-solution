<div align="center">

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://readme-typing-svg.demolab.com?font=Fira+Code&size=30&duration=3000&pause=1000&color=7F77DD&center=true&vCenter=true&width=600&lines=Minimum+Meeting+Rooms;Two+Pointer+%7C+O(n+log+n);LeetCode+%23253">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=30&duration=3000&pause=1000&color=534AB7&center=true&vCenter=true&width=600&lines=Minimum+Meeting+Rooms;Two+Pointer+%7C+O(n+log+n);LeetCode+%23253" alt="Minimum Meeting Rooms">
</picture>

<br/>

![](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)
![](https://img.shields.io/badge/Difficulty-Medium-E6A817?style=flat-square)
![](https://img.shields.io/badge/Topic-Intervals-7F77DD?style=flat-square)
![](https://img.shields.io/badge/Pattern-Two%20Pointers-1D9E75?style=flat-square)
![](https://img.shields.io/badge/Time-O(n%20log%20n)-D85A30?style=flat-square)
![](https://img.shields.io/badge/Space-O(1)-D4537E?style=flat-square)

</div>

---

## 🧩 Problem

> Given `start[]` and `end[]` arrays for `n` meetings,  
> return the **minimum number of conference rooms** needed to hold all of them simultaneously.

```
Input:   start = [0,  1,  2]
         end   = [30, 5, 10]

Output:  3
```

---

## 🎨 Visualized

```
  ┌────────────────────────────────────────────────────────────────┐
  │  Timeline →   0    5    10   15   20   25   30                 │
  │               |    |    |    |    |    |    |                  │
  │  Meeting 1    ████████████████████████████████  [0  → 30]      │
  │  Meeting 2    ████                              [1  →  5]      │
  │  Meeting 3         █████                        [2  → 10]      │
  │               ↑                                                │
  │            3 meetings overlap at t=2  →  need 3 rooms          │
  └────────────────────────────────────────────────────────────────┘
```

**Core insight:** Sort starts and ends separately. Use two pointers to count *active* meetings at any moment — no need to track which meeting is in which room.

---

## ⚙️ Algorithm

```
  ① Sort start[] and end[] independently
  ② Sweep with pointers i (starts) and j (ends):
  
      start[i] < end[j]  →  new meeting opens before any ends
                             rooms++ , track peak , i++
  
      start[i] ≥ end[j]  →  a meeting ended before (or as) next begins
                             rooms-- , j++
  
  ③ Return peak rooms
```

### Step-by-step trace

```
  start (sorted) →  [ 0,  1,  2 ]
  end   (sorted) →  [ 5, 10, 30 ]

  ┌────┬───┬─────────┬────────┬──────────────────┬──────┬─────┐
  │ i  │ j │ start[i]│ end[j] │ action           │ room │ res │
  ├────┼───┼─────────┼────────┼──────────────────┼──────┼─────┤
  │  0 │ 0 │    0    │   5    │ 0  < 5  → open   │  1   │  1  │
  │  1 │ 0 │    1    │   5    │ 1  < 5  → open   │  2   │  2  │
  │  2 │ 0 │    2    │   5    │ 2  < 5  → open   │  3   │  3  │◄ peak
  └────┴───┴─────────┴────────┴──────────────────┴──────┴─────┘
                                                   answer = 3 ✓
```

---

## 💻 Code

```cpp
class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {

        int n = start.size();

        sort(start.begin(), start.end());   // ← sort starts
        sort(end.begin(), end.end());       // ← sort ends (separately!)

        int i    = 0;    // pointer: next meeting to begin
        int j    = 0;    // pointer: earliest meeting to end
        int room = 0;    // rooms currently in use
        int res  = 0;    // answer

        while (i < n) {
            if (start[i] < end[j]) {
                room++;                    // overlap → need new room
                res = max(res, room);      // update peak
                i++;
            } else {
                room--;                    // freed! recycle the room
                j++;
            }
        }

        return res;                        // peak concurrent rooms
    }
};
```

---

## 📊 Complexity

| | Complexity | Note |
|---|---|---|
| ⏱ Time | `O(n log n)` | Two `sort()` calls dominate |
| 🗂 Space | `O(1)` | Sorts in-place; 4 int variables only |

---

## 🔬 Edge Cases

| Input | Output | Why |
|---|---|---|
| `[5] / [10]` | `1` | Single meeting |
| `[1,3] / [2,4]` | `1` | Sequential — never overlap |
| `[1,1,1] / [5,5,5]` | `3` | All start simultaneously |
| `[1,5] / [5,10]` | `1` | `start==end` → `≥` path frees room first |

> 💡 **Why `<` and not `<=`?**  
> `start[i] == end[j]` means one meeting ends exactly when another begins.  
> Using `<` ensures the ending room is recycled — they can share it.  
> Using `<=` would incorrectly open a new room.

---

## 🔗 Related Problems

<table>
<tr>
<td>

**Easier**
- [#252 Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) 🟢
- [#56 Merge Intervals](https://leetcode.com/problems/merge-intervals/) 🟡

</td>
<td>

**Harder**
- [#435 Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) 🟡
- [#57 Insert Interval](https://leetcode.com/problems/insert-interval/) 🟡

</td>
</tr>
</table>

---

<div align="center">

*If this helped you — drop a ⭐ and keep grinding!*

</div>