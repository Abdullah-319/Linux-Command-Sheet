#include <bits/stdc++.h>
#include <sys/wait.h>

using namespace std;


// calculate the sum of every row
int get_row_sum(int matrix[3][3], int size, int row) {
    int sum = 0;
    for (int j = 0; j < size; ++j) {
        sum += matrix[row][j];
    }
    return sum;
}

// calculate the sum of every column
int get_column_sum(int matrix[3][3], int size, int col) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += matrix[i][col];
    }
    return sum;
}

// calculate the sum of main and trailing diagonal
int get_diagonal_sum(int matrix[3][3], int size, bool main_diagonal) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (main_diagonal)
            sum += matrix[i][i];
        else
            sum += matrix[i][size - 1 - i];
    }
    return sum;
}

// check if the square matrix is a magic square or not
bool is_magic(int matrix[3][3], int size) {
    int pipe_row[2];
    int pipe_col[2];

    if (pipe(pipe_row) == -1 || pipe(pipe_col) == -1) {
        cerr << "pipe can't be created" << endl;
        return false;
    }

    pid_t pid_row, pid_col;

    pid_row = fork();

    // fork child to check row sum  
    if (pid_row == 0) {
        int row_sum = get_row_sum(matrix, size, 0);
        for (int i = 1; i < size; ++i) {
            if (row_sum != get_row_sum(matrix, size, i)) {
                close(pipe_row[0]);
                write(pipe_row[1], "-1", sizeof("-1"));
                close(pipe_row[1]);
                return false;
            }
        }
        close(pipe_row[0]);
        write(pipe_row[1], &row_sum, sizeof(row_sum));
        close(pipe_row[1]);
        return false;
    }

    pid_col = fork();

    // fork child to check column sum  
    if (pid_col == 0) { 
        int col_sum = get_column_sum(matrix, size, 0);
        for (int j = 1; j < size; ++j) {
            if (col_sum != get_column_sum(matrix, size, j)) {
                close(pipe_col[0]);
                write(pipe_col[1], "-1", sizeof("-1"));
                close(pipe_col[1]);
                return false;
            }
        }
        close(pipe_col[0]);
        write(pipe_col[1], &col_sum, sizeof(col_sum));
        close(pipe_col[1]);
        return false;
    }

    // parent process
    close(pipe_row[1]);
    close(pipe_col[1]);

    int row_sum, col_sum;
    read(pipe_row[0], &row_sum, sizeof(row_sum));
    read(pipe_col[0], &col_sum, sizeof(col_sum));

    close(pipe_row[0]);
    close(pipe_col[0]);

    if (row_sum == -1 || col_sum == -1) {
        cout << "Input square is not a magic square." << endl;
        return false;
    }

    int main_diagonal_sum = get_diagonal_sum(matrix, size, true);
    int trailing_diagonal_sum = get_diagonal_sum(matrix, size, false);

    if (row_sum == col_sum && row_sum == main_diagonal_sum && row_sum == trailing_diagonal_sum) {
        cout << "Input square is a magic square." << endl;
        return true;
    } else {
        cout << "Input square is not a magic square." << endl;
        return false;
    }
}


int main() {
    int size = 3;
    cout << "Let's take a square matrix of size 3x3." << endl;

    int matrix[3][3];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout<< "Enter the element at [" << i+1 << "][" << j+1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    is_magic(matrix, size);

    return 0;
}