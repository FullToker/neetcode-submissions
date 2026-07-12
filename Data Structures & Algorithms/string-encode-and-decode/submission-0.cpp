class Solution {
   public:
    string encode(vector<string>& strs) {
        string s;
        for (auto& str : strs) {
            s += to_string(str.length()) + '#' + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.length()) {
            // 第一步:找到 '#' 的位置,这之前的部分是长度数字
            int j = i;
            while (s[j] != '#') j++;

            int length = stoi(s.substr(i, j - i));

            // 第二步:从 '#' 后面开始,精确读取 length 个字符,这就是原字符串
            string str = s.substr(j + 1, length);
            result.push_back(str);

            // 第三步:跳到下一个字符串的起始位置
            i = j + 1 + length;
        }
        return result;
    }
};
