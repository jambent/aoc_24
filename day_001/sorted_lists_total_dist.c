#include <stdio.h>
#include <stdlib.h>

// Read test input text file using command line argument,
// e.g., ./day_001/sorted_lists_total_dist ./day_001/day_1_input.txt
int main (int argc, char *argv[]) {

    FILE *fp;
    int list_one_integer, list_two_integer;

    fp = fopen(argv[1], "r");

    if (argc != 2) {
        printf("%s not called with single filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (fp == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d %d", &list_one_integer, &list_two_integer);
    

    printf("First integer in file found: %d\n", list_one_integer);
    printf("Second integer in file found: %d\n", list_two_integer);

    fscanf(fp, "%d %d", &list_one_integer, &list_two_integer);
    

    printf("First integer in file found: %d\n", list_one_integer);
    printf("Second integer in file found: %d\n", list_two_integer);

    fclose(fp);
    

    return 0;
}