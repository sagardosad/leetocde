class Solution {
public:
    void combsum(vector<int>& arr, int i,
                 vector<int>& combination,
                 vector<vector<int>>& ans,
                 int target) {

        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        if (i == arr.size() || target < 0)
            return;

        // TAKE
        combination.push_back(arr[i]);
        combsum(arr, i + 1, combination, ans, target - arr[i]);

        // BACKTRACK
        combination.pop_back();

        // SKIP duplicates
        while (i + 1 < arr.size() && arr[i] == arr[i + 1])
            i++;

        // SKIP
        combsum(arr, i + 1, combination, ans, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> combination;
        vector<vector<int>> ans;

        combsum(candidates, 0, combination, ans, target);

        return ans;
    }
};