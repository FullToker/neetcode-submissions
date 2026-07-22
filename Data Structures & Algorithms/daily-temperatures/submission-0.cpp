class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int num = temperatures.size();
        vector<int> result(num, 0);
        stack<int> st;
        for (int i = 0; i < num; ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIdx = st.top();
                st.pop();
                result[prevIdx] = i - prevIdx;
            }
            st.push(i);
        }
        return result;
    }
};
