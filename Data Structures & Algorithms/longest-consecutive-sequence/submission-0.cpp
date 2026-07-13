class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int result = 0;
        for (int& num : nums) {
            // 只有当num-1不再set时 才开始起算
            if (!numSet.count(num - 1)) {
                int currNum = num;
                int currLen = 1;
                while (numSet.count(currNum + 1)) {
                    currLen++;
                    currNum++;
                }
                if (currLen > result) {
                    result = currLen;
                }
            }
        }
        return result;
    }
};
