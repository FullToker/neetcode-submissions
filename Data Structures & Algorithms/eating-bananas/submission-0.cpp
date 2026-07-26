class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, mid, h)) {
                right = mid;  // mid这个速度可行,尝试更小的速度(收缩右边界)
            } else {
                left = mid + 1;  // mid太慢了,不可行,速度需要更大
            }
        }

        return left;
    }
    bool canFinish(vector<int>& piles, int speed, int h) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;  // 向上取整
        }
        return hours <= h;
    }
};
