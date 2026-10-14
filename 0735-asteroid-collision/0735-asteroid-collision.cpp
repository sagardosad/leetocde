class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
            else {
                int val = abs(asteroids[i]);

                while (!st.empty() && st.top() > 0 && st.top() < val) {
                    st.pop();
                }

                if (!st.empty() && st.top() == val) {
                    st.pop();
                }
                else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};