#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];
        string res = "";

        for (int i = 0; i < min(first.length(), last.length()); ++i) {
            if (first[i] != last[i]) return res;
            else res += first[i];
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"flower","flow","flight"};
    cout << solution.longestCommonPrefix(strs);

    return 0;
}