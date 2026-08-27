class Solution {
public:
    bool detectCapitalUse(string word) {

        string upper = word;
        string lower = word;

        transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

        if (word == upper)
            return true;

        if (word == lower)
            return true;

        if (isupper(word[0])) {
            for (int i = 1; i < word.length(); i++) {
                if (isupper(word[i]))
                    return false;
            }
            return true;
        }

        return false;
    }
};