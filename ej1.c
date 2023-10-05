#include <assert.h>
#include <stdio.h>
#define COLS 6
#define FALSE 0
#define TRUE !FALSE

int elimina(char mat[][COLS], int rows);

int main() {
    char mat_input[][6] = {
        {'L', '#', 'B', 'B', '#', 'L'},
        {'3', '1', 'r', 'R', '1', '3'},
        {'3', '2', 'S', 'S', '2', '3'},
        {'R', 'L', 'A', 'H', 'N', 'N'},
        {'W', 'A', 'O', 'Y', 'U', 'T'},
        {'Q', 'S', 'G', 'S', 'M', 'A'}
    };
    int cant_rows = 6;

    char mat_expected[][6] = {
        {'3', '1', 'r', 'R', '1', '3'},
        {'R', 'L', 'A', 'H', 'N', 'N'},
        {'W', 'A', 'O', 'Y', 'U', 'T'},
        {'Q', 'S', 'G', 'S', 'M', 'A'}
    };

    int rows_expected = 4;

    assert(rows_expected = elimina(mat_input, cant_rows));

    for (int i = 0; i < rows_expected; i++) {
        for(int j = 0; j < COLS; j++) {
            assert(mat_expected[i][j] = mat_input[i][j]);
        }
    }

    puts("OK!");
    return 0;
}

int elimina(char mat[][COLS], int rows) {
    int rows_new = 0;
    for (int i = 0; i < rows; i++) {
        int delete = TRUE;
        for(int j = 0; j < COLS/2 && delete; j++) {
            delete = mat[i][j] == mat[i][COLS-j];
        }
        if(!delete) {
            for(int j = 0; j < COLS; j++) {
                mat[rows_new][j] = mat[i][j];
            }
            rows_new++;
        }
    }
    return rows_new;
}
