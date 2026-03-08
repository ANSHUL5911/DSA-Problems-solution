class Solution {
    public:
      int longestKSubstr(string &s, int k) {
          int low = 0;
          int res = 0;
          unordered_map<char,int> f;
          int n = s.length();
          
          for(int high = 0; high<n ; high++){
              
              f[s[high]]++;
              
              while(f.size()>k){
                  f[s[low]]--;
                  if(f[s[low]]==0){
                      f.erase(s[low]);
                  }
                  low++;
              }
              
              int ans = high-low+1;
              
              res=max(res,ans);
          }
          
          if(f.size()<k){
              return -1;
          }
          
          return res;
          
      }
  };