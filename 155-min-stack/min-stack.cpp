class MinStack {
public:
    stack<long long> st;
    long long miniElement;
    MinStack() {
        miniElement = -1;
    }

    void push(int val) {
        long long value = val;
        if (st.empty()) {
            miniElement = value;
            st.push(value);
        } else if (value < miniElement) {
            st.push(2 * value - miniElement);
            miniElement = value;
        } else {
            st.push(value);
        }
    }

    void pop() {
        if (st.empty()) return;
        long long top = st.top();
        st.pop();

        if (top < miniElement) {
            miniElement = 2 * miniElement - top;
        }
    }

    int top() {
        long long top = st.top();
        if (top < miniElement) {
            return miniElement;
        } else {
            return top;
        }
    }

    int getMin() {
        return miniElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */