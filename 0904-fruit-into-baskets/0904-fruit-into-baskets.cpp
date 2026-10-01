class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mpp;
        int l=0;
        int r=0;
        int maxlen=0;
        while(r<fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size()<=2){
                int len=r-l+1;
                maxlen=max(len,maxlen);
            }
            else{
                while(mpp.size()!=2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                    l++;
                }
            }
            r++;
        }
        return maxlen;
    }
};