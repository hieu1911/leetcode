class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int firstIdx = findIdx(nums, target, true);
        int lastIdx = findIdx(nums, target, false);
        result.push_back(firstIdx);
        result.push_back(lastIdx);
        return result;
    }

    int findIdx(vector<int>& nums, int target, bool findFirst) {
        int idx = -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                idx = mid;
                if (findFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return idx;
    }
};