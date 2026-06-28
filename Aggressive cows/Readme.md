# 🐄 Aggressive Cows - Binary Search on Answer

```{=html}
<p align="center">
```
`<img src="https://img.shields.io/badge/GFG-Aggressive%20Cows-2F8D46?style=for-the-badge"/>`{=html}
`<img src="https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge"/>`{=html}
`<img src="https://img.shields.io/badge/Algorithm-Binary%20Search-orange?style=for-the-badge"/>`{=html}
```{=html}
</p>
```

------------------------------------------------------------------------

## 🚀 Idea

We binary search the **minimum distance** between any two cows.

-   Sort stalls.
-   Guess a minimum distance.
-   Greedily place cows.
-   If possible, try a larger distance.
-   Otherwise reduce the distance.

------------------------------------------------------------------------

# 🌟 Primary Solution (Your Approach)

``` cpp
class Solution {
public:

    bool cowDist(vector<int> &stalls,int guess,int n,int k){
        int count=1;
        int j=0;
        for(int i=1;i<n;i++){
            if(count==k){
                return true;
            }
            if(stalls[i]-stalls[j]>=guess){
                count++;
                j=i;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        sort(stalls.begin(),stalls.end());

        int n = stalls.size();
        int low=0, high=stalls[n-1];
        int res=0;

        while(low<=high){
            int guess=(low+high)/2;

            bool d = cowDist(stalls,guess,n,k);

            if(d){
                res=guess;
                low=guess+1;
            }else{
                high=guess-1;
            }
        }
        return res;
    }
};
```

## ❌ Where this lags

### 1. Upper Bound

``` cpp
high = stalls[n-1];
```

Better

``` cpp
high = stalls[n-1]-stalls[0];
```

------------------------------------------------------------------------

### 2. Checking count too early

Instead of checking before placing the current cow, check immediately
after placement.

------------------------------------------------------------------------

# ⚡ Optimized Solution

``` cpp
class Solution {
public:

    bool canPlace(vector<int>& stalls,int dist,int k){

        int cows=1;
        int last=0;

        for(int i=1;i<stalls.size();i++){

            if(stalls[i]-stalls[last]>=dist){

                cows++;
                last=i;

                if(cows==k)
                    return true;
            }
        }

        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        sort(stalls.begin(),stalls.end());

        int low=1;
        int high=stalls.back()-stalls.front();

        int ans=0;

        while(low<=high){

            int mid=low+(high-low)/2;

            if(canPlace(stalls,mid,k)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return ans;
    }
};
```

------------------------------------------------------------------------

# 🧠 Dry Run

Stalls

    1 2 4 8 9

k = 3

Guess = 3

-   Place at 1
-   Place at 4
-   Place at 8

✔ 3 cows placed.

Try larger distance.

------------------------------------------------------------------------

# ⏱ Complexity

  Operation       Complexity
  --------------- ---------------------
  Sorting         O(n log n)
  Checking        O(n)
  Binary Search   O(log(MaxDistance))

Overall

    O(n log n + n log(MaxDistance))

Space

    O(1)

------------------------------------------------------------------------

# 💡 Interview Takeaways

-   Binary Search on Answer
-   Greedy Placement
-   Sorted Array
-   Feasibility Check

------------------------------------------------------------------------

⭐ If this helped, consider starring your repository!

**Made with ❤️ by Anshul**
