#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0;
        int max = 1;
        vector<vector<bool>> d(s.length(), vector<bool>(s.length(), false));

        for (int i = 0; i < s.length(); ++i) {
            d[i][i] = true;
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j] && (i - j <= 2 || d[j + 1][i - 1])) {
                    d[j][i] = true;

                    if (i - j + 1 > max) {
                        max = i - j + 1;
                        left = j;
                        right = i;
                    }
                }
            }
        }

        return s.substr(left, right - left + 1);
    }
};

int main() {
    Solution solution;
    cout << solution.longestPalindrome("aacabdkacaa");
}