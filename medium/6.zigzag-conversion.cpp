#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int currRow = 0, dir = 1;
        vector<string> v;
        string res;

        for (int i = 0; i < s.length(); ++i) {
            if (currRow == numRows - 1 || currRow == 0) {
                dir *= -1;
            }

            v[j] += s[i];
            if (dir == 1) {
                currRow++;
            } else {
                currRow--;
            }
        }

        for (int i = 0; i < currRow; ++i) {
            res += v[i];
        }
    }
};

int main() {
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 4);

    return 0;
}