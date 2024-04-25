class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    s.insert(v);
                    k--;
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        
        for (auto i : s) {
            res.push_back(i);
        }
        
        return res;
    }
};