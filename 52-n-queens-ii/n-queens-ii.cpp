class Solution {
public:

    int ans = 0;

    vector<int> col;
    vector<int> diag1;
    vector<int> diag2;


    void solve(int row, int n) {

        if(row == n) {
            ans++;
            return;
        }


        for(int c = 0; c < n; c++) {

            if(col[c] ||
               diag1[row-c+n] ||
               diag2[row+c])
                continue;


            col[c] = 1;
            diag1[row-c+n] = 1;
            diag2[row+c] = 1;


            solve(row+1,n);


            col[c] = 0;
            diag1[row-c+n] = 0;
            diag2[row+c] = 0;
        }
    }


    int totalNQueens(int n) {

        col.assign(n,0);
        diag1.assign(2*n,0);
        diag2.assign(2*n,0);

        solve(0,n);

        return ans;
    }
};