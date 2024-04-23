#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        
        int currRow = 0, dir = -1;
        vector<string> v(numRows, "");
        string res;

        for (int i = 0; i < s.length(); ++i) {
            if (currRow == numRows - 1 || currRow == 0) {
                dir *= -1;
            }

            v[currRow] += s[i];
            if (dir == 1) {
                currRow++;
            } else {
                currRow--;
            }
        }

        for (int i = 0; i < numRows; ++i) {
            res += v[i];
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 4);

    return 0;
}