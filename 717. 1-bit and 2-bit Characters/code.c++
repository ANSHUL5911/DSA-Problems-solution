class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

        // your original check kept unchanged
        if(bits.size() == 2){
            if(bits[0] == 0 && bits[1] == 0){
                return true;
            }
        }

        // main decoding logic
        int i = 0;
        while(i < bits.size() - 1){
            if(bits[i] == 1){
                i += 2;     // 2-bit character
            } else {
                i += 1;     // 1-bit character
            }
        }

        // if pointer lands on last position
        return (i == bits.size() - 1);
    }
};