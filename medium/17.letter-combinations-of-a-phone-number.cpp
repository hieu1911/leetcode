class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if (digits == "") return res;

        map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        backTracking(digits, 0, "", res, m);

        return res;
    }

    void backTracking(string digits, int position, string s, vector<string>& res, map<char, string> m) {
        if (position == digits.length()) {
            res.push_back(s);
        }

        for (int i = 0; i < m[digits[position]].length(); ++i) {
            s += m[digits[position]][i];
            backTracking(digits, position + 1, s, res, m);
            s = s.substr(0, position);
        }
    }
};