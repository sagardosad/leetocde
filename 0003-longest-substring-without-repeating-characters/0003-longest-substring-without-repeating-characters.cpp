class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map<char, int> mpp;

        int l = 0;
        int r = 0;
        int maxlen = 0;

        while (r < s.length()) {

            if (mpp.find(s[r]) != mpp.end()) {

                if (mpp[s[r]] >= l) {
                    l = mpp[s[r]] + 1;
                }

            }

            mpp[s[r]] = r;

            int len = r - l + 1;
            maxlen = max(maxlen, len);

            r++;
        }

        return maxlen;
    }
};