class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        int arr[26]={0};
    
    int number=0;
    
    for(int i=0;i<s.size();i++){
        char ch= s[i];
        if(ch>='a'&& ch<='z'){
            number = ch - 'a';
        }
        else{
            number = ch - 'A';
        }
        arr[number]++;
    }
    
    int maximum=-1,ans=0;
    for(int i=0; i<26; i++){
        if(maximum< arr[i]){
            ans=i;
            maximum = arr[i];
        }
    }
    
    return ans+'a';
    }
};