#include <stdio.h>

#define N 4

int input_matrix[N][N] = {
    { 2, -3, 3, 2 },
    { 6, 9, -2, -1 },
    { 10, 3, -3, -2 },
    { 8, 6, 1, 3 }
};

int output_matrix[N - 1][N - 1];

void delete_line_and_column(int line, int column)
{
    int x = 0;
    for (int i = 0; i < N; ++i) {
        int y = 0;
        if (i != line) {
            for (int j = 0; j < N; ++j) {
                if (j != column) {
                    output_matrix[x][y] = input_matrix[i][j];
                    ++y;
                }
            }
            ++x;
        }
    }
}

int main(void)
{
    delete_line_and_column(1, 1);
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            printf("matrix[%d][%d] = %d\n", i, j, output_matrix[i][j]);
        }
    }

    return 0;
}