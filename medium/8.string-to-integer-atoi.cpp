#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) { 
        long res = 0;
        bool negative = false;
        int i = 0;

        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        if (s[i] == '-') {
            negative = true;
            i++;
        } else if (s[i] == '+') {
            negative = false;
            i++;
        }

        while(i < s.length() && s[i] >= '0' && s[i] <='9') {
            res *= 10;
            res += s[i] - '0';
            if(res > INT_MAX && negative)
                return INT_MIN;
            else if(res > INT_MAX && !negative)
                return INT_MAX;
            i++;
        }

        if (negative) res *= -1;

        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.myAtoi("4193 with words");

    return 0;
}