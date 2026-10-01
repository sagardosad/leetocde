class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxlen=0;
        int maxfrequency=0;
        int hash[26] = {0};
        while(r<s.length()){
            hash[s[r]-'A']++;
           maxfrequency = max(maxfrequency, hash[s[r] - 'A']);
            if((r-l+1)-maxfrequency > k){
                hash[s[l]-'A']--;
                l++;
            }
            else{
                maxlen=max(r-l+1,maxlen);
            }
            r++;
        }
        return maxlen;
    }
};