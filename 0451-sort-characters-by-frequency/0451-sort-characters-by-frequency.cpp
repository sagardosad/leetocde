class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        // Step 1: Count frequency
        for (char ch : s) {
            mp[ch]++;
        }

        // Step 2: Store character and frequency in vector
        vector<pair<char, int>> v;

        for (auto it : mp) {
            v.push_back({it.first, it.second});
        }

        // Step 3: Sort by decreasing frequency
        sort(v.begin(), v.end(), [](auto a, auto b) {
            return a.second > b.second;
        });
        string ans = "";

        for (auto it : v) {
            ans += string(it.second, it.first);
        }

        return ans;
    }
};