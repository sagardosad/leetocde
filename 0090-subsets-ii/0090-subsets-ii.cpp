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
          while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
          }
          getsubsets(nums,ans,i+1,allsubsets);
      
    }
   vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>allsubsets;
        vector<int>ans;
        getsubsets(nums,ans,0,allsubsets);
        return allsubsets;
    }
};