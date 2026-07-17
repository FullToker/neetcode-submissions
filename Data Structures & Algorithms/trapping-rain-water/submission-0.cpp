class Solution {
   public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int total = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // 说明右边至少有一根柱子比左边高,rightMax一定 >= 当前leftMax
                // 此时 left 这个位置的水位,一定由 leftMax 决定(不用管rightMax具体多少)
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    total += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    total += rightMax - height[right];
                }
                right--;
            }
        }

        return total;
    }
};
