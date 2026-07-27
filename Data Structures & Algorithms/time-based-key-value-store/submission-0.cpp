class TimeMap {
   private:
    unordered_map<string, vector<pair<int, string>>> store;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { store[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";
        vector<pair<int, string>>& records = store[key];
        int left = 0, right = records.size() - 1;
        string result = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (records[mid].first <= timestamp) {
                // 这条记录的时间戳满足条件(不超过查询时间)
                // 先暂存这个候选答案,但可能还有更大的、也满足条件的时间戳,继续往右找
                result = records[mid].second;
                left = mid + 1;
            } else {
                // 这条记录的时间戳太大了(超过查询时间),不满足条件,只能往左找更小的
                right = mid - 1;
            }
        }

        return result;
    }
};
