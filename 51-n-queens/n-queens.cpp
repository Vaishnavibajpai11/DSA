class Solution {
public:

    vector<vector<string>> ans;
    vector<string> board;
    int n;

    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;


    void solve(int row) {

        if (row == n) {
            ans.push_back(board);
            return;
        }


        for (int c = 0; c < n; c++) {

            if (col[c] ||
                diag1[row - c + n] ||
                diag2[row + c])
                continue;


            board[row][c] = 'Q';

            col[c] = true;
            diag1[row - c + n] = true;
            diag2[row + c] = true;


            solve(row + 1);


            board[row][c] = '.';

            col[c] = false;
            diag1[row - c + n] = false;
            diag2[row + c] = false;
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        this->n = n;

        board = vector<string>(n, string(n,'.'));

        col.assign(n,false);
        diag1.assign(2*n,false);
        diag2.assign(2*n,false);


        solve(0);

        return ans;
    }
};