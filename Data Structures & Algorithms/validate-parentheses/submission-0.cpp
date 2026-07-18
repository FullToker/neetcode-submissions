class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);  // 左括号,压栈
            } else {
                // 右括号:检查是否能与栈顶匹配
                if (st.empty() || st.top() != pairs[c]) {
                    return false;
                }
                st.pop();  // 匹配成功,弹出
            }
        }

        return st.empty();  // 栈里不能有剩余的左括号
    }
};
