#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int res = 0;

        for (int i = 0; i < s.length() - 1; ++i) {
            if (m[s[i]] < m[s[i+1]]) {
                res -= m[s[i]];
            } else {
                res += m[s[i]];
            }
        }

        res += m[s[s.length() - 1]];

        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.romanToInt("MCMXCIV");

    return 0;
}