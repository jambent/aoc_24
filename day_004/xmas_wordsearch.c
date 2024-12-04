#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {

    FILE *fp;
    char *line_001, *line_002, *line_003, *line_004;
    int line_count = 0, line_num = 0, xmas_count = 0;
    char end_of_file_check;

    fp = fopen(argv[1], "r");


    
    if (argc != 2) {
        printf("%s not called with single filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }



    if (fp == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((end_of_file_check = getc(fp))!= EOF) {
        if (end_of_file_check == '\n') {
            line_count++;
        }
    }

    rewind(fp);


    while(fgets(line_001, 256, fp) != NULL) {
        line_num += 1;
        while(fgets(line_002, 256, fp) != NULL) {
            while(fgets(line_003, 256, fp) != NULL) {
                while(fgets(line_004, 256, fp) != NULL) {

                }
            }
        }
        printf("Number of XMAS occurrences: %d\n", xmas_count);
    }



}