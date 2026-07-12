bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int left = 0, right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int r = mid / cols;
        int c = mid % cols;

        if (matrix[r][c] == target)
            return true;
        else if (matrix[r][c] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}