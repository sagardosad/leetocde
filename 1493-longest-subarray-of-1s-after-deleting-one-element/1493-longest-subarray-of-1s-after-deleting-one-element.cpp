class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 1;
        int l = 0, r = 0;
        int maxlen = 0;

        while (r < nums.size()) {
            if (nums[r] == 1) {
                r++;
            }
            else if (cnt != 0 && nums[r] == 0) {
                cnt--;
                r++;
            }
            else if (cnt == 0 && nums[r] == 0) {
                maxlen = max(maxlen, r - l - 1);

                while (l < nums.size() && nums[l] != 0) {
                    l++;
                }

                l++;
                cnt = 1;
            }
        }

        maxlen = max(maxlen, r - l - 1);

        return maxlen;
    }
};