class Solution {
public:
    bool isPowerOfFour(int n) {
          if (n <= 0)
            return false;
        if(n==1) return true;
        int cnt=0;
        int position;
        for(int i=0;i<31;i++){
            if(n&(1<<i)){
               cnt++;
               position=i;
            }
        }
        if(cnt==1 && (position%2==0)) return true;
        return false;
    }
};