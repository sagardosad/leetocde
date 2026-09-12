class Solution {
public:
    void combsum(int idx, vector<int>& candidates, int target,
                 vector<int> &combination, vector<vector<int>> &ans) {
            if(target==0){
                ans.push_back(combination);
                return;
            }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            combination.push_back(candidates[i]);
            combsum(i+1,candidates,target-candidates[i],combination,ans);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        combsum(0, candidates, target, combination, ans);
        return ans;
    }
};