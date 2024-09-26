class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int start = nums.size() - 2;
        while (start >= 0 && nums[start] >= nums[start + 1]) --start;
        if (start >= 0) {
            int end = nums.size() - 1;
            while (nums[start] >= nums[end]) --end;

            swap(nums, start, end);
        }

        reverse(nums.begin() + start + 1, nums.end());
    }

private:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
