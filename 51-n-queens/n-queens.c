/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char ***ans;
int count;
int n;

bool col[10];
bool diag1[20];
bool diag2[20];

void backtrack(int row, char **board) {

    if (row == n) {

        char **temp = (char **)malloc(n * sizeof(char *));

        for (int i = 0; i < n; i++) {
            temp[i] = (char *)malloc((n + 1) * sizeof(char));
            strcpy(temp[i], board[i]);
        }

        ans[count++] = temp;
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


        backtrack(row + 1, board);


        board[row][c] = '.';

        col[c] = false;
        diag1[row - c + n] = false;
        diag2[row + c] = false;
    }
}


char*** solveNQueens(int N, int* returnSize, int** returnColumnSizes) {

    n = N;
    count = 0;

    ans = (char ***)malloc(10000 * sizeof(char **));


    char **board = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        board[i] = (char *)malloc((n + 1) * sizeof(char));

        for (int j = 0; j < n; j++)
            board[i][j] = '.';

        board[i][n] = '\0';
    }


    backtrack(0, board);


    *returnSize = count;


    *returnColumnSizes = (int *)malloc(count * sizeof(int));

    for (int i = 0; i < count; i++)
        (*returnColumnSizes)[i] = n;


    return ans;
}