#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long reverse = 0;
        int tmp = x;

        while (tmp / 10 != 0) {
            reverse *= 10;
            reverse += tmp % 10;
            tmp /= 10;
        }
        
        reverse *= 10;
        reverse += tmp % 10;

        if (reverse == x) return true;
        else return false;
    }
};


int main() {
    Solution solution;
    cout << solution.isPalindrome(121);

    return 0;
}