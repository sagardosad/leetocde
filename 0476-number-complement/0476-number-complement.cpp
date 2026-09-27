class Solution {
public:
    int findComplement(int num) {
        int highest = 0;

        for (int i = 30; i >= 0; i--) {
            if ((num >> i) & 1) {
                highest = i;
                break;
            }
        }

        int b = 0;

        for (int i = 0; i <= highest; i++) {
            if (((num >> i) & 1) == 0) {
                b |= (1 << i);
            }
        }

        return b;
    }
};