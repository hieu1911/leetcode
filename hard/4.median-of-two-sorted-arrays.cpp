#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int idx1 = 0, idx2 = 0, mid1 = 0, mid2 = 0;

        for (int i = 0; i <= (n1 + n2)/2; ++i) {
            mid1 = mid2;
            if (idx1 < n1 && idx2 < n2) {
                if (nums1[idx1] < nums2[idx2]) {
                    mid2 = nums1[idx1++];
                } else {
                    mid2 = nums2[idx2++];
                }
            } else if (idx1 == n1) {
                mid2 = nums2[idx2++];
            } else {
                mid2 = nums1[idx1++];
            }
        }

        if ((n1 + n2)%2 == 1) {
            return mid1;
        } else {
            return (mid2 + mid1)/2.0;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << solution.findMedianSortedArrays(nums1, nums2);

    return 0;
}