class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int> st; 
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
                
                st.push(stoi(ch));
            }
        }
        return st.top();  
    }
};
