#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string units[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string dozens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousands[] = {"", "M", "MM", "MMM"};

        int ti = num / 1000;
        int hi = (num % 1000) / 100;
        int di = (num % 100) / 10;
        int ui = num % 10;

        return thousands[ti] + hundreds[hi] + dozens[di] + units[ui];
    }
};

int main() {
    Solution solution;
    cout << solution.intToRoman(1994);

    return 0;
}