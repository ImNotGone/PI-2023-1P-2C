#include <stdio.h>
#include <assert.h>
#define M 6

void bordes(int mat[][M], int vec[]);

int main() {
    int mat_input[][6] = {
        {1, 1, 1, 1, 1, 1},
        {1, 2, 2, 2, 2, 1},
        {1, 2, 3, 3, 2, 1},
        {1, 2, 3, 3, 2, 1},
        {1, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1}
    };
    int vec[M/2];

    bordes(mat_input, vec);

    assert(vec[0] == 20);
    assert(vec[1] == 24);
    assert(vec[2] == 12);

    int mat_input_2[][6] = {
        {1, 1, 1, 1, 1, 1},
        {1, -2, 2, -2, 2, 1},
        {1, 4, 1, 2, -4, 1},
        {1, 0, 1, 2, 0, 1},
        {1, -2, -2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1}
    };

    bordes(mat_input_2, vec);

    assert(vec[0] == 20);
    assert(vec[1] == 0);
    assert(vec[2] == 6);

    int mat_input_3[][6] = {
        {1, 1, 1, 1, 1, 1},
        {1, -2, 2, -2, 2, 1},
        {1, 4, 1, 2, -4, 1},
        {1, 0, 3, 3, 0, 1},
        {1, -2, -2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1}
    };
    bordes(mat_input_3, vec);

    assert(vec[0] == 20);
    assert(vec[1] == 0);
    assert(vec[2] == 9);

    puts("OK!");

    return 0;
}

int sum_fil(int fil[], int start, int end) {
    int sum = 0;
    for(int i = start; i < end; i++) {
        sum += fil[i];
    }
    return sum;
}

int sum_row(int mat[][M], int col, int start, int end) {
    int sum = 0;
    for(int i = start; i < end; i++) {
        sum += mat[i][col];
    }
    return sum;
}

void bordes(int mat[][M], int vec[]) {
    for (int i = 0; i < (M/2); i++) {
        vec[i] = 0;
        vec[i] += sum_fil(mat[i], i, M - i);
        vec[i] += sum_fil(mat[M-i-1], i, M - i);
        vec[i] += sum_row(mat, i, i+1, M-1-i);
        vec[i] += sum_row(mat, M-i-1, i+1, M-1-i);
    }
    return;
}
