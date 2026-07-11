class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) count[c - 'a']++;

            // 把计数数组编码成唯一的字符串key,比如用分隔符拼接数字
            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#";
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            result.push_back(group);
        }
        return result;
    }

    // 并非时间最优的写法
    /*

    */
};
