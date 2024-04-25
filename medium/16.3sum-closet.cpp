class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int dis = INT_MAX;

        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) return sum;
                if (abs(sum - target) < abs(dis)) {
                    dis = sum - target;
                    res = sum;
                }

                if (sum > target) k--;
                else j++;
            }
        }
        
        return res;
    }
};