class Solution {
    public:
      bool canAttend(vector<vector<int>> &arr) {
          sort(arr.begin(), arr.end());
          int start1 = arr[0][0];
          int end1 = arr[0][1];
          int meet = 1;
          int n = arr.size();
          
          for(int i =1;i<n;i++){
              int start2 = arr[i][0];
              int end2 = arr[i][1];
              
              if(end1<= start2){
                  start1 = start2;
                  end1 = end2;
              }
              else{
                  meet = 0;
                  start1 = min(start1, start2);
                  end1 = max(end1, end2);
              }
          }
          return meet;
      }
  };