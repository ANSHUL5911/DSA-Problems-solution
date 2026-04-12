class Solution {
    public:
      int minMeetingRooms(vector<int> &start, vector<int> &end) {
          
          int n = start.size();
          
          sort(start.begin(),start.end());
          sort(end.begin(),end.end());
          
          int i =0 ;
          int j =0;
          int room =0;
          int res =0;
          
          while(i<n && j<n){
              if(start[i]<end[j]){
                  room++;
                  res = max(res, room);
                  i++;
              }
              else{  //start[i]>end[j] or start[i] == end[j]
                  room--;
                  j++;
              }
          }
          return res;
      }
  };
  