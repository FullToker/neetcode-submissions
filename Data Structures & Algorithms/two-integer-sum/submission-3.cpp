class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            int com = target-nums[i];
            if (seen.count(com)) return {seen[com], i};
            seen[nums[i]] = i;
        }
        return {};
    }
};
