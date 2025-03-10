class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> result;
            vector<int> current;
            sort(candidates.begin(), candidates.end());
            backTracking(result, current, candidates, target, 0);
            return result;
        }
    
        void backTracking(vector<vector<int>>& result, vector<int>& current, vector<int> candidates, int total, int idx) {
            if (total < 0) return;
            if (total == 0) result.push_back(current);
            else {
                for (int i = idx; i < candidates.size(); ++i) {
                    if (i > idx && candidates[i] == candidates[i - 1]) continue;
                    current.push_back(candidates[i]);
                    backTracking(result, current, candidates, total - candidates[i], i + 1);
                    current.pop_back();
                }
            }
        }
    };