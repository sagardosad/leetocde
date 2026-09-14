class Solution {
public:

    void permutation(vector<int>& nums, vector<int>& ds,
                     vector<vector<int>>& ans, vector<bool>& used) {

        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            // Choose
            ds.push_back(nums[i]);
            used[i] = true;

            // Explore
            permutation(nums, ds, ans, used);

            // Backtrack
            ds.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> used(nums.size(), false);

        permutation(nums, ds, ans, used);

        return ans;
    }
};