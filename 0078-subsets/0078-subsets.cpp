class Solution {
public:
    void getsubsets(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>>&allsubsets){
        if(i==nums.size()){
            allsubsets.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
          getsubsets(nums,ans,i+1,allsubsets);

          ans.pop_back();
          getsubsets(nums,ans,i+1,allsubsets);
      
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>allsubsets;
        vector<int>ans;
        getsubsets(nums,ans,0,allsubsets);
        return allsubsets;
    }
};