class Solution {

    public:
      long long countTriplets(int n, long long sum, long long arr[]) {
          int ans = 0;
          if(n<3) return 0;
          
          sort(arr, arr + n);
          
          for(int i = 0;i<n;i++){
              int left = i+1;
              int right=n-1;
              
              while(left<right){
                  int res_sum= arr[i]+arr[left]+arr[right];
                  
                  if(res_sum >= sum){
                      right--;
                  }
                  else{ //sum<target
                      ans = ans + (right - left);
                      left++;
                  }
              }
          }
          return ans;
      }
  };