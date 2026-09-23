class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int maxlen = 0;

        while (r < nums.size()) {

            if (nums[r] == 0) {
                k--;
            }

            while (k < 0) {
                if (nums[l] == 0) {
                    k++;
                }
                l++;
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);

            r++;
        }

        return maxlen;
    }
};