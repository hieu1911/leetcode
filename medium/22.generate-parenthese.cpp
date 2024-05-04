class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backTracking(n, 0, "", res, n, n);

        return res;
    }

    void backTracking(int n, int position, string s, vector<string>& res, int openP, int closeP) {
        if (position == n * 2) {
            res.push_back(s);
            return;
        }

        if (openP >= closeP) {
            s += '(';
            openP--;
            backTracking(n, position + 1, s, res, openP, closeP);
        } else {
            if (openP > 0) {
                s += '(';
                openP--;
                backTracking(n, position + 1, s, res, openP, closeP);
                openP++;
                s = s.substr(0, position);
            }
          
            s += ')';
            closeP--;
            backTracking(n, position + 1, s, res, openP, closeP);
            closeP++;
            s = s.substr(0, position);
        }
    }
};