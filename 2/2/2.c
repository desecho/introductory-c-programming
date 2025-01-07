#include <stdio.h>
#include <stdlib.h>


/*
 * Determines if coord is in range between
 * offset (INCLUSIVE) and offset + size (EXCLUSIVE)
 */
int isInRange(int coord, int offset, int size) {
  return coord >= offset && coord < offset + size;
}

/*
 * Determines if coord is at border of offset or
 * offset + size
 */
int isAtBorder(int coord, int offset, int size) {
  return coord == offset || coord == offset + size;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }

    return b;
}

void squares(int size1, int x_offset, int y_offset, int size2) {
  int w, h, y, x;
  w = max(size1, x_offset + size2);
  h = max(size1, y_offset + size2);

  for (y=0; y<h; y++) {
    for (x=0; x<w; x++) {
        if (
            ((x >= x_offset && x < x_offset + size2) && (y == y_offset || y == y_offset + size2 -1)) ||
            ((y >= y_offset && y < y_offset + size2) && (x == x_offset || x == x_offset + size2 - 1))
        ) {
            printf("*");
        } else if (
            ((x < size1) && (y == 0 || y == size1-1)) || ((y < size1) && (x == 0 || x == size1 - 1))
        ) {
            printf("#");
        } else {
            printf(" ");
        }
    }
    printf("\n");
  }
}
