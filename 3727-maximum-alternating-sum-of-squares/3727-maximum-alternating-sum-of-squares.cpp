class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            sum -= 1LL * nums[start] * nums[start];
            sum += 1LL * nums[end] * nums[end];

            start++;
            end--;
        }

        if (start == end) {
            sum += 1LL * nums[start] * nums[start];
        }

        return sum;
    }
};