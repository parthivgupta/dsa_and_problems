class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int> st;  // Declare a stack to store intermediate results
        int n = s.size();
        for(int i = 0; i < n; i++) {
            string ch = s[i];
            if(ch == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b + a);
            } else if(ch == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            } else if(ch == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b * a);
            } else if(ch == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            } else {
                // If it's a number, convert it from string to int and push to the stack
                st.push(stoi(ch));
            }
        }
        return st.top();  // The result will be at the top of the stack
    }
};
