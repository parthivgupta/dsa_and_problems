class Solution {
public:
    vector<int> nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> pse(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmaller = nse(arr);
        vector<int> prevSmaller = pse(arr);
        long long mod = 1e9 + 7;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            ans = (ans + (arr[i] * left * right) % mod) % mod;
        }
        return ans;
    }
};