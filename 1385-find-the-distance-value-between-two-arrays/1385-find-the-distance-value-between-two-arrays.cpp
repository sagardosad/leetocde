class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0;
        for(int i=0;i<arr1.size();i++){
            bool add=true;
            for(int j=0;j<arr2.size();j++){
                if(abs(arr2[j]-arr1[i])<=d){
                    add=false;
                    break;
                }
            }
            if(add){
                cnt++;
            }
        }
        return cnt;
    }
};