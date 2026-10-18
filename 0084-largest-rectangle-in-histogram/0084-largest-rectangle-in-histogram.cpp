class Solution {
public:
    vector<int>findNSE(vector<int>&arr){
        int n=arr.size();
         vector<int> ans(n);
        stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = n;
        } else {
            ans[i] = st.top();
        }

        st.push(i);
    }

    return ans;
    }

    vector<int>findPSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }

        st.push(i);
    }

    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>NSE(n);
        vector<int>PSE(n);
        NSE=findNSE(heights);
        PSE=findPSE(heights);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi,heights[i]*(NSE[i]-PSE[i]-1));
        }
        return maxi;
    }
};