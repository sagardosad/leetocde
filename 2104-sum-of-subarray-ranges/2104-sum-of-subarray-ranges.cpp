
class Solution {
public:
    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPGEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> NGE = findNGE(arr);
        vector<int> PGEE = findPGEE(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long right = NGE[i] - i;
            long long left = i - PGEE[i];

            total += left * right * arr[i];
        }

        return total;
    }

    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSE = findNSE(arr);
        vector<int> PSEE = findPSEE(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long right = NSE[i] - i;
            long long left = i - PSEE[i];

            total += left * right * arr[i];
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};
