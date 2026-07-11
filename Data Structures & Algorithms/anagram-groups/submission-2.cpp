class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            groups[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto& item : groups) {
            res.push_back(item.second);
        }
        return res;
    }

    // 并非时间最优的写法
    /*

    */
};
