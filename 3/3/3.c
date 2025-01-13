#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[10][10]) {
    int i,j, k, l;
    char matrix_copy[10][10];

    for (i=0;i<10;i++) {
        for (j=0;j<10;j++) {
            matrix_copy[i][j] = matrix[i][j];
        }
    }

    l=0;
    for (i=0;i<10;i++) {

        k = 9;
        for (j=0;j<10;j++) {
            matrix[i][j] = matrix_copy[k-j][l];
        }
        l++;
    }
}
