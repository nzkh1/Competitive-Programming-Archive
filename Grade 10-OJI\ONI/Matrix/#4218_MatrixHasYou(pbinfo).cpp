void Matrix(int a[300][300], int n, int L[], int C[], int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < k; i++) {
        int current_row = L[i];
        for (int j = 0; j < n; j++) {
            a[current_row][j] = 1 - a[current_row][j];
        }
        int current_col = C[i];
        for (int j = 0; j < n; j++) {
            a[j][current_col] = 1 - a[j][current_col];
        }
    }
}
//This function handles matrix toggling based on row/column indices.Note: Designed to be called by the PbInfo internal grader.
