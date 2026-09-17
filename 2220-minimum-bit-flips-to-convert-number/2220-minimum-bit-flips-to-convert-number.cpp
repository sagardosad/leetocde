class Solution {
public:
    int minBitFlips(int start, int goal) {
        // xor use to differentiate
    int num=start ^ goal;
        // now calculate the number of set bit in the number 
        // that will be total number of flip bit require 
    int cnt=0;
        for(int i=0 ;i<31;i++){
            if ((num & (1 << i)) != 0) {
            cnt++;
            }
        }
        return cnt;
    }
};