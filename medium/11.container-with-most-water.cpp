#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l < r) {
            int width = r - l;
            res = max(res, width * min(height[l], height[r]));

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << solution.maxArea(height);

    return 0;
}