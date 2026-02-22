class Solution {
    public:
        string decimalToBinary(int n) {
            if (n == 0)
                return "0";
    
            if (n == 1)
                return "1";
    
            return decimalToBinary(n / 2) + char((n % 2) + '0');
        }
    
        int binaryGap(int n) { 
            int i = 0;
            string res = decimalToBinary(n);
            int j = 0;
            int m = res.length();
            int max = 0;
            while(i<m && j<m){
                if(res[i]=='1' && res[j]=='1'){
                    int dist = j - i;
                    if(max<dist){
                        max = dist;
                    }
                    i = j;
                    j++;
                }
                else{
                    j++;
                }
            }
            return max;
        }
    };