class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int>arr;
        int cnt_even=0;
        int cnt_odd=0;
        for(int i=0;i<31;i++){
            if(n&(1<<i)){
                if(i%2==0){
                    cnt_even++;
                }
                else{
                    cnt_odd++;
                }
            }
        }
        arr.push_back(cnt_even);
        arr.push_back(cnt_odd);
        return arr;
    }
};