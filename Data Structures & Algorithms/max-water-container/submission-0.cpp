class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int size = heights.size();
        int left = 0, right = size - 1;
        while (left < right) {
            int area;
            if (heights[left] > heights[right]) {
                area = heights[right] * (right - left);
                right--;
            } else {
                area = heights[left] * (right - left);
                left++;
            }
            if (result < area) {
                result = area;
            }
        }
        return result;
    }
};
