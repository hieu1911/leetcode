class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string pre = countAndSay(n - 1);
        string res = "";
        int count = 0;
        char ch = '.';
        for (int i = 0; i < pre.size(); ++i) {
            if (ch == pre[i]) {
                ++count;
            } else {
                if (count > 0) {
                    res += to_string(count);;
                    res += ch;
                }

                ch = pre[i];
                count = 1;
            }
        }
        if (count > 0) {
            res += to_string(count);;
            res += ch;
        }

        return res;
    }
};