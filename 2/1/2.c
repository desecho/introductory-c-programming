int printTriangle(int size) {
    int starCount = 0;
    int i, j;

    for (i=0; i<size+1; i++) {
        for (j=0; j<i; j++) {
            printf("*");
            starCount++;
        }
        printf("\n");
    }

    return starCount;
}


int main(void) {
  int numStars;
  printf("Here is a triangle with height 4\n");
  numStars = printTriangle(4);
  printf("That triangle had %d total stars\n", numStars);

  printf("Here is a triangle with height 7\n");
  numStars = printTriangle(7);
  printf("That triangle had %d total stars\n", numStars);

  return 0;
}
