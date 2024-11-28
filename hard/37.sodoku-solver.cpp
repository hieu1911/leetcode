class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    int iBox = (r / 3) * 3 + c / 3;
                    int num = board[r][c] - '1';
                    row[r][num] = true;
                    col[c][num] = true;
                    box[iBox][num] = true;
                }
            }
        }

        backTracking(board, row, col, box, 0, 0);
    }

    bool backTracking(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& box, int r, int c) {
        if (r == 9) return true;
        if (c == 9) return backTracking(board, row, col, box, r+1, 0);

        if (board[r][c] != '.') return backTracking(board, row, col, box, r, c+1);
        int iBox = (r / 3) * 3 + c / 3;
        for (int i = 0; i < 9; ++i) {
            if (!row[r][i] && !col[c][i] && !box[iBox][i]) {
                row[r][i] = col[c][i] = box[iBox][i] = true;
                char ch = '1' + i;
                board[r][c] = ch;
                if (backTracking(board, row, col, box, r, c+1)) return true;
                board[r][c] = '.';
                row[r][i] = col[c][i] = box[iBox][i] = false;
            }
        }        

        return false;
    }
};