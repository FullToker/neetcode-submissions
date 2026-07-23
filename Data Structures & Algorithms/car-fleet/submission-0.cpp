class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }
        // 按position从大到小排序(离终点最近的排最前面)
        sort(cars.begin(), cars.end(), [](auto& a, auto& b) { return a.first > b.first; });
        stack<double> st;
        for (auto& [pos, time] : cars) {
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }
        return st.size();
    }
};
