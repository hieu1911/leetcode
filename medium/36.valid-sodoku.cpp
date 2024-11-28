class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> row[9];
        set<char> col[9];
        set<char> box[9];

        for (int r = 0; r < 9; ++i) {
            for (int c = 0; c < 9; ++i) {
                char ch = board[r][c];
                if (ch == ".") {
                    continue;
                }
                
                int rbox = (r / 3) * 3;
                int cbox = (c / 3);
                int idxbox = rbox + cbox;
                if (row[r].count(ch) || col[c].count(ch) || box[idxbox].count(ch)) {
                    return false;
                }

                row.insert(ch);
                col.insert(ch);
                box.insert(ch);
            }
        }

        return true;
    }
};