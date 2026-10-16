class MinStack {
public:
    stack<long long> st;
    long long mini = LLONG_MAX;

    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            mini = value;
            st.push(value);
        }
        else {
            if (value >= mini) {
                st.push(value);
            }
            else {
                st.push(2LL * value - mini);
                mini = value;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long n = st.top();
        st.pop();

        if (n < mini) {
            mini = 2 * mini - n;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long x = st.top();

        if (x < mini) {
            return mini;
        }

        return x;
    }

    int getMin() {
        return mini;
    }
};