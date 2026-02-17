class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            vector<int> pos;
            vector<int> neg;
    
            for(int i = 0; i<nums.size(); i++){
                if(nums[i]>0){
                    pos.push_back(nums[i]);
                }
                else{
                    neg.push_back(nums[i]);
                }
            }
    
            if(neg.size()==0){
                for(int i=0;i<pos.size();i++){
                    pos[i]=pos[i]*pos[i];
                }
                return pos;
            }
    
            if(pos.size()==0){
                for(int i=0;i<neg.size();i++){
                    neg[i]=neg[i]*neg[i];
                }
                reverse(neg.begin(),neg.end());
                return neg;
            }
    
            int i=0, j=0;
            int id=0;
            int m = pos.size();
            int n = neg.size();
            vector<int> res(m+n);
    
            for(int i=0;i<pos.size();i++){
                pos[i]=pos[i]*pos[i];
            }
    
            for(int i=0;i<neg.size();i++){
                neg[i]=neg[i]*neg[i];
            }
            reverse(neg.begin(),neg.end());
    
            while(i<pos.size() && j<neg.size()){
    
                if(pos[i]<neg[j]){
                    res[id]=pos[i];
                    id++;
                    i++;
                }
                else{
                    res[id]=neg[j];
                    id++;
                    j++;
                }
            }
    
            while(i<pos.size()){
                res[id]=pos[i];
                id++;
                i++;
            }
    
            while(j<neg.size()){
                res[id]=neg[j];
                id++;
                j++;
            }
    
            return res;
        }
    };