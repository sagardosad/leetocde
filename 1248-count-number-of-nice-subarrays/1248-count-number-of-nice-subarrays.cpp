class Solution {
public:
        int subarray(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l=0;
        int r=0;
        int cnt=0;
        int sum=0;
        while(r<nums.size()){
            sum=sum+(nums[r]%2);
            while(sum>goal){
                sum=sum-(nums[l]%2);
                l=l+1;
            }
            cnt=cnt+r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return   subarray(nums,k)-subarray(nums,k-1);
    }
};