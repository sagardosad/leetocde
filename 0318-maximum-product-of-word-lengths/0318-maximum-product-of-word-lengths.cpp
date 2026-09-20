class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);

        // Create mask for every word once
        for (int i = 0; i < n; i++) {
            for (char ch : words[i]) {
                mask[i] |= (1 << (ch - 'a'));
            }
        }

        int maxproduct = 0;

        // Compare every pair
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // No common character
                if ((mask[i] & mask[j]) == 0) {
                    int product = words[i].length() * words[j].length();
                    maxproduct = max(maxproduct, product);
                }
            }
        }

        return maxproduct;
    }
};