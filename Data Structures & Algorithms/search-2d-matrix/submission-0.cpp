class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rown = matrix.size(), coln = matrix[0].size();
        int left = 0, right = rown * coln - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = matrix[mid / coln][mid % coln];

            if (midVal == target) {
                return true;
            } else if (midVal < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};
