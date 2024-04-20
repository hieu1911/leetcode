#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            int key = target - nums[i];
            if (m.count(key)) {
                return {m[key], i};
            } else {
                m[nums[i]] = i;
            }
        }

        return {0, 0};
    };
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;

    vector<int> result = solution.twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;

    return 0;
}
