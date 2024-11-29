class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1);
        dp[0].push_back({});
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < candidates.size(); ++j) {
                int c = candidates[j];
                if (c <= i) {
                    for (int k = 0; k < dp[i - c].size(); ++k) {
                        vector<int> tmp(dp[i - c][k]);
                        tmp.push_back(candidates[j]);
                        sort(tmp.begin(), tmp.end());
                        if (find(dp[i].begin(), dp[i].end(), tmp) == dp[i].end()) {
                            dp[i].push_back(tmp);
                        }
                    }
                }
            }
        }

        return dp[target];
    }
};