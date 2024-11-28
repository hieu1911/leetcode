class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> row[9];
        set<char> col[9];
        set<char> box[9];

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') {
                    continue;
                }
                
                int rbox = (r / 3) * 3;
                int cbox = (c / 3);
                int idxbox = rbox + cbox;
                if (row[r].count(ch) || col[c].count(ch) || box[idxbox].count(ch)) {
                    return false;
                }

                row[r].insert(ch);
                col[c].insert(ch);
                box[idxbox].insert(ch);
            }
        }

        return true;
    }
};