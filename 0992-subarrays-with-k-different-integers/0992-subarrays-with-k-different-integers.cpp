
class Solution {
public:
    int Atmost(vector<int>&nums,int k){
        int cnt=0;
        int l=0;
        int r=0;
        map<int,int>mpp;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            cnt=cnt+r-l+1;
            r++;

        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return Atmost(nums,k)-Atmost(nums,k-1);
    }
};
