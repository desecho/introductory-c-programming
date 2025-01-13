#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t maxSeq(int * array, size_t n) {
    int i,x, y;
    int val1;
    int val2;
    x = 1;
    y = 0;

    if (n == 0) {
        return 0;
    }
    if (n== 1) {
        return 1;
    }

    for (i=0; i < n-1; i++) {
        val1 = array[i];
        val2 = array[i+1];
        if (val2 > val1) {
            x++;
        } else {
            if (x > y) {
                y = x;
            }
            x = 1;
        }
    }

    if (x>y) {
        y=x;
    }
    return y;
}
