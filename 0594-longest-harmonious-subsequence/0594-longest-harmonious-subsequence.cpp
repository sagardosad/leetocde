class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = 0;
        int maxlen = 0;

        while (r < nums.size()) {

            while (nums[r] - nums[l] > 1) {
                l++;
            }

            if (nums[r] - nums[l] == 1) {
                maxlen = max(maxlen, r - l + 1);
            }

            r++;
        }

        return maxlen;
    }
};