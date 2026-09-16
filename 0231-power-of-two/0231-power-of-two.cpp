class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        int m = n - 1;

        if ((n & m) == 0)
            return true;

        return false;
    }
};