#include <stdio.h>
#include <stdlib.h>

#define FILENAME "./day_001/day_1_input.txt"


int main (void){

    FILE *fp;

    fp = fopen(FILENAME, "r");

    if (fp == NULL) {
        printf("Cannot open file %s\n", FILENAME);
        exit(EXIT_FAILURE);
    }

    printf("Test input can be opened successfully\n");

    fclose(fp);

    return 0;
}