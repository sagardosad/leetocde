class Solution {
public:
    int large(vector<int>&nums,int i){
        int maxi=INT_MIN;
        if(i==0) return nums[0];
        for(int j=0;j<=i;j++){
            if(nums[j]>maxi){
                maxi=nums[j];
            }
        }
        return maxi;
    }
    int small(vector<int>&nums,int i){
          int mini=INT_MAX;
        for(int j=i;j<nums.size();j++){
            if(nums[j]<mini){
                mini=nums[j];
            }
        }
        return mini;
        
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int i=0;
        while(i<nums.size()){
            int largest=large(nums,i);
            int smallest=small(nums,i);
            int stability=largest-smallest;
            if(stability<=k){
               return i;
            }
            i++;
        }
      return -1;
    }
};