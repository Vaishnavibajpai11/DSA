int count;
int n;
int cols[10], diag1[20], diag2[20];

void backtrack(int row) {

    if(row == n) {
        count++;
        return;
    }

    for(int col = 0; col < n; col++) {

        if(cols[col] || 
           diag1[row-col+n] || 
           diag2[row+col])
            continue;

        cols[col] = 1;
        diag1[row-col+n] = 1;
        diag2[row+col] = 1;

        backtrack(row+1);

        cols[col] = 0;
        diag1[row-col+n] = 0;
        diag2[row+col] = 0;
    }
}

int totalNQueens(int N) {

    n = N;
    count = 0;

    backtrack(0);

    return count;
}