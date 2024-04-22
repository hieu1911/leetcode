#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> sc;
        int res = 0;
        int j = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (sc.count(s[i]) == 0) {
                sc.insert(s[i]);
                res = max(res, i - j + 1);
            } else {
                while (sc.count(s[i]) != 0) {
                    sc.erase(s[j]);
                    j++;
                }
                sc.insert(s[i]);
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb");
    return 0;
}