class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int result;
                if (str == "+")
                    result = a + b;
                else if (str == "-")
                    result = a - b;
                else if (str == "*")
                    result = a * b;
                else
                    result = a / b;
                st.push(result);
            } else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
