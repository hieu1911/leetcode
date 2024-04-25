class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        set<vector<int>> s;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n-3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                int k = j + 1;
                int p = n - 1;

                while (k < p) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[p];

                    if (sum == target) {
                        vector<int> t = {nums[i], nums[j], nums[k], nums[p]};
                        s.insert(t);
                        k++;
                        p--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        p--;
                    }
                }
            }
        }

        for (auto i : s) {
            res.push_back(i);
        }

        return res;
    }
};