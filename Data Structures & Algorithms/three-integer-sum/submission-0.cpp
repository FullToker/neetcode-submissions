class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 必须先排序才可以使用双指针
        //  固定第一个数之后就可以使用双指针里
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;
            // 跳过重复的第一个数,避免产生重复三元组
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = nums.size() - 1;
            int target = -nums[i];
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // 找到一个答案后,跳过重复的left和right,避免产生重复三元组
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (nums[left] + nums[right] > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return result;
    }
};
