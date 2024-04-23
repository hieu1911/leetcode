#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long res = 0;

        while (x / 10 != 0) {
            res += x % 10;
            res *= 10;
            x /= 10;
        }
        res += x % 10;
        if (res > INT_MAX || res < INT_MIN) return 0;

        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.reverse(120);

    return 0;
}