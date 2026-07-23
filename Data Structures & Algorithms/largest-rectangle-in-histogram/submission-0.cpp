class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int result = 0;
        stack<int> st;
        // 这里i=n是为了跳出去当作最右边有一个高度为零的柱子
        for (int i = 0; i <= n; ++i) {
            int currentHeight = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] > currentHeight) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                result = max(result,width * height);
            }
            st.push(i);
        }
        return result;
    }
};
