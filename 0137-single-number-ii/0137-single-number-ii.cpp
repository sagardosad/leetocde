class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int ans=0;
    for(int bit_idx=0; bit_idx<32;bit_idx++){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&(1<<bit_idx)){
                cnt++;
            }
        }
        if(cnt%3==1){
            ans=ans|(1<<bit_idx);
        }
    }
    return ans;
    }
};